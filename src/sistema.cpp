#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "usuario.h"

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {

  if(this->verifyEmail(email)) return "Usuário já existe!";
  

  int id = this->usuarios.size();
  this->usuarios.push_back(Usuario(id, nome, email, senha));
  return "Criando usuário " + nome + " (" + email + ")\nUsuário criado";
}

string Sistema::login(const string email, const string senha) {
  
    for(Usuario user : this->usuarios)
    {
      if(user.email == email && user.senha == senha)
      {
        this->usuariosLogados.insert(std::pair<int, std::pair<std::string, std::string>>(user.id ,std::pair<std::string, std::string>("", "")));
        return "Logado como " + email;
      }
    }

  return "Senha ou usuário inválidos!";
}

string Sistema::disconnect(int id) {

  std::map<int,std::pair<std::string, std::string>>::iterator it;
  it = this->usuariosLogados.find(id);
  if(this->verifyUserStatus(id)){
    std::string userEmail = this->getUserEmailById(id);
    this->usuariosLogados.erase(it);
    return "Desconectando usuário " + userEmail;
  }

  return "Falha ao desconectar o usuário: id inválido";
}

string Sistema::create_server(int id, const string nome) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  
  for(Servidor server : this->servidores)
  {
    if(server.verifyName(nome)) return "Este servidor já existe";
  }

  this->servidores.push_back(Servidor(id, nome, "", ""));
  return "Servidor criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";

  for(auto it = this->servidores.begin(); it != this->servidores.end(); it++)
  {
    if(it->verifyName(nome)){
      if(!it->verifyDonoId(id)) return "Você não possui permissão para fazer isso.";
      it->setDescricao(descricao);
      return "Descrição do servidor '" + nome + "' modificada!";
    }
  }

  return "Servidor '" + nome + "' não existe";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  
  for(auto it = this->servidores.begin(); it != this->servidores.end(); it++)
  {
    if(it->verifyName(nome)){
      if(!it->verifyDonoId(id)) return "Você não possui permissão para fazer isso.";
      it->setCodigoConvite(codigo);
      return codigo == "" 
        ? "Código de convite do servidor "+ nome + " removido!"
        : "Código de convite do servidor "+ nome + " modificado!"; 
    }
  }
  return "Servidor '" + nome + "' não existe";
}

string Sistema::list_servers(int id) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  std::string result;
  int counter = 0;

  for(Servidor server : this->servidores)
  {
    counter == this->servidores.size() - 1 ? result += server.getNome() : result += server.getNome() + "\n";
    
    counter++;
  }

  return  result;
}

string Sistema::remove_server(int id, const string nome) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  vector<Servidor>::iterator it;

  for(it = this->servidores.begin(); it != this->servidores.end(); it++)
  {
    if(it->getNome() == nome)
    {
      if(!it->verifyDonoId(id)) return "Você não é o dono do servidor '"+ nome +"'";
      for(map<int, std::pair<std::string, std::string>>::iterator it = this->usuariosLogados.begin(); it != this->usuariosLogados.end(); it++)
      {
        if(nome == it->second.first){
          it->second.first = "";
          it->second.second = "";
        }
      }
      this->servidores.erase(it);
      return "Servidor '"+ nome +"' removido";
    }
  }

  return "Servidor '" + nome + "' não encontrado";
}

/*
A2.7 0,6
- se o comando for chamado duas vezes pelo mesmo usuário, ficam duas cópias do mesmo usuário no servidor. -20%
- quando o dono do servidor tenta entrar nele, não deve ser necessária senha! -20%
*/
string Sistema::enter_server(int id, const string nome, const string codigo) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";

  for(auto it = this->servidores.begin(); it != this->servidores.end(); it++)
  {
    if(it->getNome() == nome)
    {
      if(!it->verifyDonoId(id)) "Você não é o dono do servidor '"+ nome +"'";

      if (it->verifyCodigo(codigo) || it->itsOpen())
      {
        auto itUserLogado = this->usuariosLogados.find(id);
        itUserLogado->second.first = nome;
        it->addUser(id);
        return "Entrou no servidor com sucesso";
      }
      return "Servidor requer código de convite"; 
    }
  }

  return "Servidor '" + nome + "' não encontrado";
}

/*
A2.8 ok
*/
string Sistema::leave_server(int id, const string nome) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";

  for(auto it = this->servidores.begin(); it != this->servidores.end(); it++)
  {
    if(it->getNome() == nome)
    {
      if(it->userExists(id)){
        it->deleteUser(id);
        (this->usuariosLogados.find(id))->second.first = "";
        return "Saindo do servidor '" + nome + "'";
      }

      return "Você não está no servidor '" + nome + "'";
    }
  }

  return "Servidor '" + nome + "' não encontrado";
}

/*
A2.9 ok
*/
string Sistema::list_participants(int id) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";

  std::string serverName = this->usuariosLogados.find(id)->second.first;
  if(serverName == "") return "Usuário não está conectado a nenhum servidor";

  std::string participantes;
  for(auto itServer = this->servidores.begin(); itServer != this->servidores.end(); itServer++)
  {
    if(itServer->getNome() == serverName){
      if(!itServer->userExists(id)) return "O usuário não está em nenhum servidor";
      std::vector<int> ids = StringHelper::splitLine(itServer->listAll(), " ");
      std::string list;
      int counter = 0;
      for(auto uId = ids.begin(); uId != ids.end(); uId++){
        if(uId != ids.end() - 1) list += this->getUserNamebyId(*uId) + "\n";
        else{
          list += this->getUserNamebyId(*uId);
        }
        counter++;
      }

      return list;
    }
  }

  return "O usuário não está em nenhum servidor";
}

/*
B1.1 ok
*/
string Sistema::list_channels(int id) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  for(auto itServer = this->servidores.begin(); itServer != this->servidores.end(); itServer++)
  {
    if(itServer->userExists(id)) {
      return itServer->listChannels();
    }
  }
  return "O usuário não está em nenhum servidor";
}

/*
B1.2 ok
*/
string Sistema::create_channel(int id, const string nome) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  for(auto itServer = this->servidores.begin(); itServer != this->servidores.end(); itServer++)
  {
    if(itServer->userExists(id)) {
      if(itServer->channelExists(nome)) return "Canal de texto '" + nome + "' já existe!";
      itServer->addChannel(nome);
      this->usuariosLogados.find(id)->second.second = nome;
      return "Canal de texto '"+ nome + " 'criado";
    }
  }

  return "O usuário não está em nenhum servidor";
}

/*
B1.3 ok
*/
string Sistema::enter_channel(int id, const string nome) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  for(auto itServer = this->servidores.begin(); itServer != this->servidores.end(); itServer++)
  {
    if(itServer->userExists(id)) {
      if(!itServer->channelExists(nome)) return "Canal '" + nome + "' não existe";
      this->usuariosLogados.find(id)->second.second = nome;
      return "Entrou no canal '" + nome + "'";
    }
  }
  return "O usuário não está em nenhum servidor";
}

/*
B1.4 ok
*/
string Sistema::leave_channel(int id) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  for(auto itServer = this->servidores.begin(); itServer != this->servidores.end(); itServer++)
  {
    if(itServer->userExists(id)) {
      if(this->usuariosLogados.find(id)->second.second == "") return "Usuário não esta vizualidando nenhum canal";
      this->usuariosLogados.find(id)->second.second = "";
      return "Saindo do canal";
    }
  }
  return "O usuário não está em nenhum servidor";
}

/*
B2.1 ok
*/
string Sistema::send_message(int id, const string mensagem) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  for(auto itServer = this->servidores.begin(); itServer != this->servidores.end(); itServer++)
  {
    if(itServer->userExists(id)) {
      if(this->usuariosLogados.find(id)->second.second == "") return "Usuário não esta vizualidando nenhum canal";
      itServer->sendMessage(this->usuariosLogados.find(id)->second.second, id, mensagem);
      return "";
    }
  }
  return "O usuário não está em nenhum servidor";
}

/*
B2.2 ok
*/
string Sistema::list_messages(int id) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  for(auto itServer = this->servidores.begin(); itServer != this->servidores.end(); itServer++)
  {
    if(itServer->userExists(id)) {
      if(this->usuariosLogados.find(id)->second.second == "") return "Usuário não esta vizualidando nenhum canal";
      std::string list = itServer->getMessages(this->usuariosLogados.find(id)->second.second, this->usuarios);
      if(list.length() == 0) return "Sem mensagens para exibir";
      return list;
    }
  }
  return "O usuário não está em nenhum servidor";
}


/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */

bool Sistema::verifyUserStatus(int id)
{
  std::map<int,std::pair<std::string, std::string>>::iterator it;
  it = this->usuariosLogados.find(id);

  return it != this->usuariosLogados.end();
}

bool Sistema::verifyEmail(std::string email)
{
  for(Usuario user : this->usuarios)
  {
    if(user.email == email) return true;
  }

  return false;
}

std::string Sistema::getUserEmailById(int id)
{
  std::string email;
  for(Usuario user : this->usuarios)
  {
    if(user.id == id) email = user.email;
  }

  return email;
}

std::string Sistema::getUserNamebyId(int id)
{
  std::string name;

  for(Usuario user : this->usuarios)
  {
    if(user.id == id) name = user.nome;
  }

  return name;
}

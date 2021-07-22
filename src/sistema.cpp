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
      this->usuariosLogados.insert(std::pair<int, std::pair<std::string, std::string>>(this->usuariosLogados.size() ,std::pair<std::string, std::string>(user.nome, user.email)));
      return "Logado como " + email;
    }

  return "Senha ou usuário inválidos!";
}

string Sistema::disconnect(int id) {

  std::map<int,std::pair<std::string, std::string>>::iterator it;
  it = this->usuariosLogados.find(id);
  if(this->verifyUserStatus(id)){
    this->usuariosLogados.erase(it);
    return "Desconectando usuário " + it->second.second;
  }

  return "Falha ao desconectar o usuário: id inválido";
}

string Sistema::create_server(int id, const string nome) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  
  for(Servidor server : this->servidores)
  {
    if(server.verifyName(nome)) return "Este servidor já existe";
  }

  this->servidores.push_back(Servidor(id, nome));
  return "Servidor criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";

  for(Servidor server : this->servidores)
  {
    if(server.verifyName(nome)){
      if(!server.verifyDonoId(id)) return "Você não possui permissão para fazer isso.";
      server.setDescricao(descricao);
      return "Descrição do servidor ‘" + nome + "’ modificada!";
    }
  }

  return "Servidor ‘" + nome + "’ não existe";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  if(!this->verifyUserStatus(id)) return "Usuário não conectado!";
  for(Servidor server : this->servidores)
  {
    if(server.verifyName(nome)){
      if(!server.verifyDonoId(id)) return "Você não possui permissão para fazer isso.";
     if(codigo != ""){
       server.setCodigoConvite(codigo);
       return "Código de convite do servidor ‘" + nome + "’ modificado!";
     }
      server.setCodigoConvite("");
      return "Código de convite do servidor ‘" + nome + "’ removido!";
    }
  }

  return "Servidor ‘" + nome + "’ não existe";
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
  return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
  return "list_messages NÃO IMPLEMENTADO";
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


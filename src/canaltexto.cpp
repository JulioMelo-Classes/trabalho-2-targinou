#include "canaltexto.h"

CanalTexto::CanalTexto(std::string nome)
{
    this->nome = nome;
}

std::string CanalTexto::getNome()
{
    return this->nome;
}

void CanalTexto::sendMessage(int id, std::string conteudo)
{
    this->mensagens.push_back(Mensagem(id, conteudo));
}

std::string CanalTexto::listMessages(std::vector<Usuario> usuarios)
{
    std::string list;

    for(auto it = this->mensagens.begin(); it != this->mensagens.end(); it++)
    {
        for(auto user = usuarios.begin(); user != usuarios.end(); user++){
            if(user->id == it->getEnviadaPor()){
                if(it != this->mensagens.end() - 1){
                    list += user->nome + it->getDataHora() + ": " + it->getConteudo() + "\n";
                }else{
                    list += user->nome + it->getDataHora() + ": " + it->getConteudo();
                }
            }
        }
    }

    return list;
}
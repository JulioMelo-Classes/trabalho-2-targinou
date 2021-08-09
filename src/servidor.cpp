#include "servidor.h"
#include <iostream>


Servidor::Servidor(int usuarioDonoId, std::string nome, std::string codigoConvite, std::string descricao)
{
    this->usuarioDonoId = usuarioDonoId;
    this->nome = nome;
    this->codigoConvite = codigoConvite;
    this->descricao = descricao;
}

void Servidor::setDescricao(std::string descricao)
{
    this->descricao = descricao;    
}

void Servidor::setCodigoConvite(std::string cod)
{
    this->codigoConvite = cod;
}

std::string Servidor::getNome()
{
    return this->nome;
}

bool Servidor::verifyName(std::string name)
{
    return name == this->nome;
}

bool Servidor::verifyDonoId(int id)
{
    return this->usuarioDonoId == id;
}

bool Servidor::itsOpen()
{
    return this->codigoConvite == "";
}

bool Servidor::verifyCodigo(std::string codigo)
{
    return this->codigoConvite == codigo;
}

void Servidor::addUser(int id)
{
    this->participantesId.push_back(id);
}

bool Servidor::userExists(int id)
{
    for(auto it = this->participantesId.begin(); it != this->participantesId.end(); it++)
    {
        if(*it == id) return true;
    }

    return false;
}

void Servidor::deleteUser(int id)
{
    vector<int>::iterator eraseIt;
    for(auto it = this->participantesId.begin(); it != this->participantesId.end(); it++)
    {
        if(*it == id) {
            eraseIt = it;
        }
    }

    this->participantesId.erase(eraseIt);
}

std::string Servidor::listAll()
{   
    std::string list;
    for(auto it = this->participantesId.begin(); it != this->participantesId.end(); it++)
    {
        list += to_string(*it) + " ";
    }

    return list;
}

std::string Servidor::listChannels()
{
    std::string list = "#canais de texto\n";
    for(auto it = this->canaisTexto.begin(); it != this->canaisTexto.end(); it++)
    {
        if(it != this->canaisTexto.end() - 1){
            list += it->getNome() + "\n";
        }else{
            list += it->getNome();
        }
    }

    return list;
}

bool Servidor::channelExists(std::string channelName)
{
    for(auto it = this->canaisTexto.begin(); it != this->canaisTexto.end(); it++)
    {
        if(it->getNome() == channelName) return true;
    }

    return false;
}

void Servidor::addChannel(std::string nome)
{
    this->canaisTexto.push_back(CanalTexto(nome));
}

void Servidor::sendMessage(std::string channel, int id, std::string conteudo)
{
    for(auto it = this->canaisTexto.begin(); it != this->canaisTexto.end(); it++)
    {
        if(it->getNome() == channel){
            it->sendMessage(id, conteudo);
        }
    }
}

std::string Servidor::getMessages(std::string channelName, std::vector<Usuario> users)
{
    std::string list;
    for(auto it = this->canaisTexto.begin(); it != this->canaisTexto.end(); it++)
    {
        if(it->getNome() == channelName){
            list = it->listMessages(users);
        }
    }

    return list;
}
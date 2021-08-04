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

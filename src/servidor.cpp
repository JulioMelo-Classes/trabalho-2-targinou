#include "servidor.h"

Servidor::Servidor(int usuarioDonoId, std::string nome)
{
    this->usuarioDonoId = usuarioDonoId;
    this->nome = nome;
}

void Servidor::setDescricao(std::string descricao)
{
    this->descricao = descricao;
}

void Servidor::setCodigoConvite(std::string codigoConvite)
{
    this->codigoConvite = codigoConvite;
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

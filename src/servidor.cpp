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

bool Servidor::verifyName(std::string name)
{
    return name == this->nome;
}

bool Servidor::verifyDonoId(int id)
{
    return this->usuarioDonoId == id;
}

#include "usuario.h"

Usuario::Usuario(int id, std::string nome, std::string email, std::string senha)
{
    this->id = id;
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}
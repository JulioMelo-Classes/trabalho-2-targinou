#include "mensagem.h"

std::string Mensagem::getDataHora()
{
    return this->dataHora;
}

void Mensagem::setDataHora(std::string dataHora)
{
    this->dataHora = dataHora;
}

int Mensagem::getEnviadaPor()
{
    return this->enviadaPor;
}

void Mensagem::setEnviadaPor(int enviadaPor)
{
    this->enviadaPor = enviadaPor;
}

std::string Mensagem::getConteudo()
{
    return this->conteudo;
}

void Mensagem::setConteudo(std::string conteudo)
{
    this->conteudo = conteudo;
}
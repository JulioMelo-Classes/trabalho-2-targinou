#include "mensagem.h" //estava com M

Mensagem::Mensagem(int id, std::string conteudo) {
    this->dataHora = this->setNow();
    this->enviadaPor = id;
    this->conteudo = conteudo;
}

int Mensagem::getEnviadaPor()
{
    return this->enviadaPor;
}

std::string Mensagem::getDataHora()
{
    return this->dataHora;
}

std::string Mensagem::getConteudo()
{
    return this->conteudo;
}

std::string Mensagem::setNow() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "<%d/%m/%Y - %X>", &tstruct);

    return buf;
}
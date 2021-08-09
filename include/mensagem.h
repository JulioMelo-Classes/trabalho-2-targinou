#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

class Mensagem
{
    private: 
        std::string dataHora;
        int enviadaPor;
        std::string conteudo;

    public:
        Mensagem(int id, std::string conteudo);
        std::string getDataHora();
        int getEnviadaPor();
        std::string getConteudo();
        std::string setNow();
};

#endif
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
        std::string getDataHora();
        void setDataHora(std::string dataHora);
        int getEnviadaPor();
        void setEnviadaPor(int enviadaPor);
        std::string getConteudo();
        void setConteudo(std::string conteudo);
};

#endif
#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

/*
Cp2 ok

Documentação 0.8
*/
class Mensagem
{
    private: 
        std::string dataHora;
        int enviadaPor;
        std::string conteudo;

    public:
        Mensagem(int id, std::string conteudo);
        
        /*! Metodo para pegar a data e a hora que a mensagem foi enviada.
				@return uma string com a data e a hora que a mensagem foi enviada.
		*/
        std::string getDataHora();

		/*! Metodo para pegar o id de quem enviou a mensagem.
				@return um valor inteiro que corresponde ao id do usuário que enviou a mensagem.
		*/
        int getEnviadaPor();
        
		/*! Metodo para pegar o conteudo da mensagem.
				@return uma string com o conteudo.
		*/
        std::string getConteudo();
        
		/*! Metodo para setar a hora que uma mensagem foi enviada em um canal de texto.
				@return uma string com a hora do envio.
		*/
        std::string setNow();
};

#endif
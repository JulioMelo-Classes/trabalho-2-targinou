#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <string>
#include <vector>
#include "mensagem.h"
#include "usuario.h"

/*
Cp2 ok

documentação: 0,8 faltaram os atributos
*/
class CanalTexto{
	private: 
		std::string nome;
		std::vector<Mensagem> mensagens;

	public: 
		CanalTexto(std::string nome);
		
		/*! Metodo para pegar o nome do canal de texto.
				@return uma string com o nome do canal de texto.
		*/
		std::string getNome();
		
		/*! Metodo para salvar as mensagens envviadas no canal de texto.
				@param id id do usuário.
				@param conteudo conteudo da mensagem.
				@return uma string com todas as mensagens.
		*/
		void sendMessage(int id, std::string conteudo);
		
		/*! Metodo para pegar todas as mensagens de um canal de texto.
				@param usuarios vetor de usuários
				@return uma string com todas as mensagens.
		*/
		std::string listMessages(std::vector<Usuario> usuarios);
};

#endif

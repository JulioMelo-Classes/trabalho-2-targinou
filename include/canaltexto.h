#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <string>
#include <vector>
#include "mensagem.h"
#include "usuario.h"

class CanalTexto{
	private: 
		std::string nome;
		std::vector<Mensagem> mensagens;

	public: 
		CanalTexto(std::string nome);
		std::string getNome();
		void sendMessage(int id, std::string conteudo);
		std::string listMessages(std::vector<Usuario> usuarios);
};

#endif

#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <vector>
#include "canaltexto.h"
#include "usuario.h"

using namespace std;

class Servidor{
	private:
		int usuarioDonoId;
		std::string nome;
		std::string descricao;
		std::string codigoConvite;
		std::vector<CanalTexto> canaisTexto;
		std::vector<int> participantesId;

	public:
		Servidor(int usuarioDonoId, std::string nome, std::string codigoConvite, std::string descricao);
		bool verifyName(std::string name);
		bool verifyDonoId(int id);
		std::string getNome();
		void setDescricao(std::string descricao);
		void setCodigoConvite(std::string cod);
		bool itsOpen();
		bool verifyCodigo(std::string codigo);
		void addUser(int id);
		bool userExists(int id);
		void deleteUser(int id);
		std::string listAll();
		std::string listChannels();
		bool channelExists(std::string channelName);
		void addChannel(std::string nome);
		void sendMessage(std::string channel, int id, std::string conteudo);
		std::string getMessages(std::string channelName, std::vector<Usuario> users);
};	

#endif

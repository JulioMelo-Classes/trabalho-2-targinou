#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <vector>
#include "canaltexto.h"

class Servidor{
	private:
		int usuarioDonoId;
		std::string nome;
		std::string descricao;
		std::string codigoConvite;
		std::vector<CanalTexto> canaisTexto;
		std::vector<int> participantesId;

	public:
		Servidor(int usuarioDonoId, std::string nome);
		bool verifyName(std::string name);
		bool verifyDonoId(int id);
		void setDescricao(std::string descricao);
};	

#endif

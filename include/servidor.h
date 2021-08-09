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
		/*! Verifica a existencia de um servidor com base no nome.
				@param nome do servidor.
				@return retorna verdadeiro caso exista um servidor com esse nome e falso caso contrário.
		*/
		bool verifyName(std::string name);

		/*! Verifica se o id informado é o do dono do servidor
				@param id o id do usuário informado no comando 
				@return retorna verdadeiro caso o id seja o dono e falso caso contrário.
		*/
		bool verifyDonoId(int id);

		/*! Metodo getter para receber o nome do servidor 
				@return uma string contendo o nome do servidor.
		*/
		std::string getNome();

		/*! Atualiza a descrição do servidor
				@param descricao a descrição a ser atribuido ao servidor 
				@return void.
		*/
		void setDescricao(std::string descricao);
		
		/*! Metodo para settar o codigo de convite do servidor
				@param uma string que vai ser o novo codigo do servidor 
				@return void
		*/
		void setCodigoConvite(std::string cod);

		/*! Verifica se o servidor está aberto.
				@return retorna verdadeiro caso o servidor esteja sem codigo de convite e falso caso contrário.
		*/
		bool itsOpen();

		/*! Verifica se o código do servidor está correto
				@param codigo código para entrar no servidor 
				@return retorna verdadeiro caso o código informado esteja correto e falso caso contrário.
		*/
		bool verifyCodigo(std::string codigo);

		/*! Metodo para adicionar o id do usuário ao vetor de participantes
				@param id do usuário
				@return void
		*/
		void addUser(int id);
		
		/*! Metodo para adicionar o id do usuário ao vetor de participantes
				@param id do usuário
				@return retorna verdadeiro caso usuário ja exista no servidor ou falso caso contrario.
		*/
		bool userExists(int id);

		/*! Metodo para deletar o id do usuário do vetor de participantes
				@param id do usuário
				@return void
		*/
		void deleteUser(int id);

		/*! Metodo para listar todo os usuários do servidor
				@return retorna uma string contendo os nomes dos usuários
		*/
		std::string listAll();

		/*! Metodo para listar todos os canais do servidor.
				@return uma string contendo os nomes dos canais.
		*/
		std::string listChannels();

		/*! Metodo para verificar a existencia de um canal.
				@param nome do canal.
				@return retorna verdadeiro caso o canal exista e falso caso contrário. 
		*/
		bool channelExists(std::string channelName);
		
		/*! Metodo para adicionar o canal no servidor
				@param nome nome do canal
				@return void
		*/
		void addChannel(std::string nome);
		
		/*! Metodo para salvar a mensagem enviada no canal
				@param nome nome do canal
				@return void
		*/
		void sendMessage(std::string channel, int id, std::string conteudo);

		/*! Metodo para pegar todas as mensagens de um canal de texto.
				@param nome nome do canal.
				@param array de usuários.
				@return uma string com todas as mensagens.
		*/
		std::string getMessages(std::string channelName, std::vector<Usuario> users);
};	

#endif

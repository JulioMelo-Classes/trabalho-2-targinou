#ifndef USUARIO_H
#define USUARIO_H

#include <string>

/*
CP1 classe usuário ok!
*/
class Usuario{
	public:
		int id;
		std::string nome;
		std::string email;
		std::string senha;
	public: 
		Usuario(int id, std::string nome, std::string email, std::string senha);
};

#endif

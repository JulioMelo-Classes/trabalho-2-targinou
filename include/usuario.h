#ifndef USUARIO_H
#define USUARIO_H

class Usuario{
	public:
		int id;
		std::string nome;
		std::string email;
		std::string senha;
	public:
		Usuario c_create(int id, std::string nome, std::string email, std::string senha);
		Usuario c_read(int id);
		Usuario c_update();
		bool c_delete();
};

#endif

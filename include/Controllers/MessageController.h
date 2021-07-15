#ifndef MESSAGECONTROLLER_H
#define MESSAGECONTROLLER_H

#include <string>
#include <ctime>
#include <chrono>
#include "Mensagem.h"

class MessageController{
    public: 
        Mensagem c_create(int idUsuario, std::string conteudo);
};

#endif
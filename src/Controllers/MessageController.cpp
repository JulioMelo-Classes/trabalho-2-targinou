#include "Mensagem.h"
#include "MessageController.h"

Mensagem MessageController::c_create(int idUsuario, std::string conteudo)
{
    Mensagem novaMensagem;

    novaMensagem.setEnviadaPor(idUsuario);
    novaMensagem.setDataHora("fodase123");
    novaMensagem.setConteudo(conteudo);

    return novaMensagem;
}
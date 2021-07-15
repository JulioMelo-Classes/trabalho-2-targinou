#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "sistema.h"
#include "executor.h"
#include "Mensagem.h"
#include "MessageController.h"

using namespace std;

int main() {
  // inicialização do sistema
  //Sistema sistema;
  //Executor executor(sistema);

  // o executor recebe o cin e o cout. Ele os utilizará para ler as linhas
  // de comando, executar o método correto em "sistema" e exibir as mensagens
  //executor.iniciar(cin, cout);

  MessageController controller;
  Mensagem teste = controller.c_create(1, "Fodase");

  cout << teste.getEnviadaPor() << " " << teste.getDataHora() << teste.getConteudo() << std::endl;

  return 0;
}

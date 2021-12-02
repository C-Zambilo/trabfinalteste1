
#include "header.h"
#include "funcoes.cpp";
int main() {
	setlocale(LC_ALL, "portuguese");
	int opcao = 0;
	
		std::cout << "=========================================\n";
		std::cout << "          .Trabalho final C++. \n";
		std::cout << "=========================================\n";
	while (opcao != 4) {

		std::cout << "Escolha uma das opções abaixo: \n";
		std::cout << "=========================================\n";
		std::cout << "1) Para cadastrar novo aluno. \n"
		std::cout << "2) Para cadastrar notas de um aluno.\n";
		std::cout << "3) Para solicitar lista de alunos.\n";
		std::cout << "4) Para finalizar a aplicacao. \n";
		std::cin >> opcao;

		system("cls");

		switch (opcao) {
		case 1:
			cadastro();
		break;
		case 2:
			cadastrar_notas();
		break;
		case 3:
			lista();
		break;
		}
	}
}

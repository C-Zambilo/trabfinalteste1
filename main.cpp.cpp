
#include "header.h"
#include "funcoes.cpp";
int main() {
	setlocale(LC_ALL, "portuguese");
	int opcao = 0;
	while (opcao != 4) {

		std::cout << "Escolha uma das opções abaixo: \n" << std::endl;
		Std::cout << "=========================================\n"
		std::cout << "1) Para cadastrar novo aluno." << std::endl;
		std::cout << "2) Para cadastrar notas de um aluno." << std::endl;
		std::cout << "3) Para solicitar lista de alunos." << std::endl;
		std::cout << "4) Para finalizar o programa." << std::endl;
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
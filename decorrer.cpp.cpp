#include "header.h"

bool cadastraAluno (Aluno aluno) {
	std::ofstream arquivo;
	arquivo.open("database.csv", std::fstream::app);

	if (!arquivo.is_open()) {
		std::cout << "Erro ao abrir o arquivo, tente novamente!\n";
		return false;
	}

	arquivo << aluno.nome << ";"
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << ";"
			<< aluno.sub << ";"
			<< aluno.media << ";"
			<< aluno.status << ";\n";

	arquivo.close();
	return true;
}


void cadastro () {
	Aluno alunoCadastro;
	std::cout << "Insira o nome do aluno: ";
	std::cin >> alunoCadastro.nome;
	std::cout << "Insira o numero da matricula: ";
	std::cin >> alunoCadastro.matricula;
	alunoCadastro.aep1 = 0;
	alunoCadastro.prova1 = 0;
	alunoCadastro.aep2 = 0;
	alunoCadastro.prova2 = 0;
	alunoCadastro.media = 0;
	alunoCadastro.sub = 0;
	alunoCadastro.status = "reprovado";

	if (cadastraAluno (alunoCadastro)) {
		std::cout << "O Aluno foi cadastrado.\n";
	} else {
		std::cout << "Erro ao cadastrar o aluno.\n";
	}
}

void lista(){

	int rodar_arquivo = 0;
	int b = 0;
	char delimitador = ';';
	std::string str;
	std::ifstream arquivo;
	std::ofstream arquivo_new_geral;
	std::ofstream arquivo_sub1;
	std::ofstream arquivo_sub2;
	std::ofstream arquivo_aprovados;
	std::ofstream arquivo_reprovados;
	int w =0;
	arquivo.open("database.csv", std::ios::in);
	
	if (!arquivo.is_open()) {
		std::cout << "Erro ao abrir o arquivo, tente novamente!\n";
	}
	else{
		while (arquivo.good()) {
			rodar_arquivo = arquivo.get();
			if (rodar_arquivo == '\n') {
				b++;
			}
		}
	}
	std::string line;
	std::string linha[b];
	int i = 0;
	arquivo.close();
	std::vector<struct Aluno> alunos(b);



	arquivo.open("database.csv", std::ios::in);
	do{
		arquivo >> linha[i];
		i++;
	}while(getline(arquivo, line));
	arquivo.close();



	for(int i = 0; i < b; i++){
		w = 0;
		std::stringstream X(linha[i]);
		while (getline(X, str, ';')){
			if(w == 0){
				alunos[i].nome = str;
			} else if(w == 1){
				alunos[i].matricula = str;
			} else if(w == 2){
				alunos[i].aep1 = std::stof(str);
			} else if(w == 3){
				alunos[i].prova1 = std::stof(str);
			} else if(w == 4){
				alunos[i].aep2 = std::stof(str);
			} else if(w == 5){
				alunos[i].prova2 = std::stof(str);
			} else if(w == 6){
				alunos[i].sub = std::stof(str);
			} else if(w == 7){
				alunos[i].media = std::stof(str);
			} else if(w == 8){
				alunos[i].status = str;
			}
			w++;
		}
	}
	

	int opcao_lista = 0;
	while (opcao_lista != 6){
		std::cout << "Escolha a opção desejada: " << std::endl
		          << "Para lista geral de alunos: 1" << std::endl
		          << "Para lista de alunos reprovados: 2" << std::endl
		          << "Para lista de alunos aprovados: 3" << std::endl
		          << "Para lista de alunos que precisam da substitutiva do primeiro bimestre: 4" << std::endl
		          << "Para lista de alunos que precisão da substitutiva do segundo bimestre: 5" << std::endl
				  << "Para voltar: 6" << std::endl;
		          std::cin >> opcao_lista;
		          system("cls");
    switch(opcao_lista){
      	case 1:
      	
      		system("cls");
            arquivo_new_geral.open("geral1.csv");

			if (!arquivo_new_geral.is_open()) {
				std::cout << "Erro ao abrir o arquivo, tente novamente!\n";
				break;
			}
      	
			for(int i = 0; i < b; i++){
				arquivo_new_geral << alunos[i].nome << ";"
								<< alunos[i].matricula << ";"
								<< alunos[i].aep1 << ";"
								<< alunos[i].prova1 << ";"
								<< alunos[i].aep2 << ";"
								<< alunos[i].prova2 << ";"
								<< alunos[i].sub << ";"
								<< alunos[i].media << ";"
								<< alunos[i].status << "\n";
			}
            arquivo_new_geral.close();
            remove("geral.csv");
            rename("geral1.csv", "geral.csv");
			std::cout << "Relatório atualizado" << std::endl;
      	break;
      	case 2:
      		
      		system("cls");
			arquivo_reprovados.open("reprovados1.csv");

			if (!arquivo_reprovados.is_open()) {
				std::cout << "Erro ao abrir o arquivo, tente novamente!\n";
				break;
			}

  
      		for(int i = 0; i < b; i++){
      			if(alunos[i].status == "reprovado"){
      				arquivo_reprovados << alunos[i].nome << ";"
								<< alunos[i].matricula << ";"
								<< alunos[i].aep1 << ";"
								<< alunos[i].prova1 << ";"
								<< alunos[i].aep2 << ";"
								<< alunos[i].prova2 << ";"
								<< alunos[i].sub << ";"
								<< alunos[i].media << ";"
								<< alunos[i].status << "\n";
				  }
			}
			arquivo_reprovados.close();
			remove("reprovados.csv");
            rename("reprovados1.csv", "reprovados.csv");
			std::cout << "Relatororio atualizado" << std::endl;
      	break;
      	case 3:


      		system("cls");
			arquivo_aprovados.open("aprovados1.csv");

			if (!arquivo_aprovados.is_open()) {
				std::cout << "Erro ao abrir o arquivo, tente novamente!\n";
				break;
			}

      		for(int i = 0; i < b; i++){
      			if(alunos[i].status == "aprovado"){
      				arquivo_aprovados << alunos[i].nome << ";"
								<< alunos[i].matricula << ";"
								<< alunos[i].aep1 << ";"
								<< alunos[i].prova1 << ";"
								<< alunos[i].aep2 << ";"
								<< alunos[i].prova2 << ";"
								<< alunos[i].sub << ";"
								<< alunos[i].media << ";"
								<< alunos[i].status << "\n";
				  }
			}
			arquivo_aprovados.close();
			remove("aprovados.csv");
            rename("aprovados1.csv", "aprovados.csv");
			std::cout << "Relatororio atualizado" << std::endl;
      	break;
      	case 4:


      		system("cls");
			arquivo_sub1.open("sub_1_bm1.csv");

			if (!arquivo_sub1.is_open()) {
				std::cout << "Erro ao abrir o arquivo, tente novamente!\n";
				break;
			}
 
      		for(int i = 0; i < b; i++){
      			if((alunos[i].aep1 +  alunos[i].prova1) < 6){
      				arquivo_sub1 << alunos[i].nome << ";"
							<< alunos[i].matricula << ";"
							<< alunos[i].aep1 << ";"
							<< alunos[i].prova1 << ";"
							<< alunos[i].aep2 << ";"
							<< alunos[i].prova2 << ";"
							<< alunos[i].sub << ";"
							<< alunos[i].media << ";"
							<< alunos[i].status << "\n";
				  }
			  }
            arquivo_sub1.close();
            remove("sub_1_bm.csv");
            rename("sub_1_bm1.csv", "sub_1_bm.csv");
            std::cout << "Relatororio atualizado" << std::endl;

      	break;
      	case 5:


      		system("cls");
			arquivo_sub2.open("sub_2_bm1.csv");

			if (!arquivo_sub2.is_open()) {
				std::cout << "Erro ao abrir o arquivo, tente novamente!\n";
				break;
			}

      		for(int i = 0; i < b; i++){
      			if((alunos[i].aep2 +  alunos[i].prova2) < 6){
      				arquivo_sub2 << alunos[i].nome << ";"
								<< alunos[i].matricula << ";"
								<< alunos[i].aep1 << ";"
								<< alunos[i].prova1 << ";"
								<< alunos[i].aep2 << ";"
								<< alunos[i].prova2 << ";"
								<< alunos[i].sub << ";"
								<< alunos[i].media << ";"
								<< alunos[i].status << "\n";
				  }
			  }
            arquivo_sub2.close();
            remove("sub_2_bm.csv");
            rename("sub_2_bm1.csv", "sub_2_bm.csv");
            std::cout << "Relatororio atualizado" << std::endl;

      	break;
		}
	}
}



void cadastrar_notas (){
	system("cls");
	std::string matricula_alt;
	std::cout << "Digite o numero da matricula para alterar as notas: ";
	std::cin >> matricula_alt;
	//variaveis
	int rodar_arquivo = 0;
	int b = 0;
	char delimitador = ';';
	std::string str;
	std::fstream arquivo;
	int w =0;
	int opcao_notas = 0;
	arquivo.open("database.csv", std::ios::in);

	if (!arquivo.is_open()) {
		std::cout << "Erro ao abrir o arquivo, tente novamente!\n";
	}
	else{
		while (arquivo.good()) {
			rodar_arquivo = arquivo.get();
			if (rodar_arquivo == '\n') {
				b++;
			}
		}
	}
	std::string line;
	std::string linha[b];
	int tamanho = 0;
	arquivo.close();
	std::vector<struct Aluno> alunos(b);



	arquivo.open("database.csv", std::ios::in);
	do{
		arquivo >> linha[tamanho];
		tamanho++;
	}while(getline(arquivo, line));
	arquivo.close();


	for(int i = 0; i < b; i++){
		w = 0;
		std::stringstream X(linha[i]);
		while (getline(X, str, ';')){
			if(w == 0){
				alunos[i].nome = str;
			} else if(w == 1){
				alunos[i].matricula = str;
			} else if(w == 2){
				alunos[i].aep1 = std::stof(str);
			} else if(w == 3){
				alunos[i].prova1 = std::stof(str);
			} else if(w == 4){
				alunos[i].aep2 = std::stof(str);
			} else if(w == 5){
				alunos[i].prova2 = std::stof(str);
			} else if(w == 6){
				alunos[i].sub = std::stof(str);
			} else if(w == 7){
				alunos[i].media = std::stof(str);
			} else if(w == 8){
				alunos[i].status = str;
			}
			w++;
		}
	}

	for(int i = 0; i < b; i++){
		if(alunos[i].matricula == matricula_alt){
			std::cout << " Nome: " << alunos[i].nome
					<< " Matricula: " << alunos[i].matricula
					<< " AEP1: " << alunos[i].aep1
					<< " Prova1: " << alunos[i].prova1
					<< " AEP2: " << alunos[i].aep2
					<< " PROVA2: " << alunos[i].prova2
					<< " SUB1: " << alunos[i].sub
					<< " Media: " << alunos[i].media
					<< " Status: " << alunos[i].status << std::endl;
			std::cout << "Escolha uma das opções a seguir: " << std::endl
		          << "1) Alterar a nota da AEP1" << std::endl
		          << "2) Alterar a nota da prova1" << std::endl
		          << "3) Alterar a nota da AEP2" << std::endl
		          << "4) Alterar a nota da prova2" << std::endl
		          << "5) Alterar a nota da substitutiva" << std::endl
				  << "6) Para voltar" << std::endl;
		          std::cin >> opcao_notas;
	    	switch(opcao_notas){
	    		case 1:
	    			system("cls");
	    			std::cout << " Nome: " << alunos[i].nome
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << std::endl;
					std::cout << "Digite a nota da AEP1: ";
					std::cin >> alunos[i].aep1;
			
					if(alunos[i].sub != 0){
				
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							//se n for maior
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						//se a sub for 0
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 2:
	    			system("cls");
	    			std::cout << " Nome: " << alunos[i].nome
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << std::endl;
					std::cout << "Digite a nota da Prova1: ";
				
					std::cin >> alunos[i].prova1;
				
					if(alunos[i].sub != 0){
					
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
				
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
					
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 3:
	    			system("cls");
	    			std::cout << " Nome: " << alunos[i].nome
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << std::endl;
					std::cout << "Digite a nota da AEP2: ";
					std::cin >> alunos[i].aep2;
				
					if(alunos[i].sub != 0){
					
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
						
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 4:
	    			system("cls");
	    			std::cout << " Nome: " << alunos[i].nome
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << std::endl;
					std::cout << "Digite a nota da Prova2: ";
					std::cin >> alunos[i].prova2;
				
					if(alunos[i].sub != 0){
					
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
						
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
					
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
	    		case 5:
	    			system("cls");
	    			std::cout << " Nome: " << alunos[i].nome
								<< " Matricula: " << alunos[i].matricula
								<< " AEP1: " << alunos[i].aep1
								<< " Prova1: " << alunos[i].prova1
								<< " AEP2: " << alunos[i].aep2
								<< " PROVA2: " << alunos[i].prova2
								<< " SUB1: " << alunos[i].sub
								<< " Media: " << alunos[i].media
								<< " Status: " << alunos[i].status << std::endl;
					std::cout << "Digite a nota da Prova2: ";
					std::cin >> alunos[i].sub;
				
					if(alunos[i].sub != 0){
					
						if((alunos[i].aep1 + alunos[i].prova1) > (alunos[i].aep2 + alunos[i].prova2)){
							alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].sub)) / 2;
						} else{
							
							alunos[i].media = ((alunos[i].sub) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
						}
					}
					else{
					
						alunos[i].media = ((alunos[i].aep1 + alunos[i].prova1) + (alunos[i].aep2 + alunos[i].prova2)) / 2;
					}
	    		break;
			}
		}
	}
	std::ofstream arquivo_new;
	arquivo_new.open("database1.csv");


	if (!arquivo_new.is_open()) {
		std::cout << "Erro ao abrir o arquivo, tente novamente!\n";
	}
	else{
		for(int i = 0; i < b; i++){
			if(alunos[i].media >= 6){
                alunos[i].status = "aprovado";
                arquivo_new << alunos[i].nome << ";"
                        << alunos[i].matricula << ";"
                        << alunos[i].aep1 << ";"
                        << alunos[i].prova1 << ";"
                        << alunos[i].aep2 << ";"
                        << alunos[i].prova2 << ";"
                        << alunos[i].sub << ";"
                        << alunos[i].media << ";"
                        << alunos[i].status << "\n";
			 }else {
                alunos[i].status = "reprovado";
                arquivo_new << alunos[i].nome << ";"
                        << alunos[i].matricula << ";"
                        << alunos[i].aep1 << ";"
                        << alunos[i].prova1 << ";"
                        << alunos[i].aep2 << ";"
                        << alunos[i].prova2 << ";"
                        << alunos[i].sub << ";"
                        << alunos[i].media << ";"
                        << alunos[i].status << "\n";
			}
		}
	}
	arquivo_new.close();
    remove("database.csv");
	rename("database1.csv", "database.csv");

}
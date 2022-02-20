
/*
PROJETO TÉCNICAS DE PROGRAMAÇÃO - GERENCIAMENTO DE HORTIFRUTI

> PROGRAMA REALIZADO UTILIZANDO O CODEBLOCKS

*/

#include <iostream>
#include <locale>
#include <iomanip>
#include<cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

#include "PROJETOPRODUTO.cpp"
#include "PROJETOPRODUTOQUILO.cpp"
#include "PROJETOPRODUTOUNIDADE.cpp"
#include "PROJETOUSUARIO.cpp"
#include "PROJETOCLIENTE.cpp"
#include "PROJETOADM.cpp"
#include "PROJETOGESTAO.cpp"

int main()
{
	setlocale(LC_ALL,"Portuguese");
	int opc = -1;
	int op_usuario = -1;
	string senha;
	ProjetoGestao gerencia;
	Administrador gerente("Justino Alves", "553.199.614-88", "2021", 1253, "55-987", 10);
	
	while(opc!=0){

		cout << "Bem-vindo ao Hortifruti Alves! Aqui você encontra os melhores preços!";
		cout << endl<<endl<<endl;
		cout << "--------- OPÇÕES DE ACESSO ---------\n";
		cout << "0) Sair do programa\n";
		cout << "1) Acessar como administrador\n";
		cout << "2) Acessar como cliente\n\n";
		cout << "Informe sua opção: ";
		cin >> opc;
		op_usuario = -1;
		
		if(opc == 1){
			cout << "\nDigite a senha para acessar o sistema como administrador: ";
			cin >> senha;
			
			if (senha == gerente.getSenha_usuario()){
				system("cls");
				cout << "\n\n--------- Bem-vindo(a) " << gerente.getNome_usuario() << " ---------"<<endl<<endl;
				system("pause");
				system("cls");
				while(op_usuario != 0){
					cout << "--------- OPÇÕES DO ADMINISTRADOR---------\n";
					cout << "0) Fazer logout\n";
					cout << "1) Inserir produto\n";
					cout << "2) Remover produto\n";
					cout << "3) Ver lista dos produtos\n";
					cout << "4) Cadastrar cliente\n";
					cout << "5) Ver lista de clientes cadastrados\n";
					cout << "6) Ver ganhos do dia\n\n";
					cout << "Informe sua opção: ";		
					cin >> op_usuario;
					if (op_usuario == 1){
						system("pause");
						system("cls");
						gerencia.inserir_produtos();
					}
						
					else if (op_usuario == 2){
						string produto_buscado;
						cout << "Informe qual produto busca remover: ";
						cin.ignore();
						getline(cin,produto_buscado);
						gerencia.remove_produto(produto_buscado);
					}
					
					else if (op_usuario == 3){
						gerencia.exibe_produtos();
					}
						
					else if (op_usuario == 4){
						gerencia.adiciona_cliente();
					}
					
					else if (op_usuario == 5){
						gerencia.exibe_clientes();
					}
					
					else if (op_usuario == 6){
						gerencia.ver_lucros();
					}
					
					else if (op_usuario == 0) {
						system("pause");
						system("cls");
					}
				}
			}
			else
				cout << "\nSenha incorreta." <<endl;
		}
		
		else if(opc == 2){
			system("pause");
			system("cls");
			int resposta_user;
			
			cout << "Você já é um cliente do nosso hortifruti? (1-sim ou 2-não)\n";
			cin >> resposta_user;
			if(resposta_user == 1){
				string nome_user;
				cout << endl << "Nesse caso, insira o seu nome: ";
				cin.ignore();
				getline(cin,nome_user);
				
				if(gerencia.verifica_senhauser(nome_user) == true){
					system("pause");
					system("cls");
					while(op_usuario != 0){
						cout << "--------- OPÇÕES DO CLIENTE---------\n";
						cout << "0) Fazer logout\n";
						cout << "1) Comprar produto\n";
						cout << "2) Ver lista dos produtos\n";
						cout << "Informe sua opção: ";
						cin >> op_usuario;
						
						if (op_usuario == 1){
							int opc;
							gerencia.vende_produto();
						}
		
						else if (op_usuario == 2){
							gerencia.exibe_produtos();
						}
						else if (op_usuario == 0){
							gerencia.limpa_vector();
						} 
						else{
							cout <<endl<< "Entrada inválida." <<endl;
						}
						system("pause");
						system("cls");
					}
				}
				else
					system("pause");
					system("cls");
			}
			
			if(resposta_user == 2){
				cout << endl << "Você deseja se tornar cliente de nosso hortifruti?(1-sim ou 2-não)\n";
				resposta_user = -1;
				cin >> resposta_user;
				if(resposta_user == 1){
					cout << endl;
					gerencia.adiciona_cliente();
				}
				if(resposta_user == 2){
					cout << "Olá, iremos então mostrar nossos produtos!\n";
					gerencia.exibe_produtos();
					system("pause");
					system("cls");
				}
			}
		}
		
		else if (opc == 0){
			break;
		}
		
		else{
			cout <<endl<< "Entrada inválida, digite sua opção novamente." <<endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}


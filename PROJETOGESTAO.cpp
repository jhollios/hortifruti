#include "PROJETOGESTAO.h"

//Métodos da classe

ProjetoGestao::ProjetoGestao(){
	
	ler_lista_estoque_unidade();
	ler_lista_estoque_quilo();
	ler_lista_cliente();
	quanttotalU=0;
	quanttotalQ=0;
	precototalU=0;
	precototalQ=0;
	
	cout <<endl<< "-------------- O programa foi inicializado e os dados carregados. --------------" <<endl<<endl;
	system("pause");
	system("cls");
}

ProjetoGestao::~ProjetoGestao(){
	
	grava_lista_estoque_unidade();
	grava_lista_estoque_quilo();
	grava_lista_cliente();
	
	system("cls");
	cout <<endl<< "-------------- Os dados foram salvos. --------------" <<endl;
}

void ProjetoGestao::ler_lista_estoque_unidade(){
	ifstream arquivoUnidade;
	arquivoUnidade.open("lista_Produto_Unidade.txt", ios::in);
	
	Produtounidade produto_auxU;
	arquivoUnidade.read(reinterpret_cast<char *> (&produto_auxU),sizeof(Produtounidade));

	while(arquivoUnidade && !arquivoUnidade.eof()){ 
		estoque_unidade.push_back(produto_auxU);
		arquivoUnidade.read(reinterpret_cast<char *> (&produto_auxU),sizeof(Produtounidade)); 
	} 
	arquivoUnidade.close();
}

void ProjetoGestao::ler_lista_estoque_quilo(){
	ifstream arquivoQuilo;
	arquivoQuilo.open("lista_Produto_Quilo.txt", ios::in);
	
	Produtoquilo produto_auxQ;
	arquivoQuilo.read(reinterpret_cast<char *> (&produto_auxQ),sizeof(Produtoquilo));

	while(arquivoQuilo && !arquivoQuilo.eof()){ 
		estoque_quilo.push_back(produto_auxQ);
		arquivoQuilo.read(reinterpret_cast<char *> (&produto_auxQ),sizeof(Produtoquilo)); 
	} 
	arquivoQuilo.close();
}

void ProjetoGestao::ler_lista_cliente(){
	ifstream arquivoCliente;
	arquivoCliente.open("lista_Cliente.txt", ios::in);
	
	Cliente cliente_aux;
	arquivoCliente.read(reinterpret_cast<char *> (&cliente_aux),sizeof(Cliente));

	while(arquivoCliente && !arquivoCliente.eof()){ 
		cliente.push_back(cliente_aux);
		arquivoCliente.read(reinterpret_cast<char *> (&cliente_aux),sizeof(Cliente)); 
	} 
	arquivoCliente.close();
}

void ProjetoGestao::grava_lista_estoque_unidade(){
	ofstream lista_unidade("lista_Produto_Unidade.txt", ios::out );
	
	for(int i = 0; i < estoque_unidade.size(); i++)
		lista_unidade.write( reinterpret_cast<const char*>(&estoque_unidade[i]), sizeof(Produtounidade) );
}

void ProjetoGestao::grava_lista_estoque_quilo(){
	ofstream lista_quilo("lista_Produto_Quilo.txt", ios::out );
	
	for(int i = 0; i < estoque_quilo.size(); i++)
		lista_quilo.write( reinterpret_cast<const char*>(&estoque_quilo[i]), sizeof(Produtoquilo) );
}

void ProjetoGestao::grava_lista_cliente(){
	ofstream lista_cliente("lista_Cliente.txt", ios::out );
	
	for(int i = 0; i < cliente.size(); i++)
		lista_cliente.write( reinterpret_cast<const char*>(&cliente[i]), sizeof(Cliente) );
}

void ProjetoGestao::pesquisa_produto(string ex_nome){
	int op_usuario;
	while(op_usuario != 0){
		cout << "\nCaso deseje encerrar essa interação, digite 0!";
		cout << "Qual tipo de produto você deseja pesquisar no estoque(1 ou 2): ";
		cin >> op_usuario;
		if(op_usuario == 1){
		  for (unsigned i=0; i<estoque_unidade.size();i++){
	        if (estoque_unidade[i].getNome() == ex_nome){ //VERIFICANDO A IGUALDADE DO PARAMETRO COM O DADO DO VETOR
	   	   	   cout << "Temos o produto no nosso estoque!";
				}
	 	  }
		}

		if(op_usuario == 2){
		  for (unsigned i=0; i<estoque_quilo.size();i++){
	        if (estoque_quilo[i].getNome() == ex_nome){ //VERIFICANDO A IGUALDADE DO PARAMETRO COM O DADO DO VETOR
	            cout << "\nTemos o produto no nosso estoque!";
				}
	 	  }
		}
		system("pause");
		system("cls");
	}
}

void ProjetoGestao::vende_produto(){
	int op_usuario, quant, novaquantemestoque;
	string nome;
	int aux = 0;
	int aux2 = 0;
	int posicao;
	int opc=1;
	while (opc != 3) {
		system("pause");
		system("cls");
		cout << "Qual tipo de produto será comprado(1 - unidade ou 2 - quilo): ";
		cin >> op_usuario;
		if(op_usuario == 1){
			cout << "\nInforme o nome do produto: "; 
			cin.ignore();
			getline(cin,nome);
			cout << "Informe a quantidade de unidades a serem vendidas: ";
			cin >> quant;
	
			if(estoque_unidade.size() == 0){
				cout << "\nNão há produtos disponíveis!"<<endl;
				return;
			}
	
		    for (unsigned i=0; i<estoque_unidade.size(); i++){
		        if (estoque_unidade[i].getNome() == nome){
		        	aux = aux + 1;
		        	if(estoque_unidade[i].getQuantidade() < quant){
		            	cout << "\nNão há no estoque essa quantidade desse produto.\n";
						return;
		   			}
					
					novaquantemestoque = estoque_unidade[i].getQuantidade() - quant;
		        	estoque_unidade[i].setQuantidade(quant);
		        	if (estoque_unidade[i].getQuantidade() > 0){
		            	cout << "\nProduto vendido com sucesso!\n";
		            	
		            	for (unsigned j=0; j<vendidos_unidade.size(); j++) {
		            		if (vendidos_unidade[j].getNome() == nome) {
		            			aux2 = 1;
		            			posicao = j;
							}
						} 
		            	
		            	if (aux2 == 0){
			            	vendidos_unidade.push_back(estoque_unidade[i]);
			            	estoque_unidade[i].setQuantidade(novaquantemestoque);
			            }
			            else if (aux2 == 1) {
			            	vendidos_unidade[posicao].setQuantidade(vendidos_unidade[posicao].getQuantidade()+quant);
			            	estoque_unidade[i].setQuantidade(novaquantemestoque);
						}
					}
		            else if(novaquantemestoque == 0){
		            	cout << "\nProduto vendido com sucesso!\n";
		            	
		            	for (unsigned j=0; j<vendidos_unidade.size(); j++) {
		            		if (vendidos_unidade[j].getNome() == nome) {
		            			aux2 = 1;
		            			posicao = j;
							}
						} 
		            	
		            	if (aux2 == 0){
			            	vendidos_unidade.push_back(estoque_unidade[i]);
		   					estoque_unidade.erase(estoque_unidade.begin()+i);
			            }
			            else if (aux2 == 1) {
			            	vendidos_unidade[posicao].setQuantidade(vendidos_unidade[posicao].getQuantidade()+quant);
			            	estoque_unidade.erase(estoque_unidade.begin()+i);
						}
					}
		   				
		        }
			}
			if (aux == 0){
				cout << "Não temos esse produto em nosso estoque!\n";
			}
			cout << "Deseja comprar mais algum produto? (1-Sim | 2-Não)"<<endl;
		    cin>>opc;
		    if (opc == 2) {
			    cout << endl << "Você deseja receber sua nota fiscal? (1-sim ou 2-não)"  << endl;
				cin >> opc;
				if (opc == 1){
					emite_notafiscal();
				}
				opc = 3;
			}
	    }
			
		else if(op_usuario == 2){
			int auxiliar = 0;
			cout << "\nInforme o nome do produto: ";
			cin.ignore();
			getline(cin,nome);
			cout << "Informe a quantidade de quilos a serem vendidos: ";
			cin >> quant;
	
			if(estoque_quilo.size() == 0){
				cout << "\nNão há produtos disponíveis!"<<endl;
				return;
			}
	
		    for (unsigned i=0; i<estoque_quilo.size(); i++){
		        if (estoque_quilo[i].getNome() == nome){
		        	auxiliar = auxiliar + 1;
		        	if(estoque_quilo[i].getQuantidade() < quant){
		            	cout << "\nNão há no estoque essa quantidade desse produto.";
						return;
		   			}
	
		        	novaquantemestoque = estoque_quilo[i].getQuantidade() - quant;
		        	estoque_quilo[i].setQuantidade(quant);
		        	if (estoque_quilo[i].getQuantidade() > 0){
		            	cout << "\nProduto vendido com sucesso!\n";
		            	
		            	for (unsigned j=0; j<vendidos_quilo.size(); j++) {
		            		if (vendidos_quilo[j].getNome() == nome) {
		            			aux2 = 1;
		            			posicao = j;
							}
						} 
		            	
		            	if (aux2 == 0){
			            	vendidos_quilo.push_back(estoque_quilo[i]);
			            	estoque_quilo[i].setQuantidade(novaquantemestoque);
			            }
			            else if (aux2 == 1) {
			            	vendidos_quilo[posicao].setQuantidade(vendidos_quilo[posicao].getQuantidade()+quant);
			            	estoque_quilo[i].setQuantidade(novaquantemestoque);
						}
					}
		            else if(novaquantemestoque == 0){
		            	cout << "\nProduto vendido com sucesso!\n";
		            	
		            	for (unsigned j=0; j<vendidos_quilo.size(); j++) {
		            		if (vendidos_quilo[j].getNome() == nome) {
		            			aux2 = 1;
		            			posicao = j;
							}
						} 
		            	
		            	if (aux2 == 0){
			            	vendidos_quilo.push_back(estoque_quilo[i]);
		   					estoque_quilo.erase(estoque_quilo.begin()+i);
			            }
			            else if (aux2 == 1) {
			            	vendidos_quilo[posicao].setQuantidade(vendidos_quilo[posicao].getQuantidade()+quant);
			            	estoque_quilo.erase(estoque_quilo.begin()+i);
						}
					}
		        }
		    }
		    if (auxiliar == 0){
				cout << "Não temos esse produto em nosso estoque!\n";
			}
			cout << "Deseja comprar mais algum produto? (1-Sim | 2-Não)"<<endl;
		    cin>>opc;
		    if (opc == 2) {
			    cout << endl << "Você deseja receber sua nota fiscal? (1-sim ou 2-não)"  << endl;
				cin >> opc;
				if (opc == 1){
					emite_notafiscal();
				}
				opc = 3;
			}
		}
	}
}

void ProjetoGestao::inserir_produtos(){
	int acao;
	int escolha_estoque;

	//Atributos do produto por unidade
	string nome_produtoU;
	string tipo_U;
	int quantidade_U;
	float preco_U;

	//Atributos do produto por quilo
	string nome_produtoQ;
	string tipo_Q;
	int quantidade_Q;
	float preco_Q;
	
	while(acao != 2){
		cout << "Qual tipo de produto será adicionado ao estoque(1 - Unidade ou 2 - Quilo): ";
		cin >> escolha_estoque;
		if(escolha_estoque == 1){
			cout << "Insira o nome do produto: ";
			cin.ignore();
			getline(cin,nome_produtoU);
			
			if(!verifica_existencia_no_estoque_unidade(nome_produtoU)){
				
				cout << "Insira o tipo do produto: ";
				getline(cin,tipo_U);
				cout << "Insira a quantidade do produto: ";
				cin >> quantidade_U;
				cout << "Insira o preço por unidade do produto: ";
				cin >> preco_U;
				Produtounidade produto_U(nome_produtoU, tipo_U, quantidade_U, preco_U);
				estoque_unidade.push_back(produto_U);
			}
		
			cout << "Produto inserido no estoque!\n";
		}
		
		if(escolha_estoque == 2){
			cout << "Insira o nome do produto: ";
			cin.ignore();
			getline(cin,nome_produtoQ);
			if(!verifica_existencia_no_estoque_quilo(nome_produtoQ)){
				
				cout << "Insira o tipo do produto: ";
				getline(cin,tipo_Q);
				cout << "Insira a quantidade de quilos do produto: ";
				cin >> quantidade_Q;
				cout << "Insira o preço por quilo do produto: ";
				cin >> preco_Q;
				Produtoquilo produto_Q(nome_produtoQ, tipo_Q, quantidade_Q, preco_Q);
				estoque_quilo.push_back(produto_Q);			
			}

			cout << "Produto inserido no estoque!\n";
		}
		
		cout << endl << "Deseja inserir mais produtos(Digite - 1); Caso deseje parar essa interação digite (Digite -2)\n";
		cin >> acao;
		system("pause");
		system("cls");
	}
	
		system("pause");
		system("cls");
}

bool ProjetoGestao::verifica_existencia_no_estoque_unidade(string nome_produtoU){
	int contador = 0, quantidade_U; 
	
	for (unsigned i = 0; i < estoque_unidade.size(); i++)
        if (estoque_unidade[i].getNome() == nome_produtoU){
        	cout << "Insira a quantidade do produto: ";
			cin >> quantidade_U;
			
        	estoque_unidade[i].setQuantidade(estoque_unidade[i].getQuantidade() + quantidade_U);
        	return true;
		}
		
	return false;
}

bool ProjetoGestao::verifica_existencia_no_estoque_quilo(string nome_produtoQ){
	int contador = 0, quantidade_Q;
	
	for (unsigned i = 0; i < estoque_quilo.size(); i++)
        if (estoque_quilo[i].getNome() == nome_produtoQ){
        	cout << "Insira a quantidade do produto: ";
			cin >> quantidade_Q;
			
        	estoque_quilo[i].setQuantidade(estoque_quilo[i].getQuantidade() + quantidade_Q);
        	return true;
		}
		
	return false;
}

void ProjetoGestao::remove_produto(string ex_nome){ //RECEBE POR PARAMETRO O NOME DO PRODUTO
	int verificacao=0;
	int op_usuario=3;
	while(op_usuario != 0){
		cout << "Qual tipo de produto será removido do estoque(1 ou 2): ";
		cin >> op_usuario;
        if(op_usuario == 1){
            if (estoque_unidade.empty()) {
                cout << "O estoque de produtos por unidade está vazio!"<<endl;
                break;
            }
            else {
                for (unsigned i=0; i<estoque_unidade.size();i++){
                    if (estoque_unidade[i].getNome() == ex_nome){ //VERIFICANDO A IGUALDADE DO PARAMETRO COM O DADO DO VETOR
                        estoque_unidade.erase(estoque_unidade.begin()+i);
                        verificacao += 1;
                        }
                }
                if (verificacao == 1) {
                    cout << "Produto removido com sucesso!"<<endl;
                    break;
                }
                else {
                    cout << "Produto não encontrado!"<<endl;
                    break;
                }
            }
        }
		if(op_usuario == 2){
            if (estoque_quilo.empty()) {
                cout << "O estoque de produtos por quilo está vazio!"<<endl;
                break;
            }
            else {
                for (unsigned i=0; i<estoque_quilo.size();i++){
                    if (estoque_quilo[i].getNome() == ex_nome){ //VERIFICANDO A IGUALDADE DO PARAMETRO COM O DADO DO VETOR
                        estoque_quilo.erase(estoque_quilo.begin()+i);
                        verificacao += 1;
                        }
                }
                if (verificacao == 1) {
                    cout << "Produto removido com sucesso!"<<endl;
                    break;
                }
                else {
                    cout << "Produto não encontrado!"<<endl;
                    break;
                }
            }
        }
	}
	system("pause");
	system("cls");
}

void ProjetoGestao::adiciona_cliente(){
	string nome_c;
	string CPF_c;
	string senha_c;
	string email_c;
	system("pause");
	system("cls");
	
	cout << "Agora iremos dar início ao seu cadastro em nosso hortifruti!\n";
	cout << "Informe o nome do cliente: ";
	cin.ignore();
	getline(cin,nome_c);
	cout << "Informe o CPF do cliente: ";
	getline(cin,CPF_c);
	cout << "insira a nova senha: ";
	cin >> senha_c;
	cout << "insira o seu e-mail: ";
	cin.ignore();
	getline(cin,email_c);
	Cliente cliente_c(nome_c, CPF_c, senha_c, email_c);
	cliente.push_back(cliente_c);
	cout << "Cliente cadastrado no sistema!\n";
	system("pause");
	system("cls");
}

void ProjetoGestao::exibe_produtos(){
	int opc = -1;
    while(opc != 0){
    	system("pause");
		system("cls");
        cout << "Caso deseje encerrar esta interação, digite 0\n";
        cout << "Qual tipo de produto você busca(1 - Produtos por unidade ou 2 - Produtos por quilo): ";
        cin >> opc;
        cout << endl;
        if(opc == 1){
            if(estoque_unidade.size() == 0){
                cout << "Não há produtos por unidade disponíveis!\n";
            }else{
                cout<<"Produtos disponíveis para compra: "<<endl<<endl;
                for (unsigned i=0; i < estoque_unidade.size();i++){
                    cout <<endl<< i + 1 << "º Produto:\n";
                    cout << "Nome: " << estoque_unidade[i].getNome() << endl;
                    cout<< "Tipo: "<< estoque_unidade[i].getTipo()<<endl;
                    cout<<"Quantidade: "<<estoque_unidade[i].getQuantidade()<< " Unidades" <<endl;
                    cout<<fixed<<setprecision(2)<<"Preço de unidade: " << "R$" <<estoque_unidade[i].getPreco_unidade()<<endl;
                }
            }
        }
        if(opc == 2){
            if(estoque_quilo.size() == 0){
                cout <<endl<< "Não há produtos por quilo disponíveis!\n";
            }else{
                cout<<"Produtos disponíveis para compra: "<<endl<<endl;
                for (unsigned i=0; i < estoque_quilo.size();i++){
                    cout <<endl<< i + 1 << "º Produto:\n";
                    cout << "Nome: " << estoque_quilo[i].getNome() << endl;
                    cout<< "Tipo: "<< estoque_quilo[i].getTipo()<<endl;
                    cout<<"Quantidade: "<<estoque_quilo[i].getQuantidade()<< " Quilos" << endl;
                    cout<<fixed<<setprecision(2)<<"Preço do quilo: "<< "R$" << estoque_quilo[i].getPreco_quilo()<<endl;
                }
            }
        }
    }
    system("pause");
	system("cls");
}

void ProjetoGestao::emite_notafiscal(){
	float precototal=0,precoproduto=0;
	cout << "-------- NOTA FISCAL --------\n\n";
	cout << "LISTA DOS PRODUTOS COMPRADOS:\n";
	if (!vendidos_unidade.empty()) {
		cout<<endl<<"Produtos comprados por unidade: "<<endl<<endl;
		for (unsigned i=0; i < vendidos_unidade.size();i++){
			cout << i + 1 << "º Produto:\n";
			cout << "Nome: " << vendidos_unidade[i].getNome() << endl;
			cout<< "Tipo: "<< vendidos_unidade[i].getTipo()<<endl;
			cout<<"Quantidade: "<<vendidos_unidade[i].getQuantidade()<< " Unidades" << endl;
			precoproduto = (vendidos_unidade[i].getPreco_unidade()*vendidos_unidade[i].getQuantidade());
			cout<<fixed<<setprecision(2)<<"Preço: "<< "R$" <<precoproduto<<endl<<endl;
			precototal += precoproduto;
		}
	}
	if (!vendidos_quilo.empty()) {
		cout<<"Produtos comprados por quilo: "<<endl<<endl;
		for (unsigned i=0; i < vendidos_quilo.size();i++){
			cout << i + 1 << "º Produto:\n";
			cout << "Nome: " << vendidos_quilo[i].getNome() << endl;
			cout<< "Tipo: "<< vendidos_quilo[i].getTipo()<<endl;
			cout<<"Quantidade: "<<vendidos_quilo[i].getQuantidade()<< " Quilos" << endl;
			precoproduto = (vendidos_quilo[i].getPreco_quilo()*vendidos_quilo[i].getQuantidade());
			cout<<fixed<<setprecision(2)<<"Preço: "<< "R$" <<precoproduto<<endl<<endl;
			precototal += precoproduto;
		}
	}
	cout <<fixed<<setprecision(2)<< endl << "Valor total da compra: R$" << precototal << endl;
}

bool ProjetoGestao::verifica_senhauser(string nome_user){  
	int posicao=-1;
	string senha_user;
    for (unsigned i=0; i < cliente.size();i++){
        if(cliente[i].getNome_usuario() == nome_user){
            posicao = i;
        }
    }
    if (posicao != -1) {
    	cout<<"Digite a sua senha: ";
    	cin>>senha_user;
	    if (cliente[posicao].getSenha_usuario() == senha_user) {
	    	return true;
		}
		else {
			cout<<"Senha invalida!"<<endl;
			return false;
		}
	}
	else {
		cout<<"Usuário não encontrado!"<<endl;
		return false;
	}
}

void ProjetoGestao::limpa_vector(){  

	for (unsigned i=0; i < vendidos_unidade.size();i++){
		quanttotalU += vendidos_unidade[i].getQuantidade();
		precototalU += (vendidos_unidade[i].getPreco_unidade()*vendidos_unidade[i].getQuantidade());
	}
	
	for (unsigned i=0; i < vendidos_quilo.size();i++){
		quanttotalQ += vendidos_quilo[i].getQuantidade();
		precototalQ += (vendidos_quilo[i].getPreco_quilo()*vendidos_quilo[i].getQuantidade());
	}
	
	for(int i =0; i < vendidos_unidade.size(); i++){
		vendidos_unidade.erase(vendidos_unidade.begin()+i);
	}

	for(int i =0; i < vendidos_quilo.size(); i++){
		vendidos_quilo.erase(vendidos_quilo.begin()+i);
	}
}

void ProjetoGestao::ver_lucros(){
	system("pause");
	system("cls");
	
	cout <<fixed<<setprecision(2);
	cout << "Exibindo ganhos do dia:" << endl << endl;
	cout << "Foram vendidos " << quanttotalU << " unidades de frutas, legumes e verduras."<<endl;
	cout << "Totalizando um ganho de: R$ " << precototalU << endl << endl;
	cout << "Foram vendidos " << quanttotalQ << " quilos de frutas, legumes e verduras."<<endl;
	cout << "Totalizando um ganho de: R$ " << precototalQ << endl << endl;
	cout << "O ganho total foi de: R$" << (precototalQ + precototalU) << endl;
	
	system("pause");
	system("cls");
}

void ProjetoGestao::exibe_clientes(){
	system("pause");
	system("cls");
	
	if (cliente.size() == 0){
		cout <<endl<< "Nenhum cliente cadastrado no momento." <<endl;
	}
	else
		cout <<endl<< "Cliente(s) cadastrado(s): " <<endl<<endl;
		for (int i = 0; i < cliente.size(); i++){
			cout << "Nome: " << cliente[i].getNome_usuario() <<endl;
			cout << "E-mail: " << cliente[i].getEmail() <<endl<<endl;
		}
	
	system("pause");
	system("cls");
}

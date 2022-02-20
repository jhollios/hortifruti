#include "PROJETOPRODUTO.h"

//Construtor
Produto::Produto(string nome, string tipo, float quantidade){
	setNome(nome);
	setTipo(tipo);
	setQuantidade(quantidade);
}


void Produto::setNome(string nome){
	strncpy( this-> nome, nome.c_str(), 49);
	this->nome[49] = '\0';
}

void Produto::setTipo(string tipo){
	strncpy( this-> tipo, tipo.c_str(), 49);
	this->tipo[49] = '\0';
}

void Produto::setQuantidade(float quantidade){
	this->quantidade = quantidade;
}

//Métodos de retorno
string Produto::getNome() const{
	return nome;
}

string Produto::getTipo() const{
	return tipo;
}

float Produto::getQuantidade() const{
	return quantidade;
}

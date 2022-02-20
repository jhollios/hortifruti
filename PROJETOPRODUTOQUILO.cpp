#include "PROJETOPRODUTOQUILO.h"

//Construtor
Produtoquilo::Produtoquilo(string nome, string tipo, float quantidade,  
							float preco_quilo) : Produto(nome,tipo,quantidade){
	setPreco_quilo(preco_quilo);
}

void Produtoquilo::setPreco_quilo(float preco_quilo){
	this-> preco_quilo = preco_quilo;
}

float Produtoquilo::getPreco_quilo() const{
	return preco_quilo;
}




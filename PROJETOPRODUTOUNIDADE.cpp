#include "PROJETOPRODUTOUNIDADE.h"

Produtounidade::Produtounidade(string nome, string tipo, float quantidade,
								float preco_unidade) : Produto(nome,tipo,quantidade){
	setPreco_unidade(preco_unidade);
}

void Produtounidade::setPreco_unidade(float preco_unidade){
	this-> preco_unidade = preco_unidade;
}

float Produtounidade::getPreco_unidade() const{
	return preco_unidade;
}




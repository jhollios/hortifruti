#ifndef PROJETOPRODUTO_H
#define PROJETOPRODUTO_H

//Classe base para produto unidade e quilo 
class Produto{
	private:
		char nome[50];
		char tipo[50];
		float quantidade;
		
	public:
		Produto(string, string, float); 

		void setNome(string);
		void setTipo(string);
		void setQuantidade(float);		
		
		string getNome() const;
		string getTipo() const;
		float getQuantidade() const;
};

#endif

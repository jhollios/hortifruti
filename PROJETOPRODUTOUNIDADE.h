#ifndef PROJETOPRODUTOUNIDADE_H
#define PROJETOPRODUTOUNIDADE_H

class Produtounidade : public Produto{
	private:
		float preco_unidade;
		
	public:
		Produtounidade(string = "", string = "", float = 0.0, float = 0.0); //Construtor
		
		void setPreco_unidade(float);
		
		float getPreco_unidade() const;
		
		
};

#endif

#ifndef PROJETOPRODUTOQUILO_H
#define PROJETOPRODUTOQUILO_H

class Produtoquilo : public Produto{
	private:
		float preco_quilo;
		
	public:
		Produtoquilo(string = "", string = "", float = 0.0, float = 0.0);
		
		void setPreco_quilo(float);
		
		float getPreco_quilo() const;
};

#endif

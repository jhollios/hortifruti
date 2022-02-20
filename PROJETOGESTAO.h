#ifndef PROJETOGESTAO_H
#define PROJETOGESTAO_H

class ProjetoGestao{
	private:
	    //Atributos da classe
		vector <Produtounidade> estoque_unidade;
		vector <Produtoquilo> estoque_quilo;
		vector <Produtoquilo> vendidos_quilo;
		vector <Produtounidade> vendidos_unidade;
		vector <Cliente> cliente;
		int quanttotalU;
		int quanttotalQ;
		float precototalU;
		float precototalQ;

	public:
		//Métodos da classe
		ProjetoGestao();
		~ProjetoGestao();
		void ler_lista_estoque_unidade();
		void ler_lista_estoque_quilo();
		void ler_lista_cliente();
		void grava_lista_cliente();
		void grava_lista_estoque_unidade();
		void grava_lista_estoque_quilo();
		void pesquisa_produto(string);
		void vende_produto();
		void inserir_produtos();
		void remove_produto(string);
		void adiciona_cliente();
		void exibe_produtos();
		void exibe_clientes();
		void emite_notafiscal();
		bool verifica_senhauser(string);
		bool verifica_existencia_no_estoque_unidade(string);
		bool verifica_existencia_no_estoque_quilo(string);
		void limpa_vector();
		void ver_lucros();
		
		//EXIBINDO PRODUTOS VENDIDOS POR UNIDADE
		void imprimi_verduras_uni();
		void imprimi_legumes_uni();
		void imprimi_frutas_uni();

		//EXIBINDO PRODUTOS VENDIDOS POR QUILO
		void imprimi_legumes_kg();
		void imprimi_frutas_kg();
};

#endif

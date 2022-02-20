#ifndef PROJETOVENDEDOR_H
#define PROJETOVENDEDOR_H

class Administrador : public Usuario {
	private:
		float salario_adm;
		char num_carteira[50];
		int num_cracha;
		
	public:
		Administrador(string, string, string, float, string, int);
		
		void setSalario_adm(float);
		void setNum_carteira(string);
		void setNum_cracha(int);
		
		float getSalario_adm() const;
		string getNum_carteira() const;
		int getNum_cracha() const;

};

#endif

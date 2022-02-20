#ifndef PROJETOUSUARIO_H
#define PROJETOUSUARIO_H

class Usuario {
	private:
		char nome_usuario[50];
		char CPF_usuario[50];
		char senha_usuario[50];
		
	public:
		Usuario(string, string, string);
		
		void setNome_usuario(string);
		void setCPF_usuario(string);
		void setSenha_usuario(string);		
		
		string getNome_usuario() const;
		string getCPF_usuario() const;
		string getSenha_usuario() const;
		
};

#endif

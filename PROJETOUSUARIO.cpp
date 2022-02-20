#include "PROJETOUSUARIO.h"

Usuario::Usuario(string nome_usuario, string CPF_usuario, string senha_usuario){	
	setNome_usuario(nome_usuario);
	setCPF_usuario(CPF_usuario);
	setSenha_usuario(senha_usuario);	
}

void Usuario::setNome_usuario(string nome_usuario){
	strncpy( this-> nome_usuario, nome_usuario.c_str(), 49);
	this->nome_usuario[49] = '\0';
}

void Usuario::setCPF_usuario(string CPF_usuario){
	strncpy( this-> CPF_usuario, CPF_usuario.c_str(), 49);
	this->CPF_usuario[49] = '\0';
}

void Usuario::setSenha_usuario(string senha_usuario){
	strncpy( this-> senha_usuario, senha_usuario.c_str(), 49);
	this->senha_usuario[49] = '\0';
}

string Usuario::getNome_usuario() const{
	return nome_usuario;
}

string Usuario::getCPF_usuario() const{
	return CPF_usuario;
}

string Usuario::getSenha_usuario() const{
	return senha_usuario;
}

#include "PROJETOADM.h"

Administrador::Administrador(string nome_usuario, string CPF_usuario, string senha_usuario, float salario_adm, string num_carteira, int num_cracha
) : Usuario(nome_usuario,CPF_usuario,senha_usuario){
	setSalario_adm(salario_adm);
	setNum_carteira(num_carteira);
	setNum_cracha(num_cracha);
}

void Administrador::setSalario_adm(float salario_adm){
	this-> salario_adm = salario_adm;
}

void Administrador::setNum_carteira(string num_carteira){
	strncpy( this-> num_carteira, num_carteira.c_str(), 49);
	this->num_carteira[49] = '\0';
}

void Administrador::setNum_cracha(int num_cracha){
	this-> num_cracha = num_cracha;
}

float Administrador::getSalario_adm() const{
	return salario_adm;
}

string Administrador::getNum_carteira() const{
	return num_carteira;
}

int Administrador::getNum_cracha() const{
	return num_cracha;
}

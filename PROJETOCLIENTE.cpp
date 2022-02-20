#include "PROJETOCLIENTE.h"

Cliente::Cliente(string nome_usuario, string CPF_usuario, string senha_usuario, 
				string email) : Usuario(nome_usuario,CPF_usuario,senha_usuario){
					
	setEmail(email);
}

void Cliente::setEmail(string email){
	strncpy( this-> email, email.c_str(), 49);
	this->email[49] = '\0'; 
}

string Cliente::getEmail() const{
	return email; 
}


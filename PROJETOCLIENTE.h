#ifndef PROJETOCLIENTE_H
#define PROJETOCLIENTE_H

class Cliente : public Usuario{
	private:
		char email[50];
		
	public:
		Cliente(string = "", string = "", string = "", string = "");
		
		void setEmail(string);
		string getEmail() const;
		
};

#endif

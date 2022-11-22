#include<iostream>
#include<string>
using namespace std;
class CPersona{//clase base
	protected:
		string nombre;
		int edad;
	public:
		CPersona(string="Nombre",int edad=0);
		CPersona(const CPersona&);
		string getNombre();
		void setNombre(string);
		int getEdad();
		void setEdad(int);
		void mostrar();
};
CPersona::CPersona(string nombre,int edad){
	this->nombre=nombre;
	this->edad=edad;
}
CPersona::CPersona(const CPersona&obj){
	this->nombre=obj.nombre;
	this->edad=obj.edad;
}
string CPersona::getNombre(){
	return nombre;
}
void CPersona::setNombre(string nombre){
	this->nombre=nombre;
}
int CPersona::getEdad(){
	return edad;
}
void CPersona::setEdad(int edad){
	this->edad=edad;
}
void CPersona::mostrar(){
	cout<<"Nombre: "<<nombre<<endl
	    <<" edad: " <<edad<<endl;
}

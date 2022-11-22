#include<iostream>
using namespace std;

class Radio{
	protected:
     float frecuencia;
     string banda;//AM FM
     bool encendido;
   public:
     Radio(float =95.5, string ="FM", bool =false);
     void CambiaBanda(string);
     void CambiaFrecuencia(float);
     void On_Off();
     float getFrecuencia();
     string getBanda();
     bool estado();
};

Radio::Radio(float f, string b, bool p){
	 frecuencia = f;
     banda = b;
     encendido = p;
}

void Radio::CambiaBanda(string b){
	banda=b;
}  

void Radio::CambiaFrecuencia(float f){    
	frecuencia = f; 
}

void Radio::On_Off( ){    
	encendido= bool(!encendido); 
}

float Radio::getFrecuencia(){
	return frecuencia; 
}

string Radio::getBanda(){    
	return banda; 
}

bool Radio::estado(){    
	return encendido; 
}


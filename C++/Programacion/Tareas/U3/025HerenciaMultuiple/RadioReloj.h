#include <iostream>
using namespace std;

class RadioReloj: public Radio, public Reloj{
     int alarmaHora;
     int alarmaMinuto;
     bool tipo;// radio=true , timbre=false
     bool alarmaOnOf;// encendida apagada
   public:
     RadioReloj(int =0, int =0,bool =false,bool =false,
	            int =0,int =0,int =0,float =100.9, string ="FM",bool =false);
	            
     void ProgramarAlarma(int, int, bool);
     bool estadoAlarma();
     
     void On_Off_Alarma();
     bool VerificaAlarma();
     /*int getAlarmaHora();
     int getAlarmaMinuto();
     bool getTipo();
     bool getalarmaOnOf();*/
     
     void SuenaAlarma();
};


RadioReloj::RadioReloj(int alarmaHora, int alarmaMinuto,bool tipo,bool alarmaOnOf,
	       int hh,int mm,int ss,
		   float frecuencia, string banda,bool encendido):Reloj(hh,mm,ss),Radio(frecuencia,banda,encendido){
			 this->alarmaHora=alarmaHora;
			 this->alarmaMinuto=alarmaMinuto;
			 this->tipo=tipo;
			 this->alarmaOnOf=alarmaOnOf;		
			}
void RadioReloj::ProgramarAlarma(int ah , int am, bool t){
     alarmaHora = ah;
     alarmaMinuto = am;
     tipo = t;
     alarmaOnOf = true;
}				
bool RadioReloj::estadoAlarma(){
	return alarmaOnOf;
} 
void RadioReloj::On_Off_Alarma(){
     alarmaOnOf = bool(!estadoAlarma()); 
}


bool RadioReloj::VerificaAlarma(){    
    if (hora==alarmaHora && minuto==alarmaMinuto) 
         return true;
     return false;
}

void RadioReloj::SuenaAlarma()
{    if (tipo == false || VerificaAlarma())
     {    const char BEEP=7;
          for (int i =0; i<10; i++) 
		      cout<<BEEP;
     }
     else
     {    On_Off();
          cout << "Frecuencia: ";
          if (banda=="FM") 
		     cout << "FM"<< endl;
          else 
		     cout << "AM"<< endl;
     }
}



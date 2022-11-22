#include<iostream>
using namespace std;

class Reloj{    
   protected:
	 int hora;
     int minuto;
     int segundo;
   public:
     Reloj(int h=0, int m=0, int s=0);
     void DefineTiempo(int, int, int);
     void DefineHora(int);
     void DefineMinuto(int);
     void DefineSegundo(int);
     int Hora(void);
     int Minuto(void);
     int Segundo(void);
     void IncTiempo(void);
     void mostrar();
};

Reloj::Reloj(int h, int m, int s)
{    hora=h;
     minuto=m;
     segundo=s;
}

void Reloj::DefineTiempo(int h, int m, int s)
{    hora=h;
     minuto=m;
     segundo=s;
}

void Reloj::DefineHora(int h)
{    hora = h; 
}

void Reloj::DefineMinuto(int m)
{    minuto = m; 
}

void Reloj::DefineSegundo(int s)
{    segundo = s; 
}

int Reloj::Hora(void)
{    return hora; 
}

int Reloj::Minuto(void)
{    return minuto; 
}

int Reloj::Segundo(void)
{    return segundo; 
}

void Reloj::IncTiempo(void)
{    if (segundo < 59) segundo++;
     else
         if(minuto<59)
         {    minuto++;
              segundo = 0;
         }
         else
             if (hora<23)
             {    hora++;
                  minuto = segundo = 0;
             }
             else
                 hora = minuto = segundo = 0;
}
void Reloj::mostrar(){
	cout<<hora<<":"<<minuto<<":"<<segundo;
}


#include<iostream>

using namespace std;

class THorario{
    private:
        int hh, mm, ss;
    public:
        THorario();//const por defecto
        THorario(int, int, int);// const con arguentos
        //THorario(int=0, int=0, int=0);//const inizializado
        THorario(THorario &obj);//const copia
        void ajuste(int, int, int);
        void militar();
        void standar();
        // constructores
        int getmm();
        int getss();
        int gethh();
        // set
        void sethh(int);
        void setmm(int);
        void setss(int);
};

//Tipo de dato de retorno clase::nombre(parametros)
THorario::THorario(){
    hh = mm = ss = 0;
}
THorario::THorario(int hh, int mm, int ss){// const con arguentos = inizializado solo una o la otra
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
}

THorario::THorario(THorario &obj){//const copia
    hh = obj.hh;
    mm = obj.mm;
    ss = obj.ss;
};

void THorario::ajuste(int h, int m, int s){
    hh = (h>=0 && h<=24)? h:0;
    mm = (m>=0 && m<=60)? m:0;
    ss = (s>=0 && s<=60)? s:0;
};

void THorario::militar(){
    cout << ( hh < 10 ? "0":"") << hh 
         << ( mm < 10 ? "0":"") << mm
         << ( ss < 10 ? "0":"") << ss
         << endl;
};

void THorario::standar(){
    cout << ((hh == 0 || hh == 12)? 12:hh%12)
         << ":" << (mm < 10 ? "0":"" ) << mm
         << ":" << (ss < 10 ? "0":"" ) << ss
         << ( hh < 12 ? "AM":"PM" ) << endl;
};

int THorario::gethh(){
	return hh;
}

int THorario::getmm(){
	return mm;
}

int THorario::getss(){
	return ss;
}

void THorario::sethh(int hh){
	this->hh = hh;
}

void THorario::setmm(int mm){
	this->ss = mm;
}

void THorario::setss(int ss){
	this->ss = ss;
}
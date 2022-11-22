class CEstudiante: public CPersona{
	protected:
		string escuela;
		float promGral;
	public:
		CEstudiante();
		CEstudiante(string,float,CPersona);
		CEstudiante(string,float,string,int);
		string getescuela();
		float getpromGral();
		void setescuela(string);
		void setpromGral(float);
		void mostrar();
};
CEstudiante::CEstudiante():CPersona(){
	this->escuela="";
	this->promGral=0.0;
	
}
CEstudiante::CEstudiante(string escuela,float promGral,CPersona obj):CPersona(obj){
	this->escuela=escuela;
	this->promGral=promGral;
}
CEstudiante::CEstudiante(string escuela,float promGral,string nombre,int edad):CPersona(nombre,edad){
	this->escuela=escuela;
	this->promGral=promGral;
}
string CEstudiante::getescuela(){
	return escuela;
}
float CEstudiante::getpromGral(){
	return promGral;
}
void CEstudiante::setescuela(string escuela){
	this->escuela=escuela;
}
void CEstudiante::setpromGral(float promGral){
	this->promGral=promGral;
}
void CEstudiante::mostrar(){
	CPersona::mostrar();
	cout<<"Escuela: "<<escuela<<endl
	    <<"Promedio: "<<promGral;
}

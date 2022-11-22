class Empleado : public CPersona { // clase derivada Empleado
	protected:
		float salario;
	public:
		Empleado( string = "", int = 18, float = 0 );
		Empleado (float,CPersona &);
		float getSalario();
		void setSalario(float salario);
		void mostrar ();	
};
// llamada al constructor de la clase base
Empleado::Empleado( string nombre, int edad, float salario ):CPersona( nombre, edad) { 
	this->salario = salario;
}
Empleado::Empleado (float salario ,CPersona &obj):CPersona(obj){
	this->salario = salario;
}
float Empleado ::getSalario() { 
	return salario; 
}

void Empleado ::setSalario(float salario ) {
	this->salario = salario;
}
void Empleado ::mostrar (){
	CPersona::mostrar();
	cout<<"Salario de la pesrsona es: "<<salario;
}

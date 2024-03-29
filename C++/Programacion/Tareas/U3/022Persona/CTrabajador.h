class CTrabajador : protected CPersona {
   protected:
    float salario;
    string empresa;

   public:
    CTrabajador() : CPersona() {
        this->salario = 0;
        this->empresa = "";
    };
    CTrabajador(string empresa, float salario, string nombre, int edad) : CPersona(nombre, edad) {
        this->salario = salario;
        this->empresa = empresa;
    };
    CTrabajador(const CTrabajador &tobj, const CPersona &pobj) : CPersona(pobj) {
        this->salario = tobj.salario;
        this->empresa = tobj.salario;
    };
    CTrabajador(string empresa, float salario, const CPersona &obj) : CPersona(obj) {
        this->salario = salario;
        this->empresa = empresa;
    };
    inline void setEmpresa(string empresa) { this->empresa = empresa; };
    inline void setSalario(float salario) { this->salario = salario; };
    inline string getEmpresa() { return this->empresa; };
    inline float getSalario() { return this->salario; };
    void mostrar() override;
    friend ostream &operator<<(ostream &out, const CTrabajador &obj) {
        out << "Empresa: '" << obj.empresa << "' " << endl
            << "Salario $" << obj.salario;
        return out;
    }
};

void CTrabajador::mostrar() {
    CPersona::mostrar();
    cout << endl
         << "Empresa: '" << empresa << "' " << endl
         << "Salario: " << salario;
}

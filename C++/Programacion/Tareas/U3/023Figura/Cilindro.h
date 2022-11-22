class Cilindro : public Circulo {
   protected:
    double alto;  // agrega un miembro de datos adicional y
   public:        // dos miembros de funci�n adicionales
    Cilindro(double radio = 1.0, double alto = 1.0);
    double area();
};
Cilindro::Cilindro(double radio, double alto) : Circulo(radio) {
    this->alto = alto;
}
double Cilindro::area() {             // esto calcula un volumen
    return (alto * Circulo::area());  // n�tese la llamada a la funci�n base
}

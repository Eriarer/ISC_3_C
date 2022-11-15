#include <iostream>
#include <string>

using namespace std;
/*
=======  READ ME =======
si quiere una correcta impresion de grafos CON LETRAS
    Hacer un cast (char)(k+65)
    Hacer un cast (char)(i+65)
si quiere una correcta impresion de grafos CON NUMEROS
empezando des 0
    cambiar el cout de impresion por:
        cout << k
        cout << i
    CAMBIAR en la funcion fill el paso de parametros
    de las funciones addNoDirigido y addDirigido por solo
        (i, j)
EN CASO CONTRARIO
    cambiar la impresion por:
        cout << k + 1
        cout << i + 1
    CAMBIAR en la funcion fill el paso de parametros
    de las funciones addNoDirigido y addDirigido por solo
        (i - 1, j - 1)
SI QUIERE HACER INDICACIONES DE INSERCION CON LETRAS
modificar el codigo para que haga los respectivos cast
en las funciones addNoDirigido y addDirigiso

Las zonas para ahcer esos respectivos cambios verificar
las partes del codigo indicadas con un

//=== CAMBIO ===//
*/
class Grafo {
   private:
    int **matriz, ren, col;

   public:
    Grafo(int n) {                     // al ser una matriz cuadrada
        this->ren = n;                 // renglones y columnas
        this->col = n;                 // son iguales
        matriz = new int *[ren];       // crea los renglones
        for (int i = 0; i < ren; i++)  // en cada renglon
            matriz[i] = new int[col];  // crea una columna
        for (int i = 0; i < ren; i++)  // llena la matriz de 0´s
            for (int j = 0; j < col; j++)
                matriz[i][j] = 0;
    }
    ~Grafo() {
        for (int i = 0; i < ren; i++)  // destruye las columnas
            delete[] matriz[i];        // de cada renglon de la matriz
        delete[] matriz;               // destruye la matriz
    }
    void addNoDirigido(int i, int j) {  // al ser NO dirigido
        matriz[i][j] = 1;               // crea una matriz simetrica
        matriz[j][i] = 1;               // la insersion es simetrica
    };
    void addDirigido(int i, int j) {  // al SI ser dirigido
        matriz[i][j] = 1;             // es una insercion simple
    }
    void fill(char selec) {
        bool flag = false;  // bandera que utilizaremos para la validacion (se puede usar break)
        char opc;
        int i, j;
        cout << "\tGRAFOS" << endl;
        while (!flag) {
            cout << "En que posiciones quieres insertar el grafo?" << endl
                 << "Fila\nGrafos# ";
            do {                // validacion para que la relacion este dentro
                fflush(stdin);  // del tamaño de la matriz
                cin >> i;
                if (i > ren)
                    cout << "Insertar de nuevo la Fila\nGrafos# ";
            } while (i > ren);
            cout << "Colunma\nGrafos# ";
            do {                // validacion para que la relacion este dentro
                fflush(stdin);  // del tamaño de la matriz
                cin >> j;
                if (i > ren)
                    cout << "Insertar de nuevo la Columna\nGrafos# ";
            } while (j > col);
            if (selec == 's' || selec == 'S')  // recordar S = dirigido N = NO dirigido
                addDirigido(i - 1, j - 1);     //=== CAMBIO ===//
            else
                addNoDirigido(i - 1, j - 1);  //=== CAMBIO ===//
            while (!flag) {                   // validacoin para que se haya elegido respuesta correcta
                cout << "Deseas insertar mas vercices? S/N\nGrafos# ";
                fflush(stdin);  // si no es una respuesta correcta seguimos entrando
                cin >> opc;     // en el ciclo hasta poner s S n N
                fflush(stdin);
                if (opc == 's' || opc == 'S' || opc == 'n' || opc == 'N')  // si es correcta la eleccion
                    flag = true;                                           // cambiamos la bandera para salir del while
            }                                                              // se puede usar un break tambien
            if (opc == 's' || opc == 'S')                                  // si se desea continuar se resetea
                flag = false;                                              // la bandera para no salirse
            fflush(stdin);
        }
    };
    void imprimir() {
        cout << "    ";                                                 // Formato de impresion para que la matriz tenga
        for (int k = 0; k < ren; k++)                                   // una visivilidad adecuada
            cout << "  " << (char)(k + 65) << ((k < 10) ? "  " : " ");  //=== CAMBIO ===//
        cout << endl;
        for (int i = 0; i < ren; i++) {                                // impresion normal
            cout << " " << (char)(i + 65) << ((i < 10) ? "  " : " ");  //=== CAMBIO ===//
            for (int j = 0; j < col; j++)
                cout << "[ " << matriz[i][j] << " ]";
            cout << endl;
        }
    }
};

int main() {
    bool flag = true;  // bandera de validacion (se puede usar break en su lugar)
    char opc;          // respuesta
    int n;             // tamaño de la matriz cuadrada
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>\n"
         << "Cuantos vertices tiene el grafo?\nGrafos# ";
    cin >> n;
    Grafo grafo(n);  // manda a crear la matriz cuadrara
    fflush(stdin);
    while (flag) {                                      // while para validar que los datos esten insertados de manera correcta
        cout << "Es un grafo Dirigido? S/N\nGrafos# ";  // S = grafo dirigido
        fflush(stdin);                                  // N = grafo NO dirigido
        cin >> opc;
        fflush(stdin);
        if (opc == 's' || opc == 'S' || opc == 'n' || opc == 'N')  // si se da respuesta correcta se sale automaticamente
            flag = false;                                          // del while por hacer la bandera en falsa
    }
    grafo.fill(opc);  // llamado para llenar el grafo, junto con la opcion elegida
    grafo.imprimir();
}
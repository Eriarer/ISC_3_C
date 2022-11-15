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
    Grafo(int n) {
        this->ren = n;
        this->col = n;
        matriz = new int *[ren];
        for (int i = 0; i < ren; i++)
            matriz[i] = new int[col];
        for (int i = 0; i < ren; i++)
            for (int j = 0; j < col; j++)
                matriz[i][j] = 0;
    }
    ~Grafo() {
        for (int i = 0; i < ren; i++)
            delete[] matriz[i];
        delete[] matriz;
    }
    void addNoDirigido(int i, int j) {
        matriz[i][j] = 1;
        matriz[j][i] = 1;
    };
    void addDirigido(int i, int j) {
        matriz[i][j] = 1;
    }
    void fill(char selec) {
        bool flag = false;
        char opc;
        int i, j;
        cout << "\tGRAFOS" << endl;
        while (!flag) {
            cout << "En que posiciones quieres insertar el grafo?" << endl
                 << "Fila\nGrafos# ";
            do {
                fflush(stdin);
                cin >> i;
                if (i > ren)
                    cout << "Insertar de nuevo la Fila\nGrafos# ";
            } while (i > ren);
            cout << "Colunma\nGrafos# ";
            do {
                fflush(stdin);
                cin >> j;
                if (i > ren)
                    cout << "Insertar de nuevo la Columna\nGrafos# ";
            } while (j > col);
            if (selec == 's' || selec == 'S')
                addDirigido(i - 1, j - 1);
            else
                addNoDirigido(i - 1, j - 1);
            while (!flag) {
                cout << "Deseas insertar mas vercices? S/N\nGrafos# ";
                fflush(stdin);
                cin >> opc;
                fflush(stdin);
                if (opc == 's' || opc == 'S' || opc == 'n' || opc == 'N')
                    flag = true;
            }
            if (opc == 's' || opc == 'S')
                flag = false;
            fflush(stdin);
        }
    };
    void imprimir() {
        cout << "    ";
        for (int k = 0; k < ren; k++)
            cout << "  " << (char)(k + 65) << "  ";
        cout << endl;
        for (int i = 0; i < ren; i++) {
            cout << " " << (char)(i + 65) << ((i < 10) ? "  " : " ");
            for (int j = 0; j < col; j++)
                cout << "[ " << matriz[i][j] << " ]";
            cout << endl;
        }
    }
};

int main() {
    bool flag = true;
    char opc;
    int n;
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>\n"
         << "Cuantos vertices tiene el grafo?\nGrafos# ";
    cin >> n;
    Grafo grafo(n);
    fflush(stdin);
    while (flag) {
        cout << "Es un grafo Dirigido? S/N\nGrafos# ";
        fflush(stdin);
        cin >> opc;
        fflush(stdin);
        if (opc == 's' || opc == 'S' || opc == 'n' || opc == 'N')
            flag = false;
    }
    grafo.fill(opc);
    grafo.imprimir();
}
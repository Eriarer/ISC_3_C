#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

class list {
   public:
    class Node {
       public:
        string nom;
        int salario;
        Node *next;
        Node(string nom, int salario) {
            this->nom = nom;
            this->salario = salario;
            this->next = NULL;
        };
    };

   private:
    int tam = 0;
    Node *start, *end;

   public:
    //===============CONSTRUCTOR/DESTRUCTOR=========
    list() { start = end = NULL; };
    ~list() {
        while (start != NULL)
            eliminar();
        delete (start);
        delete (end);
    };
    //=========INSERCIONES========
    void Listinsert(string nom, int salario) {
        Node *aux = new Node(nom, salario);
        if (start == NULL) {
            start = end = aux;
        } else {
            aux->next = start;
            start = aux;
        }
    };
    //==============FUNCIONES=========
    void Listprint() {
        if (start == NULL)
            cout << endl
                 << "Lista vacia";
        else {
            cout << endl;
            Node *aux = start;
            while (aux != NULL) {
                for (int i = 0; i < aux->nom.size(); i++) {
                    if (aux->nom[i] == '_')
                        cout << " ";
                    else
                        cout << aux->nom[i];
                }
                cout << " " << aux->salario << endl;
                aux = aux->next;
            }
        }
        cout << endl;
    };
    void eliminar() {
        if (start->next == NULL)
            start = end = NULL;
        else {
            Node *aux = start;
            start = aux->next;
            delete (aux);
        }
    };
};
int main() {
    cout << endl
         << "\t\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    int sueldo;
    list list1;
    string nom;
    fstream file;
    file.open("file.txt", ios::in);
    while (file >> nom >> sueldo)
        list1.Listinsert(nom, sueldo);
    list1.Listprint();
    file.close();
    return 0;
};
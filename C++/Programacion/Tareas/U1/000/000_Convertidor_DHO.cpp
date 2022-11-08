#include<iostream>

using namespace std;

int main(){
    int opc, valor;
    do{
        system ("cls");
        cout << endl << "1\tDe decimal (10) a octal (8)";
        cout << endl << "2\tDe decimal (10) a hexadecimal (16)";
        cout << endl << "3\tDe octal (8) a decimal (10)";
        cout << endl << "4\tDe octal (8) a hexadecimal (16)";
        cout << endl << "5\tDe hexadecimal (16) a decmimal (10)";
        cout << endl << "6\tDe hexadecimal (16) a octal (8)";
        cout << endl << "7\tSalir";
        cout << endl << "Selecciona tu opcion: ";
        cin >> opc;
        fflush(stdin);
        system ("cls");
        switch (opc)
        {
        default:
            cout << endl << "Selecciona una opcion valida" << "\n\n\n\n";

            system ("pause");
            break;
        
        case (1):
            cout << endl << "\tDe decimal (10) a octal (8)" << endl;
            cout << endl << "Dame un valor en decimal (10): ";
            cin >> dec >> valor; fflush(stdin);
            cout << endl << "El valor octal del numero decimal " << valor << " es: " << oct << valor << "\n\n\n\n";

            system ("pause");
            break;

        case (2):
            cout << endl << "\tDe decimal (10) a hexadecimal (16)" << endl;
            cout << endl << "Dame un valor en decimal (10): ";
            cin >> dec >> valor; fflush(stdin);
            cout << endl << "El valor hexadecimal del numero decimal " << valor << " es: " << hex << valor << "\n\n\n\n";

            system ("pause");
            break;

        case (3):
            cout << endl << "\tDe octal (8) a decimal (10)" << endl;
            cout << endl << "Dame un valor en octal (8): ";
            cin >> oct >> valor; fflush(stdin);
            cout << endl << "El valor decimal del numero octal  " << oct << valor << " es: " << dec << valor << "\n\n\n\n";

            system ("pause");
            break;

        case (4):
            cout << endl << "\tDe octal (8) a hexadecimal (16)" << endl;
            cout << endl << "Dame un valor en octal (8): ";
            cin >> oct >> valor; fflush(stdin);
            cout << endl << "El valor hexadecimal del numero octal  " << oct << valor << " es: " << hex << valor << "\n\n\n\n";
            

            system ("pause");
            break;
        
        case (5):
            cout << endl << "\tDe hexadecimal (16) a decmimal (10)" << endl;
            cout << endl << "Dame un valor en hexadecimal (16): ";
            cin >> hex >> valor; fflush(stdin);
            cout << endl << "El valor decimal del numero en hexadecimal " << hex << valor << " es: " << dec << valor << "\n\n\n\n";

            system ("pause");
            break;
        
        case (6):
            cout << endl << "6\tDe hexadecimal (16) a octal (8)" << endl;
            cout << endl << "Dame un valor en hexadecimal (16): ";
            cin >> hex >> valor; fflush(stdin);
            cout << endl << "El valor decimal del numero en octal " << hex << valor << " es: " << oct << valor << "\n\n\n\n";

            system ("pause");
            break;

        case (7):
            cout << endl << "Saliendon\n\n\n\n";
            system ("pause");
            break;
        }
    }while(opc != 7);
    return 0;
}

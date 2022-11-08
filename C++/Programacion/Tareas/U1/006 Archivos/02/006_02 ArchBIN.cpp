#include<fstream>
#include<iostream>
#include<cstdlib>
#include<conio.h>

using namespace std;

struct Tproducto{
    int codigo;
    char descripcion[100];
    float precio;
    int noarticulos;
};

void alta();
void conGral();
void conProd();
void venta();
void bajaL();
void bajaF();

int main(){
    int opc;
    do{
        system("cls");
        cout << "1...Alta" << endl;
        cout << "2...Consulta" << endl;
        cout << "3...Busqueda por producot" << endl;
        cout << "4...Venta de producto" << endl;
        cout << "5...Baja logica" << endl;
        cout << "6...Baja fisica" << endl;
        cout << "9...salir" << endl;
        cout << endl << "OPCION: ";
        cin  >> opc; cin.ignore();

        switch(opc){
            case 1:
                alta();
                cout << endl << "Datos almacenados" << endl;
                cout << "\n\n\tPRESIONE PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
                break;
            case 2:
                conGral();
                cout << "\n\n\tPRESIONE PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
                break;
            case 3:
                conProd();
                cout << "\n\n\tPRESIONE PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
                break;
            case 4:
                venta();
                cout << endl << "Productos vendidos" << endl;
                cout << "\n\n\tPRESIONE PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
                break;
            case 5:
                bajaL();
                cout << endl << "Dado de baja" << endl;
                cout << "\n\n\tPRESIONE PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
                break;
            case 6:
                bajaF();
                cout << endl << "Dado de baja" << endl;
                cout << "\n\n\tPRESIONE PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
                break;        
            case 9:
                cout << "\tHasta luego" << endl;
                cout << "\n\n	TEXT" <<endl; _getch(); //Pausa (needs conio.h)
                break;
            default:
                cout << "Seleccione una opcion correcta" << endl;
                cout << "\n\n\tPRESIONE PARA CONTINUAR" <<endl; _getch(); //Pausa (needs conio.h)
        }
    }while(opc!=9);

}

void alta(){
    fstream archivo;
    archivo.open("productos.dat", ios::binary | ios::out | ios::ate | ios::app);
    if(!archivo){
        system("cls");
        cout<< endl << "\tFATAL ERROR" << endl;
        cout << "\n  PRESS ANY KEY TO EXIT" <<endl; _getch(); //Pausa (needs conio.h)
        exit(0);
    }
    Tproducto producto;
    int op;
    do{
        
        system("cls");
        cout << endl << "\tLLENADO DE PRODUCTO" << endl << endl;
        cout << "[INSERTA 0 PARA SALIR]" << endl << "Codigo: ";
        cin >> producto.codigo;
        if(producto.codigo==0){
            goto exit;
        }
        cout << "Descripcion: ";
        cin >> producto.descripcion;
        cout << "Precio: ";
        cin >> producto.precio;
        cout << "No. de articulos disponiblos: ";
        cin >> producto.noarticulos;
        archivo.write(reinterpret_cast<char *>(&producto), sizeof(Tproducto));
        cout << endl << "HACER OTRA ALTA Y(1)/N(2): ";
        cin >> op;
    }while (op==1);
    exit:
    archivo.close();
}

void conGral(){
    fstream archivo;
	archivo.open("productos.dat",ios::binary|ios::in);
	if(!archivo) {
		cout<<"Error de apertura de archivo"<<endl;
		system("pause");
		exit(0);
	}
	Tproducto prod, blanco = {0, " ", 0, 0};
	int i,c=0,op;
	while(!archivo.eof()) {
		archivo.read(reinterpret_cast<char *>(&prod), sizeof(Tproducto));
		c++;
	}
	c--;
	archivo.clear();
	archivo.seekg(0);
	for(i=0; i<c; i++) {
		archivo.read(reinterpret_cast<char *>(&prod), sizeof(Tproducto));
        if(prod.codigo != blanco.codigo){
            cout<<endl;
		    cout<<"Codigo: "<<prod.codigo<<endl;
		    cout<<"Descripcion: "<<prod.descripcion<<endl;
		    cout<<"No articulos: "<<prod.noarticulos<<endl;
		    cout<<"Precio: "<<prod.precio<<endl;
        }		
	}
	archivo.close();
}

void conProd(){
    fstream archivo;
	archivo.open("productos.dat",ios::binary|ios::in);
	if(!archivo) {
		cout<<"Error de apertura de archivo"<<endl;
		system("pause");
		exit(0);
	}
	Tproducto producto, blanco = {0, " ", 0, 0};
	int i,c=0,op, codigo=1;
    
    while(codigo!=0){
        cout << endl << "Inserte el codigo de producto que se desee buscar" << endl << "[0 para salir]\nCodigo: ";
        cin >> codigo; fflush(stdin);
        archivo.clear();
	    archivo.seekg(0);
	    while(!archivo.eof()){
	    	archivo.read(reinterpret_cast<char *>(&producto), sizeof(Tproducto));
	    	c++;
        }
	    c--;
	    archivo.clear();
	    archivo.seekg(0);
	    for(i=0; i<c; i++) {
		    archivo.read(reinterpret_cast<char *>(&producto), sizeof(Tproducto));
            if(producto.codigo != blanco.codigo && producto.codigo == codigo){
                cout<<endl;
		        cout<<"Codigo: "<<producto.codigo<<endl;
		        cout<<"Descripcion: "<<producto.descripcion<<endl;
		        cout<<"No articulos: "<<producto.noarticulos<<endl;
		        cout<<"Precio: "<<producto.precio<<endl;
            }		
	    }
    }
	archivo.close();
}

void venta(){
	fstream archivo;
	archivo.open("productos.dat",ios::binary|ios::in|ios::out);
	if(!archivo){
		cout<<"Error de apertura de archivo"<<endl;
		system("pause");
		exit(0);
	}
	Tproducto producto;
	int codigo,c=0,np,op;
	bool bandera=false;
	float vta=0,vtaT=0;
	cout<<"Codigo del producto: ";
	cin>>codigo;
	do{
	c=0;
	archivo.seekg(0);
	bandera=false;
	while(!archivo.eof()&& bandera==false){
		archivo.read(reinterpret_cast<char *>(&producto), sizeof(Tproducto));
		c++;
		if(producto.codigo==codigo){
			cout<<endl<<"No de productos: ";
			cin>>np;
			if(np<=producto.noarticulos){
				vta=np*producto.precio;
				vtaT=vtaT+vta;
				producto.noarticulos=producto.noarticulos-np;
				cout<<"Quedan "<<producto.noarticulos<<" articulos"<<endl;
				c--;
				archivo.seekp(c*sizeof(Tproducto),ios::beg);
				archivo.write(reinterpret_cast<char *>(&producto), sizeof(Tproducto));
				bandera=true;
			}else{
				cout<<endl<<"Productos insuficientes"<<endl;
				bandera=true;
			}
		}
	}
	if(!bandera)
		cout<<endl<<"Producto no existente"<<endl;
	cout<<"[0 para salir]\nCodigo del producto: ";
	cin>>codigo;
	}while(codigo!=0);
	cout<<endl<<"Total a pagar: "<<vtaT<<endl;
	archivo.close();
}

void bajaL(){
    fstream archivo;
    archivo.open("productos.dat", ios::binary | ios::in | ios::out);
    if(!archivo){
        cout << endl <<  "\tFATAL ERROR" << endl;
        cout << "\nPRESS TO EXIT" <<endl; _getch(); //Pausa (needs conio.h)
        exit(0);
    }
    Tproducto producto,blanco={0, " ", 0, 0};
    int codigo, c=0;
    bool flag = false;
    cout << "Codigo del producto a dar de baja: ";
    cin >> codigo; fflush(stdin);
    do{
        c=0;
        flag = false;
        archivo.clear();
        archivo.seekg(0);
        while (!archivo.eof()&& flag==false){
            archivo.read(reinterpret_cast<char *>(&producto), sizeof(Tproducto));
            c++;
            if(producto.codigo==codigo){
                c--;
                cout << "Se encontro el producto, dando de baja..." << endl;
                flag = true;
                archivo.seekp(c*sizeof(Tproducto));
                archivo.write(reinterpret_cast<char *>(&blanco), sizeof(Tproducto));
            }
        }        
        cout << "[0 para salir] Codigo del producto a dar de baja: ";
        cin >> codigo; fflush(stdin);
        cout << endl;
    }while(codigo!=0);
    archivo.close();
}

void bajaF(){
    fstream archivo;
    fstream bajas;
    archivo.open("productos.dat", ios::binary | ios::in);
    bajas.open("bajas.tmp", ios::binary | ios::out);
    if(!archivo || !bajas){
        cout << endl <<  "\tFATAL ERROR" << endl;
        cout << "\nPRESS TO EXIT" <<endl; _getch(); //Pausa (needs conio.h)
        exit(0);
    }
    Tproducto producto, blanco={0, " ", 0, 0};
    int codigo, c=-1;
    cout << "[0 para eliminar bajas logicas]" << endl << "Codigo del producto a dar de baja: ";
    cin >> codigo; fflush(stdin);
    do{
        archivo.clear();
        bajas.clear();
        archivo.seekg(0);
        bajas.seekg(0);
        bajas.seekp(0);
        c=-1;
        while (!archivo.eof()){
            archivo.read(reinterpret_cast<char *>(&producto), sizeof(Tproducto));
            c++;
            if(producto.codigo != codigo && producto.codigo != blanco.codigo){
                if(!archivo.eof()){
                    archivo.seekp(c*sizeof(Tproducto));
                    archivo.read(reinterpret_cast<char *>(&producto), sizeof(Tproducto));
                    bajas.write(reinterpret_cast<char *>(&producto), sizeof(Tproducto));
                }
            }
        }
        if(codigo!=0){
            cout << "[0 para salir]" << endl << "Codigo del producto a dar de baja: ";
            cin >> codigo; fflush(stdin);
        }
    }while(codigo!=0);
    archivo.close();
    bajas.close();
    remove("productos.dat");
    rename("bajas.tmp", "productos.dat");
    
}
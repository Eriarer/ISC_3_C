#include<iostream>
#include<time.h>

using namespace std;

class list{
public:
    class Node{
        public:
            int num;
            Node *next;
            Node(int num){
                this->num = num;
                this->next = NULL;
            };
    };
private:
    Node *start, *end;
public:
    list(){start = end = NULL;};
    //==============CREAR/LLENAR=========
    void createlist();
    void copyList(list &);
    //=========INSERCIONES========
    void insertStart(int);
    void insertEnd(int);
    //=========ELIMINACIONES=========
    void delStart();
    //==============FUNCIONES=========
    void Listprint();
    void fillList(int);
    
};
//==============CREAR/LLENAR=========
void list::createlist(){
    while (start!=NULL)
        delStart();
    int tam =rand()%20+9;
    fillList(tam);
}; 
void list::copyList(list &obj){
    while (start!=NULL)
        delStart();
    Node *aux = obj.start;
    while(aux!=NULL){
        this->insertEnd(aux->num);
        aux = aux->next;
    }
};
//=========INSERCIONES==========
void list::insertStart(int n){
    Node *aux;
    aux = new Node(n);
    if(start == NULL)
        start = end = aux;
    else{
        aux->next = start;
        start = aux;
    }
};
void list::insertEnd(int n){
    Node *aux;
    aux = new Node(n);
    if(start == NULL)
        start = aux;
    else
        end->next = aux;
    end = aux;
};
//=========ELIMINACIONES==========
void list::delStart(){
    if(start->next==NULL || start == end){
        delete start;
        start = end = NULL;
    }else{
        Node *aux = start;
        start = aux->next;
        delete aux;
    }
};
//==============FUNCIONES=========
void list::Listprint(){
    if(start==NULL)
        cout << endl << "Lista vacia";
    else{
        cout << endl;
        Node *aux = start;
        cout << "\t[ ";
        while(aux!=NULL){
            cout << aux->num;
            if(aux->next!=NULL)
                cout <<" - ";
            aux = aux->next;
        }
        cout << " ]";
    }
    cout << endl;
};
void list::fillList(int tam){
    srand(time(NULL));
    int num=0;
    for(int i=0;i<tam;i++){
        insertStart((rand()%900+101));
    }
}
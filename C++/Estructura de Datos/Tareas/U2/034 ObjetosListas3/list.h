#include<iostream>
#include<algorithm>

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
    int *vec=NULL;
    int tam=0;
    Node *start, *end;
    //==============FUNCIONES=========
    void quick(int ,int);
    void sortVec();
    //=========INSERCIONES========
    void insertEnd(int);
    //=========ELIMINACIONES=========
    void delStart();
public:
    //===============CONSTRUCTOR/DESTRUCTOR=========
    list(){start = end = NULL; vec = (int*)calloc(tam,sizeof(int));};
    ~list(){delete start; delete end;  free(vec);};
    //=========INSERCIONES========
    void insertStart(int);
    //==============FUNCIONES=========
    void Listprint();
    int listlen();
    void Listsort();
    //=========GETS==========
    int gettam();
};
//------------------PUBLICO------------------
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
//==============FUNCIONES=========
void list::Listprint(){
    if(start==NULL)
        cout << endl << "Lista vacia";
    else{
        cout << endl;
        Node *aux = start;
        cout << "  [ ";
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
int list::listlen(){
    tam = 0;
    Node *aux = start;
    while (aux!=NULL){
        aux = aux->next;
        tam++;
    }
    tam++;
    return tam;
};
void list::Listsort(){
    sortVec();//Se manda a obtener y ordenar el vctor
    while(start!=NULL)//se elimina lo que se tenga en la lista
        delStart();
    for(int i=0; i<gettam()-1;i++){//se inserta el vector ordenado
        insertEnd(vec[i]);
    }
};
//=========GETS==========
int list::gettam(){
    if(tam==0)
       tam = listlen();
    return tam;
}
//------------------PRIVADO------------------
//=========INSERCIONES==========
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
void list::sortVec(){
    vec = (int*)realloc(vec,gettam());//Se obiene el vector de la lista
    int i=0,tam=gettam()-1;
    Node *aux=start;
    while(aux!=NULL){
        vec[i] = aux->num;
        aux = aux->next;
        i++;
    }
    sort(vec, vec+gettam()-1);
    //POR ALGUNA RAZON DEJO DE FUNCIONAR si encuentra el error porfavor digame
    //Funcionaba a la perfeccion... los errores de C son sorprendentes
    /*if(tam<=2){
        if(tam == 2){
            if(vec[0]>vec[1]){
                int temp=vec[1];
                vec[1] = vec[0];
                vec[0] = temp;
            }
        }        
    }else
        quick(0, tam);//se manda a ordenar QUICK SORT*/
};
void list::quick(int min,int max){
    int i=min,
        j=max,
        half=vec[(i+j)/2],
        temp=0;
    
    do{
        while(vec[i] < half && i < max)
            i++;
        while(vec[j] > half && j> min)
            j--;
        if(i<=j){
            temp = vec[i];
            vec[i] = vec[j],
            vec[j] = temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(min < j)
       quick(min, i-1);
    if(i < max)
       quick(i+1,max);
};
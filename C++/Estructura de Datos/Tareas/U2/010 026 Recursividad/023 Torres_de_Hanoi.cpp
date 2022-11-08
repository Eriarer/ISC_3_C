#include<iostream>
#include<conio.h>

using namespace std;
void hanoi(int, char, char, char);

int main(){
    cout << "\t<ABRAHAM MELGOZA DE LA TORRE>" << endl;
    char a='A', b='B', c='C';
    hanoi(4,a,b,c);
    return 0;
}

void hanoi(int n, char a, char b, char c){
    if(n==1)
        cout << endl << "Disco " << n << " " << a << "->" << c;
    else{
        hanoi(n-1,a,c,b);
        cout << endl << "Disco " << n << " " << a << "->" << c;
        hanoi(n-1,b,a,c);
    }
};
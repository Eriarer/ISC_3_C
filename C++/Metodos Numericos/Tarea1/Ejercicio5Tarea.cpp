#include<iostream>
#include<iomanip>
#include<conio.h>

using namespace std;

int main(){
    float x=0, y=1, z=0;
    cout << "X value: ";
    cin >> x; fflush(stdin);
    z= ((x+y)*(x+y)-(2*x*y)-(y*y))/(x*x);
    cout << endl << z;
    return 0;
}

#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    double pi=3.143241;
    char a[20]={'H','o','l','a',' ','C','o','m','o',' ','E','s','t','a','s'};
    cout<<"\t\t<Abraham Melgoza de la Torre>"<<endl;
    cout << setprecision(3) << setiosflags(ios::uppercase);
    cout << a << " " << pi << endl;

    return 0;
}
#include <iostream>
using namespace std;

int DegerArttir(){
    static int sayac=0; // Statik bellek b�lgesinde
    return ++sayac;
}
int topla(int a,int b){
      int sonuc = a+b;  // �al��ma an� y���n�nda
      return sonuc;
}
int main(){
     cout<<DegerArttir()<<endl;
     cout<<DegerArttir()<<endl;
     cout<<topla(21,10)<<endl;
	 cout<<topla(5,7)<<endl;
     return 0;
}

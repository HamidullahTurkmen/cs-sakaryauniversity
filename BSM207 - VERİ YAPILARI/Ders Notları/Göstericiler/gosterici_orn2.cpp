#include <iostream>
using namespace std;

int main(){
	int *p;
	int a=12;
	p=&a;

	cout<<*p<<endl;        // G�sterdi�i yerdeki de�eri yaz
	cout<<p<<endl;          // G�sterdi�i yerin bellek adresi
	cout<<&p<<endl;      // G�stericinin kendi bulundu�u adres
	cout<<&a<<endl;      // a de�i�kenin bulundu�u adres.
}

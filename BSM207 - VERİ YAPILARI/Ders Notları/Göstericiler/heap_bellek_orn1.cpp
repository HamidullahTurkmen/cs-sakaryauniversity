#include <iostream>
using namespace std;

int main(){
	// Adresi heap bellek b�lgesinde
	string *isimp = new string; 

	// Adresi yok.
	string *adp;
	
	cout<<*isimp<<endl;
	cout<<*adp<<endl;  // �al��t�ktan sonra hata verir ��nk� g�sterdi�i bir yer yok veya anlams�z bir yeri g�steriyor.
	return 0;
}
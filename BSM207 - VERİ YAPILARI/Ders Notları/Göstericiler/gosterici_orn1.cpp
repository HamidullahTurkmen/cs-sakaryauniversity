#include <iostream>
using namespace std;

int main(){
	int x=10;
	int *p;
	p=&x;  // x de�i�kenin adresini tut
	x++;
	cout<<*p; 
}

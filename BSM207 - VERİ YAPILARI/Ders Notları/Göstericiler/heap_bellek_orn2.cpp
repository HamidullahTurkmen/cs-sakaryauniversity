#include <iostream>
using namespace std;

class Kisi{
	private:
		string adi;
	public:
		Kisi(string ad):adi(ad){ }
};
class Arac{
	private:
		Kisi *surucu;
		float hiz;
		
	public:
		Arac(string surucuAdi,float hz){    // Yap�c� fonksiyon 
				surucu = new Kisi(surucuAdi);
				hiz=hz;
			}
		~Arac()   // Y�k�c� fonksiyon.
		{
			delete surucu;
		}
};

int main()
{
	Arac *a = new Arac("Mehmet",75);
	delete a;
	return 0;
}

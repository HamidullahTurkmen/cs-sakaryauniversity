/*******************************************************************************************************************************************************/
/*                                                          SAKARYA �N�VERS�TES� */
/*                                                 B�LG�SYAR VE B�L���M B�L�MLER� FAK�LTES�*/
/*                                                       B�LG�SAYAR M�HENDS�L��� B�L�M�*/
/*                                                          PROGRAMLAMAYA G�R�� DERS�*/
/*                                                                   2. �DEV*/
/*                                                                BEYZANUR DEM�R  */
/*                                                                  G161210045*/
/*                                                                  C GURUBU*/
/*******************************************************************************************************************************************************/



#include<iostream
#include<time.h>
using namespace std;
int main()
{
	int diziBoyut;
	char karakter = 0;
	int sira = 0;
	int*dizi;

	cout << "Dizi boyutunu giriniz: ";
	cin >> diziBoyut;
	dizi = new int[diziBoyut];
	do      //dizinin devaml�l���n� sa�l�yor
	{
		system("cls"); //ekran�n temzilenmesini sa�l�yor
		for (int i = 0; i < diziBoyut; i++)
		{
			int bosluk = 4;
			if (sira == i)
			{
				cout << "--->";
				bosluk = 0;
			}
			srand(time(0);
			dizi[i] = rand() % 10;   //diziye rastgele eleman atan�yor
			for (int j = 0; j < bosluk; j++)
			{
				cout << " ";
			}

			cout << dizi[i] << endl;

			if (karakter == 'a' || karakter == 'A') //karakter kontrol� yap�lyor
			{
				i++;
			}

			else if (karakter == 'd' || karakter == 'D')
			{
				i--;
			}
			
		}
		

		
	} while (karakter == 'c');

	system("pause");
	return 0;
}
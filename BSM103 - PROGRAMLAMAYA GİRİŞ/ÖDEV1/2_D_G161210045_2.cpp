/******************************************************************************************************************************************/
//                                               SAKARYA �N�VERS�TES�
//                                    B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
//                                         B�LG�SAYAR M�HEND�SL��� B�L�M�
//                                            PROGRAMLAMAYA G�R�� DERS� 
//                                                    G161210045
//                                                  BEYZANUR DEM�R
//                                                    1. �DEV
//                                                     D GRUBU
/******************************************************************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
	int girilena, girilenb;
	cout << "1 ile 20 arasinda bir a tam sayi degeri giriniz=";
	cin >> girilena;
	cout << "1 ile 20 arasinda a dan kucuk olacak sekilde bir b tam sayi degeri giriniz=";
	cin >> girilenb;

	{
		for (int x = 1;x <= 20;x++)  //ilk sat�r i�in d�ng� d�n�yor.20 de�er atan�yr
		{
			if (x <= (girilenb - 1) + (girilena - girilenb + 1))  //ilk sat�rda 2. ve 3. sat�rdaki y�ld�z say�s� de�erince bo�luk bas�l�yor
			{
				cout << " ";
			}
			else     //kalan durumlarda y�ld�z bas�l�yor
				cout << "*";
		}
		cout << endl;
		for (int x = 1;x <= 20;x++) //ikinci sat�r i�in d�ng� d�n�yor

			if (x <= girilenb - 1) //3. sat�rdaki y�ld�z de�erince bo�luk bas
			{
				cout << " ";
			}

			else if (x > girilenb - 1 && x <= girilena)  //girilenb-1 de�erinden b�y�kse ve girilena de�erinden k���k e�itse y�ld�z bas
				cout << "*";


		cout << endl;
		for (int x = 1;x <= 20;x++)   //3.sat�r i�in d�ng� d�n�yor
		{
			if (x <= girilenb - 1)   //girilenb de�erinden k���k say�lar i�in y�ld�z bas�l�yor
			{
				cout << "*";
			}
			else      //1. ve 2. sat�rdaki y�ld�z say�s� kadar bo�luk b�rak�l�yor
				cout << " ";
		}

	}

	system("pause");
	return 0;
}

/******************************************************************************************************************************************/
/**                                           SAKARYA �N�VERS�TES�                                                                        
/** 								B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
/** 								    B�LG�SAYAR M�HEND�SL��� B�L�M�
/** 										PROGRAMLAMAYA G�R�� DERS�
/** 											  G161210045
/** 											BEYZANUR DEM�R
/** 											   1.�DEV
/** 											   D GRUBU
/******************************************************************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
	for (int i = 0; i < 24; i++) // en �st k�s�mdaki y�ld�zlar bast�r�l�yor
	{
		cout << " * ";
	}
	cout << "\n";
	cout << " *  S  A  U     B  I  L  G  I  S  A  Y  A  R                          *\n";
	for (int k = 0; k < 24; k++) // 3. sat�r bast�r�l�yor
	{
		if (k == 0 || k == 23) cout << " * ";  // 3. sat�r�n birinci s�tunundaysan ya da son s�tunundaysan y�ld�z bas
		else cout << "   ";    //arada kalan di�er s�tunlarda bo�luk bas
	}
	cout << "\n";
	int buyukUcgenBosluk = 5; // 4. sat�r i�in iki ��gen de 5 bo�luk 1 y�ld�z �eklinde ba�l�yor
	for (int i = 0; i < 6; i++) //��geni olu�turmak i�in d�ng�y� 6 defa d�nd�r�r
	{
		cout << " * ";
		for (int j = 0; j < 11; j++) // �st sol b�y�k ��gen i�in d�ng� d�n�yor
		{
			if (j >= buyukUcgenBosluk && j < (11 - buyukUcgenBosluk)) // Her sat�r i�in birer azalan bo�luk say�sndan b�y�k veya e�itse ve 11-azalan bo�luk say�s� de�erinden k���kse
			{
				cout << " * "; //Y�ld�z bas
			}
			else  //kalan durumlar i�in bo�luk bas
				cout << "   ";
		}
		for (int j = 0; j < 11; j++) // �st sa� b�y�k ��gen i�in d�n�yor
		{
			if (j >= buyukUcgenBosluk && j < (11 - buyukUcgenBosluk))
			{
				cout << " * ";
			}
			else if (i == 0 && j >= 8) // b�y�k ��genin i�indeki k���k ��genin �st k�sm� i�in 
				cout << " * ";
			else if (i == 1 && j == 9) // b�y�k ��genin i�indeki k���k ��genin alt k�sm� i�in
				cout << " * ";
			else
				cout << "   ";
		}
		cout << " * ";
		cout << "\n";
		buyukUcgenBosluk -= 1;
	}
	for (int k = 0; k < 24; k++) //10. sat�r i�in d�ng� d�n�yor
	{
		if (k == 0 || k == 23)    //10. sat�r�n ba��nda ve sonundaysan y�ld�z bas
			cout << " * ";
		else    //aradaki s�tunlarda bo�luk bas
			cout << "   ";
	}
	cout << "\n";
	cout << " *  M  U  H  E  N  D  I  S  L  I  G  I     B  O  L  U  M  U           *\n";
	for (int k = 0; k < 24; k++)     // 12. sat�r i�in d�ng� d�n�yor
	{
		if (k == 0 || k == 23)   //12. sat�r�n 1.s�tununda ya da son s�tununda isen y�ld�z bas
			cout << " * ";
		else                   //di�er s�t�nlarda bo�luk bas
			cout << "   ";
	}
	cout << "\n";
	buyukUcgenBosluk = 5;
	for (int i = 0; i < 6; i++)
	{
		cout << " * ";
		for (int j = 0; j < 11; j++) // Sol alt b�y�k ��gen i�in
		{
			if (j >= buyukUcgenBosluk && j < (11 - buyukUcgenBosluk)) // Her sat�r i�in birer azalan bo�luk say�sndan b�y�k veya e�itse ve 11-azalan bo�luk say�s� de�erinden k���kse
			{
				cout << " * ";  //y�ld�z bas
			}
			else if (i == 0 && j >= 8)  // b�y�k ��genin i�indeki k���k ��genin �st k�sm� 
				cout << " * ";
			else if (i == 1 && j == 9) // b�y�k ��genin i�indeki k���k ��genin alt k�sm�
				cout << " * ";
			else
				cout << "   ";
		}
		for (int j = 0; j < 11; j++) // Sa� alt b�y�k ��gen i�in
		{
			if (j >= buyukUcgenBosluk && j < (11 - buyukUcgenBosluk)) // Her sat�r i�in birer azalan bo�luk say�sndan b�y�k veya e�itse ve 11-azalan bo�luk say�s� de�erinden k���kse
			{
				cout << " * ";  //y�ld�z bas
			}
			else  //di�er durumlarda bo�luk bas
				cout << "   ";
		}
		cout << " * ";
		cout << "\n";
		buyukUcgenBosluk -= 1;
	}
	for (int k = 0; k < 24; k++) // 19. sat�r i�in d�ng� d�n�yor
	{
		if (k == 0 || k == 23)  //19. sat�r�n ba��nda veya sonunda isen y�ld�z bas
			cout << " * ";
		else  //aradaki s�tunlarda bo�luk bas
			cout << "   ";
	}
	cout << "\n";
	for (int i = 0; i < 24; i++) // en alt k�s�mdaki y�ld�zlar�n bas�m� i�in d�ng� d�n�yor
	{
		cout << " * ";
	}
	system("pause");
	return 0;
}

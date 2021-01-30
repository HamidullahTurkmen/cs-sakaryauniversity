/**********************************************************************************************************************************************/
/*                                                    SAKARYA �N�VERS�TES�                                                                    */
/*                                           B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�                                                        */
/*                                                B�LG�SAYAR M�HEND�SL��� B�L�M�                                                             */
/*                                                 PROGRAMLAMAYA G�R�� DERS�                                                                 */
/*                                                          4.�DEV                                                                             */
/*                                                         G161210045                                                                          */
/*                                                       BEYZANUR DEM�R                                                                         */
/*                                                          D GRUBU                                                                            */
/*********************************************************************************************************************************************/
#include<iostream>
#include<time.h>
#include<iomanip>

using namespace std;
void Olustur(int matris[10][10]);
void sirala(int matris[10][10]);
void MatrisYaz(int matris[10][10]);
bool ElemanKontrol matris[10][10];
int main()
{
	int k,sayac = 0;
	int matris[10][10];
	k = rand() % 100 + 1;
	srand(time(0));
	for (int i = 0; i < 10; i++)  //matrisin sat�r� tan�mlan�yor
	{
		for (int j = 0; j < 10; j++) //matrisin s�tunu tan�mlan�yor
		{
			if (ElemanKontrol() == true)
			{
				k= rand() % 100 + 1;
				j = j - 1;
				sayac++;
			}
			else
			{
				matris[i][j] =k;
			}
			
		}

	}
	
	Olustur(matris);
	cout << "rand () kac defa cagr�ld�: " << sayacc;
	sirala(matris);
	MatrisYaz(matris);
	system("pause");
	return 0;
}
void Olustur(int matris[10][10])
{
	for (int i = 0; i < 10; i++)  //matrisin sat�r� yazd�r�l�yor
	{
		for (int j = 0; j < 10; j++) //matrisin s�tunu yazd�r�l�yor
		{
			cout << setw(5) << matris[i][j];
		}
		cout << endl;
	}
}
void sirala(int matris[10][10])
{	
	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 10; column++)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = i; j < 10; j++)
				{
					if (matris[row][i] < matris[row][j])
					{
						int temp = matris[row][j];
						matris[row][i] = matris[row][j];
						matris[row][j] = temp;
					}
					if (matris[i][column] < matris[j][column])
					{
						int temp = matris[i][column];
						matris[i][column] = matris[j][column];
						matris[j][column] = temp;

					}
				}
			}
		}
	}
}
void MatrisYaz(int matris[10][10])
{
	cout << "Buyukten kucuge siralanmis matris" << endl;
	for (int i = 0; i < 10; i++)	
	{
		for (int j = 0; j < 10; j++)
		{
			cout << setw(5) << matris[i][j];
		}
		cout << endl;
	}
	
}
bool ElemanKontrol(matris[10][10]) 
{

	for (int i = 0; i<10; i++)

	{
		for (int j = 0; j<10; j++)
		{
			if (Matris[i][j] == k)
			{
				return true;
				break;
			}

		}

	}
	return false;
}





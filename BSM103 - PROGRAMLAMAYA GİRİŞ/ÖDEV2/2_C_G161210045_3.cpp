/**************************************************************************************************************************************************************/
/*                                                        SAKARYA �N�VERS�TES�                                                                                */
/*                                             B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�                                                                      */
/*                                                 B�LG�SAYAR M�HEND�S�L��� B�L�M�                                                                            */
/*                                                   PROGRAMLAMAYA G�R�� DERS�                                                                                */
/*                                                             2. �DEV                                                                                        */
/*                                                         BEYZANUR DEM�R                                                                                     */
/*                                                            G161210045                                                                                      */
/*                                                             C GRUBU                                                                                        */
/**************************************************************************************************************************************************************/
#include<iostream>
#include<math.h>
using namespace std;
int main ()
{
	int a, b, c;
	float delta, x1, x2;
	cout << "ax2 + bx +c 'de a degerinia giriniz= ";
	cin >> a;

	cout << "ax2 + bx +c'de b degerinia giriniz=  ";
	cin >> b;

	cout << "ax2 + bx +c'de a degerinia giriniz=  ";
	cin >> c;


	delta=(float) b*b- 4*a*c;
	cout << "delta=" << delta << endl;


	if (delta < 0)   //deltan�n negatif oldu�u durumlarda
	{
		cout << "Reel kok yoktur" << endl;
	}
	else if (delta>0) //delat�n�n pozitif oldu�u durumlarda
	{
		cout << "iki reel koku vardir" << endl;
		x1 =(float) (-b - sqrt(delta)) / 2*a;
		x2 =(float) (-b + sqrt(delta)) / 2*a;
		cout << "kok1=" << x1 << endl;
		cout << "kok2=" << x2 << endl;
	}
	else if (delta=0) //delta�n�n s�f�r oldu�u durumlarda
	{
		cout << "Cak�s�k iki kok vardir" << endl;
		x1 = (float)(-b / 2 * a);
		x2 = (float) x1;
		cout << "kok1 ve kok2" << x1<< endl;
		
	}


	system("pause");
	return(0);
}
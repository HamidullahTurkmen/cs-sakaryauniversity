/**********************************************************************************************************************************************************************/
/*                                                           SAKARYA �N�VERS�TES�                                                                                     */
/*                                                B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�                                                                           */
/*                                                     B�LG�SAYAR M�HEND�S�L��� B�L�M�                                                                                */
/*                                                          PROGRAMLAMAYA G�R�� DERS�                                                                                 */
/*                                                                 2.�DEV                                                                                             */
/*                                                             BEYZANUR DEM�R                                                                                         */
/*                                                               G161210045                                                                                           */
/*                                                                C GRUBU                                                                                           */
/**********************************************************************************************************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int vize,odev1,vizenot, odev, quiz, odev2, quiz1, quiz2, final, finalnot, vizeyuzde, odevyuzde, quizyuzde, yilicipyuzde, toplamp, yilicinot, yilsonup;

	do  // 100'den b�y�k bir vize notu girilmemesini kontrol etmek i�in 
	{
		cout << "vize notunuzu giriniz";
		cin >> vizenot;
	} while (vizenot > 100);
	
	do  //100 den b�y�k bir  odev notu girilmemesini kontrol etmek i�in 
	{
		cout << "1.odev notunuzu giriniz";
		cin >> odev1;
	} while (odev1 > 100);

	do //100 den b�y�k bir  odev notu girilmemesini kontrol etmek i�in 
	{
		cout << "2.odev notunuzu giriniz";
		cin >> odev2;
	} while (odev2 > 100);

	do //100 den b�y�k bir quiz notu girilmemesini kontrol etmek i�in 
	{
		cout << "1.quiz notunuzu giriniz";
		cin >> quiz1;
	} while (quiz1 > 100);

	do //100 den b�y�k bir quiz notu girilmemesini kontrol etmek i�in 
	{
		cout << "2.quiz notunuzu giriniz";
		cin >> quiz2;
	} while (quiz2 > 100);

	do //100 den b�y�k bir final notu girilmemesini kontrol etmek i�in 
	{
		cout << "final sinavi notunuzu giriniz";
		cin >> finalnot;
	} while (finalnot > 100);

	do  /*100 den b�y�k bir vize y�zdesi girilmemesini kontrol etmek i�in ve
	    yil i�ine y�zde toplam�n�n 100'den b�y�k olmamas�n� kontrol etmek i�in*/
	{
		cout << "vizenin yil icine etkisi yuzde kac olacaktir?";
		cin >> vizeyuzde;
	} while (vizeyuzde > 100);

	do /*100 den b�y�k bir �dev y�zdesi girilmemesini kontrol etmek i�in ve
	    yil i�ine y�zde toplam�n�n 100'den b�y�k olmamas�n� kontrol etmek i�in*/
	{
		cout << "Odevlerin yil icine etkisi yuzde kac olacaktir?";
		cin >> odevyuzde;
	} while (odevyuzde > 100-vizeyuzde || odevyuzde==100-vizeyuzde);

	do /*100 den b�y�k bir quiz y�zdesi girilmemesini kontrol etmek i�in ve
	    yil i�ine y�zde toplam�n�n 100'den b�y�k olmamas�n� kontrol etmek i�in*/
	{
		cout << "quizlerin yil icine etkisi yuzde kac olacaktir";
		cin >> quizyuzde;
	} while (quizyuzde > 100-(vizeyuzde+odevyuzde));

	do  //100'den b�y�k bir yil i�i puan y�zdsi girilmemesini kontrol etmek i�in
	{
		cout << "Yil ici puaninin etkisi yuzde kac olacaktir?";
		cin >> yilicipyuzde;
	} while (yilicipyuzde > 100);
	


	
	vize = (vizenot*vizeyuzde) / 100;
	odev = ((odev1 + odev2)/ 2)*odevyuzde / 100;
	quiz = ((quiz1 + quiz2)/ 2)*quizyuzde / 100;
	toplamp = vize + odev + quiz;
	yilicinot = (toplamp*yilicipyuzde) / 100;
	final = (100 - yilicipyuzde)*finalnot / 100;
	yilsonup = yilicinot + final;



	if (yilsonup >= 90)  //al�nan notlara g�re harf aral�klar� belirlendi.
	{
		cout << "AA aldiniz" << setw(5)<< yilsonup << endl;
	}

	else if (yilsonup >= 85)
	{
		cout << "BA aldiniz" << setw(5) << yilsonup << endl;
	}
	else if (yilsonup >= 80)
	{
		cout << "BB aldiniz" << setw(5) << yilsonup << endl;
	}
	else if (yilsonup >= 75)
	{
		cout << "CB aldiniz" << setw(5) << yilsonup << endl;
	}
	else if (yilsonup >= 65)
	{
		cout << "CC aldiniz" << setw(5) << yilsonup << endl;
	}
	else if (yilsonup >= 58)
	{
		cout << "DC aldiniz" << setw(5) << yilsonup << endl;
	}
	else if (yilsonup >=50)
	{
		cout << "DD aldiniz" << setw(5) << yilsonup << endl;
	}
	else
	{
		cout << "FF aldiniz" << setw(5) << yilsonup << endl;
	}

	system("pause");
	return 0;


}
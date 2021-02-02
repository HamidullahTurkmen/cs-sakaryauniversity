/************************************************************************************************************************************/
/*                                                SAKARYA �N�VERS�TES�  */
/*                                       B�LG�SAYAR VE B�L���M B�L�MLER FAK�LTES�*/
/*                                            B�LG�SAYAR M�HEND�SL��� B�L�M�*/
/*                                                PROGRAMLAMAYA G�R�� DERS�*/
/*                                                       G161210045*/
/*                                                     BEYZANUR DEM�R*/
/*                                                       D GRUBU*/
/*                                                    PROJE �DEV�*/
/*************************************************************************************************************************************/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;
int main()
{
	int secim = 1;

	do
	{
		cout << "OTEL ISLEMLER�" << endl;
		cout << "--------------------" << endl;
		cout << "1)Oda Islemleri" << endl;
		cout << "2)Musteri Islemleri" << endl;
		cout << "3)Oda kayit Islemleri" << endl;
		cout << "99)Cikis" << endl;
		cout << "Seciminiz:  " << endl;
		cin >> secim;

	} while (secim != 1 && secim != 2 && secim != 3 && secim != 99);

	if (secim == 1)
	{
		do {
			system("cls");
			cout << "Oda Islemleri" << endl;
			cout << "---------------------" << endl;
			cout << "1)Oda ekle" << endl;
			cout << "2)Oda sil" << endl;
			cout << "3)Odalari listele" << endl;
			cout << "99)Ust menu" << endl;
			cout << "seciminiz:" << endl;
			cin >> secim;

		} while (secim != 1 && secim != 2 && secim != 3 && secim != 99);
		if (secim == 1) //neden �al��m�yor hocam bu k�s�m :(
		{
			class musteri
			{
			public:
				string Ad;
				string Soyad;
				string Numara;
				char TC[11];
				
				fstream dosya;
				musteri() //kurucu dosya
				{ 
					dosya.open("M��teri Bilgisi.txt", ios::in | ios::out | ios::app);
					dosya.setf(ios::left);
				}
				
				void odaEkle(string Numara)
				{
					
					musteri A;
					dosya >> A.Ad;
					dosya >> A.Soyad;
					dosya >> A.Numara;
					dosya >> A.TC;

					cout << "m��teri numaras�: " << endl;
					cin >> Numara;
					if (A.Numara == Numara)
					{
						cout.setf(ios::right);
						cout << setw(20) << "musteri adi:  " << Ad << endl;
						cout << setw(20) << "musteri soyadi:  " << Soyad << endl;
						cout << setw(20) << "musteri numarasi:   " << Numara << endl;
						cout << setw(20) << "musteri TC:    " << TC << endl;
					}
			    }
				int main()
				{
					musteri Musteri;
					Musteri.odaEkle(Numara);
				}
			};
		}
		if (secim == 2)
		{
				//ODA S�L
		}
	
		if (secim == 3)
		{
			//ODALARI L�STELE
		}
		if (secim == 99)
		{
			do {
				system("cls");
				cout << "Oda Islemleri" << endl;
				cout << "---------------------" << endl;
				cout << "1)Oda ekle" << endl;
				cout << "2)Oda sil" << endl;
				cout << "3)Odalari listele" << endl;
				cout << "99)Ust menu" << endl;
				cout << "seciminiz:" << endl;
				cin >> secim;

			} while (secim != 1 && secim != 2 && secim != 3 && secim != 99);
	    }

	if (secim == 2) //m��teri kayd� i�in
	{
		do
		{
			system("cls");
			cout << "Musteri �slemleri" << endl;
			cout << "--------------------------" << endl;
			cout << "1)Musteri kaydet" << endl;
			cout << "2)Musteri sil" << endl;
			cout << "seciminiz" << endl;
			cin >> secim;

		} while (secim != 1 && secim != 2);

		if (secim == 1)
		{
			class musteri
			{
			public:
				string Ad;
				string Soyad;
				string Numara;
				char TC [11];
				int cevap = 'e';
		

				void BilgiGir()
				{
						cout << "M�STER� B�LG�S�" << endl;
						cout << "----------------------------" << endl;

						cout.setf(ios::right);   //sa�a yat�k yazmay� sa�l�yor.

						cout << setw(20) << "musteri adi:  ";
						cin >> Ad;

						cout << setw(20) << "musteri soyadi:  ";
						cin >> Soyad;

						cout << setw(20) << "musteri numarasi:   ";
						cin >> Numara;

						cout << setw(10) << "musteri TC no:    ";
						cin >> TC;
		    	}

				void BilgiYazd�r()
				{
						cout.setf(ios::right);
						cout << setw(20) << "musteri adi:  " << Ad << endl;
						cout << setw(20) << "musteri soyadi:  " << Soyad << endl;
						cout << setw(20) << "musteri numarasi:   " << Numara << endl;
						cout << setw(20) << "musteri TC:    " << TC << endl;
				}
			};

			class Otel
			{
			public:
				musteri Musteriler[100];
				int MustrSayisi;  //M��teri say�s�n� tutacak bir de�i�kene ihtiya� var
				fstream dosya; //Otel bir dosyaya yaz� yazmak ister bu y�zden bir nesneye ihtiyac�m�z var 



				Otel() //kurucu fonksiyon a�t�k
				{
					int MustrSayisi = 0;
					dosya.open("M��teri Bilgisi.txt", ios::out | ios::in | ios::app); //kurucu fonksiyon i�inde dosya a�t�k

					dosya.setf(ios::left);
				}

				void MusteriEkle()
				{

					Musteriler[MustrSayisi].BilgiGir(); //fonksiyon �a�r�ld��� nesnenin de�i�kenlerine etki eder.
					musteri k = Musteriler[MustrSayisi];

					dosya << "M�steri Adi:" << setw(20) << k.Ad
						<< "M�steri Soyad�:" << setw(20) << k.Soyad
						<< "M�steri Numaras�:" << setw(20) << k.Numara
						<< setw(2) << "M�sreri TC:" << setw(20) << k.TC
						<< endl;
				}
			};


			int main();
			{
				Otel SAU;
				SAU.MusteriEkle();
				system("pause");
			}
		}
		if (secim == 2) //m��teri kayd� silmek i�in
		{
			class musteri
			{
			public:
				string Ad;
				string Soyad;
				string Numara;
				char TC[11];
				fstream dosya;

				musteri() //kurucu fonksiyon
				{
					dosya.open("M��teri Bilgisi.txt", ios::in); //okuma modunda a��ld�
					dosya.open("M��teri Bilgisi.tmp", ios::in | ios::out | ios::app ); //ge�ici dosyaya yazma modunda a��ld�
					dosya.setf(ios::left);
				}
				void MusteriSil()
				{
					musteri A;

					while (dosya.eof() != true) //dosyan�n sonunu kontrol ediyor, bu fonk true d�n�yorsa dosya bitmi� demektir.
					{
						dosya >> A.Ad;
						dosya >> A.Soyad;
						dosya >> A.Numara;
						dosya >> A.TC;
						if (A.TC == TC)
						{
							//silinecek kay�d� g�ster ve yedek dosyaya kaydetme
							cout.setf(ios::right);
							cout << "Silinecek kay�d� g�ster" << endl;
							cout << setw(20) << "musteri adi:  " << Ad << endl;
							cout << setw(20) << "musteri soyadi:  " << Soyad << endl;
							cout << setw(20) << "musteri numarasi:   " << Numara << endl;
							cout << setw(20) << "musteri TC:    " << TC << endl;
						}
						else
						{
							//silinmeyecek kay�tlar� yedek dosyaya kaydet
							dosya << setw(20) << Ad << setw(20) << Soyad << setw(20) << Numara << setw(20) << TC;
						}
					}
					dosya.close();
					dosya.close();
					//as�l veri dosyas�n� diskten sil
					remove("M��teri Bilgisi.txt");

					//yedek dosyan�n ismini as�l dosyan�n ismi olarak de�i�tir
					rename("M��teri Bilgisi.tmp", "m��teri Bilgisi.txt");
				}
				int main()
				{ 
				
					musteri Musteri;
					Musteri.MusteriSil();
				}
			};
		}

		if (secim == 3)
		{
			//oda kay�t i�lemleri
		}

		if (secim == 99)
		{
			exit(99);
		}

		system("pause");
	}
}



	




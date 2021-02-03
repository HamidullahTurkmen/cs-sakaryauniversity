#ifndef LISTE_HPP
#define LISTE_HPP

#include <iostream>
using namespace std;

#include "ElemanYok.hpp"
#include "Tasma.hpp"

template <typename Nesne>
struct Dugum{
	Nesne veri;
	Dugum *ileri;
	/**
		D���m s�n�f�n�n yap�c� fonksiyonu.
		@param d���m�n ta��yaca�� veri, verilmez ise bo� bir veri olu�turulur.
		@param d���m�n g�sterece�i d���m, verilmez ise NULL'� g�sterir.
	*/
	Dugum(const Nesne &vr=Nesne(),Dugum *ilr=NULL){
		veri = vr;
		ileri = ilr;
	}
};

template <typename Nesne>
class Liste{
	private:
		Dugum<Nesne> *bas; // Listede ba�taki d���m� tutar.
	public:
		/**
			Yap�c� Fonksiyon
		*/
		Liste(){
			bas = NULL;
		}
		
		/**
			Listenin ba��n� g�steren g�sterici NULL'� g�steriyorsa liste bo�tur.
		*/
		bool Bosmu() const {
			return bas == NULL;
		}
		
		/**
			Listedeki eleman sayisini d�nd�r�r.
		*/
		int Uzunluk() const{
			int uzunluk = 0;
			Dugum<Nesne> *simdiki = bas;
			while(simdiki != NULL){
				simdiki = simdiki->ileri;
				uzunluk++;
			}
			return uzunluk;
		}
		
		/**
			Belirtilen konumdaki d���m� g�steren d���m� bulur.
			@param �stenen d���m�n konumu
		*/
		Dugum<Nesne>* OncekininKonumuileBul(int konum) const throw(Tasma){
			if(konum < 0 || konum > Uzunluk()) throw Tasma("Konum sinirlar disinda!"); 
			int indeks=1;
			Dugum<Nesne> *simdiki = bas;
			while(simdiki->ileri != NULL && konum!=indeks++) simdiki = simdiki->ileri;
			
			return simdiki;
		}
		
		/**
			Verilen eleman� bar�nd�ran d���mden bir �ncekini bulur.
			@param D���m�n i�erdi�i veri
			@return Bir �nceki d���m
		*/
		Dugum<Nesne>* OncekiniBul(const Nesne& eleman) const throw(ElemanYok){
			Dugum<Nesne> *simdiki = bas;
			while(simdiki->ileri != NULL && simdiki->ileri->veri != eleman) simdiki = simdiki->ileri;
			if(simdiki->ileri->veri != eleman) throw ElemanYok("Eleman bulunamadi"); 
			return simdiki;
		}
		
		/**
			Verilen eleman sona eklenir.
		*/
		void Ekle(const Nesne& yeni)
		{
			int konum = (Bosmu() ? 0 : this->Uzunluk());
			Ekle(yeni,konum);
		}
		
		/**
			Verilen eleman belirtilen konuma eklenir.
		*/
		void Ekle(const Nesne& yeni,int konum) throw(Tasma)
		{
			int indeks=0;
			if(konum == 0) // Ba�a ekle
			{
				Dugum<Nesne> *yeniBas = new Dugum<Nesne>(yeni,bas);
				bas=yeniBas;
				return;
			}
			
			try{
				Dugum<Nesne>* onceki = OncekininKonumuileBul(konum);
				// Eklenen konumdan sonraki listenin devam� yeni d���m�n ilerisine eklenecek
				onceki->ileri = new Dugum<Nesne>(yeni,onceki->ileri);
			}
			catch(Tasma &tsm){
				throw Tasma("Konum sinirlar disinda!");
			}
		}
		
		/**
			Listenin t�m d���mlerini ekrana yazar
		*/
		void Yaz() const{
			for(Dugum<Nesne> *simdiki=bas;simdiki!=NULL;simdiki = simdiki->ileri){
				cout<<"|"<<simdiki->veri<<"|->";
			}
			cout<<"NULL"<<endl;
		}
		/**
			Verilen eleman� siler.
			@param Silinecek eleman
		*/
		void Sil(const Nesne &eleman) throw(ElemanYok)
		{
			if(bas->veri == eleman) // ba�� sil.
			{
				Dugum<Nesne> *eskiBas = bas;
				bas = bas->ileri;
				delete eskiBas;
				return;
			}
		
			try{
				Dugum<Nesne> *onceki = OncekiniBul(eleman);
				Dugum<Nesne> *tmp = onceki->ileri;
				onceki->ileri = onceki->ileri->ileri; // silinen eleman� es ge�.
				delete tmp; // ��p olu�mamas� i�in.
			}
			catch(ElemanYok &elm){
				throw ElemanYok("Eleman bulunamadi"); 
			}		
		}
		
		/**
			Listenin sonundaki d���m� siler.
		*/
		void SondanSil() throw(ElemanYok){
			if(Bosmu()) throw ElemanYok("Listede eleman yok.");
			if(this->Uzunluk() == 1) Bosalt(); // Ba�� sil.
			
			Dugum<Nesne> *onceki = OncekininKonumuileBul(this->Uzunluk()-1);
			Dugum<Nesne> *tmp = onceki->ileri;
			onceki->ileri = NULL;
			delete tmp;
		}
		
		/**
			Listenin ba��ndaki d���m� siler.
		*/
		void BastanSil() throw(ElemanYok){
			if(Bosmu()) throw ElemanYok("Listede eleman yok.");
			Dugum<Nesne> *tmp = bas;
			bas = bas->ileri;
			delete tmp;
		}
		
		/**
			Listedki t�m d���mleri belle�e iade eder.
		*/
		void Bosalt()
		{
			while(!Bosmu())
				BastanSil();
		}
		
		/**
			Y�k�c� metot. T�m d���mleri silmek i�in Bosalt metodunu �a��r�r.
		*/
		~Liste()
		{
			Bosalt();
		}
};
#endif
#ifndef STACK_HPP
#define STACK_HPP
 
#include <iostream>
using namespace std;

/**
	Generic yap� tasarlanaca�� zaman generic yap� ile ilgili t�m metot i�erikleri ba�l�k dosyas� i�inde olmal�d�r.
*/
template <typename Nesne>
class Stack
{
   private:
      /**
		struct'ta public veya private tan�m� yap�lmad��� s�rece i�erdi�i elemanlar varsay�lan olarak publictir.
	  */
      struct Dugum
	  {
	      Nesne eleman;
		  Dugum *ileri;
		  Dugum(const Nesne &yeniEleman, Dugum *n=NULL)
		  {
		     eleman=yeniEleman;
			 ileri=n;
		  }
	  };
	  Dugum *stackBasi; // Y���t�n en �st�n� tutuyor.
	  
	public:
		/**
			Varsay�lan Yap�c� metot
		*/
	   Stack()  
	   {
	      stackBasi=NULL;
	   }
	   /**
		 Kopyalama i�lemi yapan yap�c� metot (copy constructor)
	   */
	   Stack(const Stack &sag) 
	   {
	       stackBasi=NULL;
		   *this=sag;
	   }
	   ~Stack()  
	   {
	       Bosalt();
	   }
	   
	   /**
		Sadece okunabilir bir fonskiyon Y���t�n bo� olup olmad���n� kontrol ediyor.
		*/
	   bool Bosmu() const 
	   {
	     // stackBasi NULL ise true d�nd�r.
	      return stackBasi == NULL; 
	   }
	   
	   const Nesne &top() const
	   {
	      //if(Bosmu()) Hata kontrol� yap�lmas� gerekir.			
   
		  return stackBasi->eleman;
	   }
	   
	   /**
		 Y���t� bo�alt�r.
	   */
	   void Bosalt() 
	   {
	     // Bo� olmad��� s�rece eleman ��kar.
	      while(!Bosmu()) 
		   {
			  pop();
		   }
	   }
	   
	   void pop()  
	   {
	       if(Bosmu()) return; // Hata olu�ur
   
		   Dugum *eskiTepe = stackBasi;
		   stackBasi=stackBasi->ileri;
		   delete eskiTepe;
	   }
	   void push(const Nesne& x)  
	   {
	      stackBasi = new Dugum(x,stackBasi);
	   }
	   
	   /**
		Y���t Atama
	   */
	   const Stack& operator=(const Stack& sag)
	   {
	      if(this != &sag)
		   {
			  Bosalt(); // Sol taraftaki stack'i bo�alt.
			  if(sag.Bosmu()) return *this;
			  
			  Dugum *rptr = sag.stackBasi;
			  Dugum *ptr = new Dugum(rptr->eleman);
			  stackBasi=ptr;
			  
			  for(rptr=rptr->ileri;rptr!=NULL;rptr=rptr->ileri)
				  ptr=ptr->ileri=new Dugum(rptr->eleman);
		   }
		   return *this;
	   }
};
#endif
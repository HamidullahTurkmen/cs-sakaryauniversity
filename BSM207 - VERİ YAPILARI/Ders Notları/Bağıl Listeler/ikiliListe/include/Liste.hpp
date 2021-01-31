#ifndef LISTE_HPP
#define LISTE_HPP

#include "Node.hpp"
#include "ListeGezici.hpp"

template <typename Nesne>
class Liste
{
	private:
		Node<Nesne> *header;  // i�inde eleman olmayan sadece ba� taraf� tutan Node.
	public:
		Liste()
		{
			header = new Node<Nesne>();
		}
		
		bool isEmpty() const
		{
			return header->next == NULL;
		}
		
		// Liste gezici �eklinde listenin ba��n� d�nd�r�r. Eleman de�ilde bo� bir Node d�ner.
		ListeGezici<Nesne> zeroth() const
		{
			return ListeGezici<Nesne>(header);
		}
		
		// Liste gezici �eklinde listenin ilk eleman�n� d�nd�r�r
		ListeGezici<Nesne> first() const
		{
			return ListeGezici<Nesne>(header->next);
		}
		
		// Liste gezici �eklinde listenin son eleman�n� d�nd�r�r
		ListeGezici<Nesne> last() const
		{
			//if(this->isEmpty())  Hata olu�ur.
			Node<Nesne> *son = new Node<Nesne>();
			
			for(ListeGezici<Nesne> itr = this->first();!itr.isPastEnd();itr.advance())son->eleman=itr.retrieve();
			
			return ListeGezici<Nesne>(son);
		}
		
		void print()
		{
			if(this->isEmpty())
				cout<<"Liste bos."<<endl;
			else
			{
				ListeGezici<Nesne> itr = this->first();
				for( ; !itr.isPastEnd(); itr.advance())
					cout<<itr.retrieve()<<" ";
			}
			
			cout<<endl;
		}
		
		ListeGezici<Nesne> find(const Nesne& aranan) const
		{
			Node<Nesne> *itr = header;
			while(itr != NULL && itr->eleman != aranan) itr=itr->next;
			
			return ListeGezici<Nesne>(itr);
		}
		
		// belirtilen elemandan ilk g�rd��� yerde listeden ��kar�r.
		void remove(const Nesne& aranan)
		{
			ListeGezici<Nesne> p = find(aranan);  // Aranan listede yoksa hata olu�ur.
			Node<Nesne> *eskiNode = p.current;
			
			p.current->prev->next = p.current->next;
			if(p.current->next != NULL) p.current->next->prev = p.current->prev;
			delete eskiNode;			
		}
		
		// belirtilen konumdan eleman ��kar�r.
		void removeAt(int konum)
		{
			//if(this->isEmpty())  Hata olu�ur.
			
			int indeks=0;
			Node<Nesne> *eskiNode = header->next;
			while(eskiNode->next != NULL && konum!=indeks++) eskiNode = eskiNode->next;
			
			eskiNode->prev->next = eskiNode->next;
			if(eskiNode->next != NULL) eskiNode->next->prev = eskiNode->prev;
			delete eskiNode;
		}
		
		// belirtilen konumdaki eleman� getirir.
		ListeGezici<Nesne> elementAt(int konum)
		{
			ListeGezici<Nesne> p = findPreviousByPosition(konum);
			
			if(p.current->next != NULL)
			{
				Node<Nesne> *istenenNode = p.current->next;
				return ListeGezici<Nesne>(istenenNode);
			}
			
			return NULL;
		}
		
		// Aranan node'un bir �ncesini getirir.
		ListeGezici<Nesne> findPrevious(const Nesne& aranan) const
		{
			ListeGezici<Nesne> p = find(aranan);
			
			return ListeGezici<Nesne>(p.current->prev);
		}
		
		// Aranan konumun bir �ncesini getirir.
		ListeGezici<Nesne> findPreviousByPosition(int konum) const
		{
			int indeks=0;
			Node<Nesne> *itr = header;
			while(itr->next != NULL && konum!=indeks++) itr = itr->next;
			
			return ListeGezici<Nesne>(itr);
		}
		
		// yeni eleman� belirtilen konuma ekler.
		void insert(const Nesne& yeni,int konum)
		{
			int indeks=0;
			ListeGezici<Nesne> itr = findPreviousByPosition(konum);
			
			Node<Nesne> *prevTemp = itr.current->next;
			itr.current->next = new Node<Nesne>(yeni,itr.current->next,itr.current);
			if(prevTemp != NULL) prevTemp->prev = itr.current->next;
		}
		
		// yeni eleman� listede p'den sonras�na ekler.
		void insert(const Nesne& yeni,const ListeGezici<Nesne>& p)
		{
			if(p.current != NULL)
			{
				Node<Nesne> *prevTemp = p.current->next;
				p.current->next = new Node<Nesne>(yeni,p.current->next,p.current);
				if(prevTemp != NULL) prevTemp->prev = p.current->next;
			}
		}	
		
		// Listeyi bo�alt�r.
		void makeEmpty()
		{
			while(!isEmpty())
				remove(first().retrieve());
		}
		// Y�k�c� metot
		~Liste()
		{
			makeEmpty();
			delete header;
		}
};
#endif
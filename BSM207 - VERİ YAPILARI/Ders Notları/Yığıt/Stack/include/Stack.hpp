#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

#include "Tasma.hpp"
#include "ElemanYok.hpp"

#define BOYUT 100

template <typename Nesne>
class Stack{
	private:
		Nesne elemanlar[BOYUT];
		int stackBasi;
	public:
		Stack(){
			stackBasi=-1;
		}
		bool bosmu(){
			return stackBasi == -1;
		}
		bool dolumu(){
			return stackBasi == (BOYUT - 1);
		}
		/**
			Push i�lemi
		*/
		void push(const Nesne &eleman) throw(Tasma){
			if(dolumu()) throw Tasma("Stack dolu!"); 
			stackBasi++;
			elemanlar[stackBasi] = eleman;
		}
		/**
			Pop i�lemi
		*/
		void pop() throw(ElemanYok){
			if(bosmu()) throw ElemanYok("Eleman yok");
			stackBasi--;
		}
		/**
			Stackta s�radaki eleman� g�sterir.
		*/
		const Nesne& top() const {
			return elemanlar[stackBasi];
		}
		void makeEmpty(){
			stackBasi=-1;
		}
};
#endif
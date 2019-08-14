/*
 * Hash.h
 *
 *  Created on: 2019Äê7ÔÂ24ÈÕ
 *      Author: yifan
 */

#ifndef HASH_H
#define HASH_H
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Member.h"
#include "Iterator.h"
using namespace std;

template <class T>
class HashTable{
	static const int emptySlot = -99999991;
  protected:
	T ** table;
	int cap, iSize;
	double MLF, incPer;
  public:
	class HashIterator: public Iterator<T>{
		int index;
		T * cur;
		public:
			HashIterator( int i, T * ptr ) { index = i;cur = ptr; }
			bool hasNext() { return index < cap;}
			T * next(){
				index = index + 1;
				cur = table[index+1];
				return cur;
			}
			void remove() {}
	};
	Iterator<T> * iterator() { return new HashIterator( 0, table[0] ); }
	void initialize(){
		for(int i = 0; i < cap; i ++) table[i] = NULL;
		iSize = 0;
	}
	HashTable(){
		cap = 10; iSize = 0; MLF = 0.80; incPer = 0.20;
		table = new T * [cap];
		initialize();
	}
	~HashTable(){delete [] table;}
	int capacity(){return cap;}
	int distance(int from, int to){return to >= from ? to - from: cap - from + to;}

	//change template objects to their Id, and should be overwritten if item has no ID
	int hashCode(T * item){return item == NULL? emptySlot: item->ID;}
	int hash(int ID){return ID % cap;}

	void show(){
		int id, homeAdd, dis;
		string name;
		printf("\nCur-pos  ID               Last-First-Name         Home   Distance\n");
		for(int i = 0; i < cap; i ++){
			id = table[i] == NULL? emptySlot:hashCode(table[i]);
			homeAdd = table[i] == NULL? i:hash(id);
			name = table[i] == NULL? "null":table[i]->toString();
			dis = distance(homeAdd, i);
			printf("%-8d ID: %-9s Name: %-20s", i, id == emptySlot? "null" : to_string(id).c_str(), name.c_str());
			printf("%7d %7d\n", homeAdd, dis);
		}
	}


	void add(T * nn){
		int homeAdd = hash(hashCode(nn));
		while(table[homeAdd] != NULL) homeAdd = (homeAdd + 1) % cap;
		table[homeAdd] = nn; iSize++;
		double curMLF = (double)(iSize)/(double)(cap);
		if (curMLF > MLF) rehash();
	}
	void rehash(){
		int length = cap;
		T ** temp = table;
		cap = (double)cap * (1.0 + incPer);
		table = new T * [cap];
		initialize();
		for(int i = 0; i < length; i++){
			if(temp[i] != NULL){ add(temp[i]); }
		}
	}
	T * get(T * obj){
		return get(hashCode(obj));
	}
	T * get(int ID){
		if(ID < 0) return NULL;
		int homeAdd = hash(ID);
		while(table[homeAdd] != NULL && table[homeAdd]->ID != ID){
			homeAdd = (homeAdd + 1) % cap;
		}
		return table[homeAdd];
	}
	T * remove(T * obj){
		return remove(hashCode(obj));
	}
	T * remove(int ID){
		int homeAdd = hash(ID);
		while(table[homeAdd] != NULL && table[homeAdd]->ID != ID){
			homeAdd = (homeAdd + 1) % cap;
		}
		T * tmp = table[homeAdd];
		table[homeAdd] = NULL;
		if(tmp != NULL && tmp->ID == ID) {iSize--;}
		shift(homeAdd, (homeAdd + 1) % cap);
		return tmp;
	}
	void shift(int empty, int cur){
		if( table[cur] == NULL ) return;
		int home = hash(hashCode(table[cur]));
		int dis1 = distance(home, empty);//distance from home of cur to empty
		int dis2 = distance(home, cur);//distance from home of cur to cur
		if(dis1 < dis2){
			table[empty] = table[cur];
			table[cur] = NULL;
			shift( cur, (cur+1) % cap);
		}else shift( empty, (cur + 1) % cap );
	}
};



#endif /* HASH_H */

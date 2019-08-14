/*
 * HashTest.cpp
 *
 *  Created on: 2019Äê7ÔÂ24ÈÕ
 *      Author: yifan
 */
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Hash.h"
#include "Member.h"
#include "Iterator.h"
using namespace std;

HashTable<Member> memberTable;


	void menu() {
       cout << "\n\n\t+-------- General List Help Menu  -------+\n";
       cout << "\t|    S: Show each Item and position      |\n";
       cout << "\t|    I: Insert entry                     |\n";
       cout << "\t|    D: Delete entry                     |\n";
       cout << "\t|    G: Get entry name                   |\n";
       cout << "\t|    Q: Exit                             |\n";
       cout << "\t+----------------------------------------+\n";
       cout << "\t|    ?/H: Show this menu                 |\n";
       cout << "\t+----------------------------------------+\n";
	}
	/*
	void show(){
		Iterator<Member> * itr = iterator<Member>();
	    Member * v;
	    int homeAdd, dis;
	    int i = 0;
	    printf("\nCur-pos  ID               Last-First-Name         Home   Distance\n");
	    while (itr->hasNext()) {
			v = itr->next();
			homeAdd = v == NULL? i: memberTable.hash(memberTable.hashCode(v));
			dis = memberTable.distance(homeAdd, i);
			printf("%-8d", i);
			printf("%-40s", (v->toString().c_str()));
			printf("%7d %7d\n", homeAdd, dis);
	    }
	}*/

int main(int argc, char ** argv)  {
	srand(time(NULL));
	string s1, s2;
	for(int i = 0; i < 8; i ++){
		Member * n = new Member();
		memberTable.add(n);
	}
	char c = ' ';
	string name1, name2, name3, name4;
	int ID;
	while ( c != 'Q' && c != 'q' ) {
		cout << "\n\tType ? for help, Q, q to quit or S/I/D/G command: ";
		cin >> c;
		switch(c) {
    		case '?': case 'H': case 'h':
    			menu();
    			break;
    		case 's': case 'S':
    			cout << "\tShow Each item-position including current and home position, and its distance.\n";
    			memberTable.show();
    			break;
    		case 'd': case 'D':
    			cout << "\tAsk for ID to delete in the list\n";
    			cin >> ID;
    			memberTable.remove(ID);
    			memberTable.show();
    			break;
    		case 'g': case 'G':
    			cout << "Ask for ID to show full name.\n";
    			cin >> ID;
    			if(memberTable.get(ID)== NULL) s1 =  "Null";
    			else s1 = memberTable.get(ID)->lastName+" "+memberTable.get(ID)->firstName;
    			cout << s1 << endl;
    			break;
    		case 'q': case 'Q':
    			return 0;
    		case 'i': case 'I':
    			cout << "\tAsk for last and first name to add.\n";
    			cin >> ID;
    			cin >> name1;
    			cin >> name2;
    			Member * nn = new Member(ID, name1, name2);
    			memberTable.add( nn);
    			memberTable.show();
    		break;
	} // end of switch
} // end of while
	return 0;
}


/*
int main(int argc, char ** argv)  {
	srand(time(NULL));
	//HashTable<Member> memberTable;
	Member s1 = Member("Teer", "asdfs");
	printf("s1 is %d\n", s1.IDnum(s1));
	Member s2 = Member("aaaa", "bbbb");
	printf("s1 is %d\n", s2.IDnum(s2));
	bool x = s1 < s2;
	printf("x is %d\n", x);
	return 0;
}*/


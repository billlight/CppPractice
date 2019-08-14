/* general_list_test2.cpp:
	A driver program which tests the general list operations
   implemented in both array and linked list.
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Iterator.h"
#include "List_temp.h"
using namespace std;



void menu() {
    cout << "\n\n\t+-------- General List Help Menu  -------+\n";
    cout << "\t|    S: Show each Item and position      |\n";
    cout << "\t|    I: Insert entry at position x       |\n";
    cout << "\t|    D: Delete entry at position x       |\n";
    cout << "\t|    G: Get entry at position x          |\n";
    cout << "\t|    Q: Exit                             |\n";
    cout << "\t+----------------------------------------+\n";
    cout << "\t|    ?/H: Show this menu                 |\n";
    cout << "\t+----------------------------------------+\n";
}

List<char> intList;
// List<char>  cList;
char val;
int pos;

void addItem(int n ) {
    for ( int i = 0; i < n ; i++ ) {
    	val = rand() % 26;
    	pos = rand() % ( intList.size() + 1);
    	intList.add( (char) (val + 65), pos);
    }
    intList.show();
}
void addOne() {
    cout << "\tEnter value and position position: ";
    cin >> val >> pos;
    intList.add((char)val , pos);
    intList.show();
}

void removeOne() {
    cout << "\tEnter position :";
    cin >> pos;
    intList.remove(pos);
    intList.show();
}
int main(int argc, char ** argv)  {

   srand(time(0));// set random seed.

    addItem( 10);

    char c = ' ';

    while ( c != 'Q' && c != 'q' ) {
    	cout << "\nType ? for help, Q, q to quit or S/I/D/G command: ";
    	cin >> c;

    	switch(c) {
        	case '?': case 'H': case 'h':
        		menu();
        		break;
        	case 's': case 'S':
        		intList.show();
        		break;
        	case 'i': case 'I':
        		addOne();
        		break;
        	case 'd': case 'D':
        		removeOne();
        		break;
        	case 'g': case 'G':
        		cout << "Enter a position: ";
        		cin >> pos ;
        		intList.data(pos);
        		printf("[%d] is %c \n", pos, intList.data(pos));
        		break;
        	case 'q': case 'Q':
        		return 0;
    	} // end of switch
    } // end of while

}


/*
 * testBST.cpp
 *
 *  Created on: 2019Äê7ÔÂ24ÈÕ
 *      Author: yifan
 */
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include "BinarySearchTree.h"

	BST<int> iBST;
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

int main(int argc, char ** argv)  {
	srand(time(NULL));

	int k;
	for(int i = 0; i < 5; i++){
		k = rand()%100;
		printf("%d ", k);
		iBST.add(k);
	}
	iBST.show();

    char c = ' ';
    int v;
    while ( c != 'Q' && c != 'q' ) {
    	cout << "\nType ? for help, Q, q to quit or S/I/D/G command: ";
    	cin >> c;

    	switch(c) {
        	case '?': case 'H': case 'h':
        		menu();
        		break;
        	case 's': case 'S':
        		iBST.show();
        		break;
        	case 'i': case 'I':
        		cout << "Enter the value to be added" << endl;
        		cin >> v;
        		iBST.add(v);
        		iBST.show();
        		break;
        	case 'd': case 'D':
        		cout << "Enter the value to be delete" << endl;
        		cin >> v;
        		iBST.remove(v);
        		iBST.show();
        		break;
        	case 'g': case 'G':
        		cout << "Enter a value: ";
        		cin >> v ;
        		iBST.find(v);
        		break;
        	case 'q': case 'Q':
        		return 0;
    	} // end of switch
    } // end of while

	return 0;
}



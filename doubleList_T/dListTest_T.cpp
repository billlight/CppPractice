/*
 * dListTest_T.cpp
 *
 *  Created on: 2019/7/16
 *      Author: yifan
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "doubleList_T.h"
#include "Iterator.h"
#include "Stack.h"
#include "Queue.h"
#include "SortedQueue.h"
using namespace std;

void menu() {
    cout << "\n\n\t+-------- General List Help Menu  -------+\n";
    cout << "\t|    I: Add to front for Stack and to end for Queue|\n";
    cout << "\t|    D: Delete front element                       |\n";
    cout << "\t|    G: Get entry at front                         |\n";
    cout << "\t|    Q: Exit                                       |\n";
    cout << "\t+--------------------------------------------------+\n";
    cout << "\t|    ?/H: Show this menu                           |\n";
    cout << "\t+--------------------------------------------------+\n";
}
SQueue<char> sQueue;
Queue<char> aQueue;
Stack<char> aStack;
char val;

void addStack(int n ,bool direction) {
    for ( int i = 0; i < n ; i++ ) {
    	val = rand() % 26;
    	aStack.push( (char) (val + 65));
    }
}

void addQueue(int n ,bool direction) {
    for ( int i = 0; i < n ; i++ ) {
    	val = rand() % 26;
    	aQueue.enque( (char) (val + 65));
    }
}

void addSQueue(int n ,bool direction) {
    for ( int i = 0; i < n ; i++ ) {
    	val = rand() % 26;
    	sQueue.enque( (char) (val + 65));
    }
}

void addStack() {
    cout << "\tEnter value: ";
    cin >> val;
    aStack.push((char)val);
}

void addQueue() {
    cout << "\tEnter value: ";
    cin >> val;
    aQueue.enque((char)val);
}

void addSQueue() {
    cout << "\tEnter value: ";
    cin >> val;
    sQueue.enque((char)val);
}

void removeStack() {
    cout << "\tRemove first item ";
    aStack.pop();
}

void removeQueue() {
    cout << "\tRemove first item ";
    aQueue.deque();
}

void removeSQueue() {
    cout << "\tRemove first item ";
    sQueue.deque();
}

int main(int argc, char ** argv)  {
    srand(time(0));// set random seed.

    addStack( 10, true);
    addQueue( 10, true);
    addSQueue( 10, true);

    char c = ' ';
    int x;
	cout << "\nType? Stack, Queue, or sorted Queue with command 1/2/3: ";
	cin >> x;
    while ( c != 'Q' && c != 'q' ) {
    	if (x < 2){
    		cout << "\nType ? for help, Q, q to quit or I/D/G command: ";
    		cin >> c;

    		switch(c) {
        		case '?': case 'H': case 'h':
        			menu();
        			break;
        		case 'i': case 'I':
        			addStack();
        			break;
        		case 'd': case 'D':
        			removeStack();
        			break;
        		case 'g': case 'G':
        			cout << "Get first element ";
        			printf("Last element is %c \n", aStack.top());
        			break;
        		case 'q': case 'Q':
        			return 0;
    		}
    	}// end of switch
    	if (x == 2){
    		cout << "\nType ? for help, Q, q to quit or I/D/G command: ";
    		cin >> c;

    		switch(c) {
    			case '?': case 'H': case 'h':
    		    	menu();
    		        break;
    		    case 'i': case 'I':
    		        addQueue();
    		        break;
    		    case 'd': case 'D':
    		        removeQueue();
    		        break;
    		    case 'g': case 'G':
    		        cout << "Get first element ";
    		        printf("Last element is %c \n", aQueue.front());
    		        break;
    		    case 'q': case 'Q':
    		        return 0;
    		   }
    	}
    	if (x > 2){
    		cout << "\nType ? for help, Q, q to quit or I/D/G command: ";
    		cin >> c;

    		switch(c) {
    			case '?': case 'H': case 'h':
    		    	menu();
    		        break;
    		    case 'i': case 'I':
    		        addSQueue();
    		        break;
    		    case 's': case 'S':
    		    	sQueue.show();
    		    	break;
    		    case 'd': case 'D':
    		        removeSQueue();
    		        break;
    		    case 'g': case 'G':
    		        cout << "Get first element ";
    		        printf("Last element is %c \n", sQueue.front());
    		        break;
    		    case 'q': case 'Q':
    		        return 0;
    		   }
    	}
    }
}



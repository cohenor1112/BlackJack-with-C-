#include <iostream>

#include <time.h>
#include "BlackJack.h"

//#include "Card.h"
//#include "Dequeue.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
//see http://msdn.microsoft.com/en-us/library/e5ewb1h3(VS.80).aspx

using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

void test() {
	BlackJack bj;
	bj.play();
}

int main()
{
	srand(time(NULL));
	test();
	cout << "Leaks = " << _CrtDumpMemoryLeaks() << endl;
	return 0;
}

///////////////////////////////////////////////////////////
//int main() {		///////////// Card.cpp //////////////
///////////////////////////////////////////////////////////
//	Card  c1(1);
//	Card  c2(10);
//	Card  c3(12);
//	cout << "test print cards:" << endl << "c1 = " << c1 << endl << "c2 = " << c2 << endl << "c3 = " << c3 << endl;
//
//	cout << "Leaks = " << _CrtDumpMemoryLeaks() << endl;
//	return 0;
//}


///////////////////////////////////////////////////////////
//int main() {	  ///////////// dequeue.cpp /////////////
///////////////////////////////////////////////////////////
//	Dqueue* d = new Dqueue(10);
//	Card* c1 = new Card(2);
//	Card* c2 = new Card(3);
//	Card* c3 = new Card(4);
//	Card* c4 = new Card(5);
//	Card* c5 = new Card(6);
//	Card* c6 = new Card(7);
//	Card* c7 = new Card(8);
//	Card* c8 = new Card(9);
//	cout << "is empty = " << d->is_empty() << endl << endl;
//
//	d->push_back(c1);
//	d->push_front(c2);
//
//	cout << "card in the back = " << d->back() << endl << "card in the front = " << d->front() << endl;
//	d->push_back(c3);
//	d->push_back(c4);
//	d->push_back(c5);
//	d->pop_front();
//	d->pop_front();
//	d->pop_front();
//	d->pop_front();
//
//	cout << "dequeue zise = " << d->size() << endl;
//
//	delete d;
//}
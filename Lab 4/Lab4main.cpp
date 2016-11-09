/*
 * Lab4main.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: Alvin
 */
#include "BSTB.hpp"
#include "NodeTB.hpp"
#include "Game.hpp"
#include<stdlib.h>
#include <iostream>
using namespace std;

int main() {
	BSTB *dict = new BSTB();
	BSTB *test = new BSTB();
	dict->insert("Cool");
	dict->insert("Duck");
	dict->insert("New");
	test->insert("Cool");
	cout << "testing printTreeio()" << endl;
	test->printTreeio();
	test->insert("Bus");
	cout << "testing insert(string x)" << endl;
	test->printTreeio();
	test->insert("Duck");
	test->printTreeio();
	test->insert("Each");
	test->printTreeio();
	test->insert("Zap");
	test->insert("Can");

	test->printTreeio();

	test->printTreePre();

	test->printTreePost();

	cout<< "Testing search(string)"<<endl;
	cout << test->search("Zap") << endl;
	cout << test->search("Cool") << endl;
	cout << test->search("Bus") << endl;
	cout << test->search("Can") << endl;
	cout << test->search("Duck") << endl;
	cout << test->search("Each") << endl;
	cout << test->search("NotZap") << endl;
	dict->printTreeio();
	  cout<<test->getScore(dict)<<endl;
	test->adjustBalances();





	test->~BSTB();
	cout<<"testing ~BSTB()"<<endl;
	test->printTreeio();


	return 1;
}

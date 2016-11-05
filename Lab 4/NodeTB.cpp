#include "NodeTB.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
NodeTB::NodeTB(string x){
	data = x;
	left = NULL;
	right = NULL;
}
NodeTB:: ~NodeTB(){
	if (left != NULL || right != NULL) {
		cout << "deleting this DNode may cause a memory leak" << endl;
	}

}
string NodeTB::getData(){
	return data;
}
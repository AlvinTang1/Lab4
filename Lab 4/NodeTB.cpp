#include "NodeTB.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
NodeTB::NodeTB(string x){
	height = 1;
	data = x;
	left = NULL;
	right = NULL;
	parent = NULL;
}
NodeTB:: ~NodeTB(){
	if (left != NULL || right != NULL) {
		cout << "deleting this NodeTB may cause a memory leak" << endl;
	}

}
string NodeTB::getData(){
	return data;
}

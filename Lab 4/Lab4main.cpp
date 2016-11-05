/*
 * Lab4main.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: Alvin
 */
#include "BSTB.hpp"
#include "NodeTB.hpp"
#include<stdlib.h>
#include <iostream>
using namespace std;

int main() {
	BSTB *test = new BSTB();
	test->insert( "Cool");
	test->insert("Bus");
	test->insert("Duck");
	test->printTreeio();

}

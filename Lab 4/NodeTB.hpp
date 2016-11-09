#include <iostream>
 using namespace std;
#ifndef NodeTB_HPP_
#define NodeTB_HPP_
 class NodeTB{
	 friend class BSTB;
	 int height;
	 string data;
	 NodeTB *left;
	 NodeTB *right;
	 NodeTB *parent;

public:
	 NodeTB(string x);
	 ~NodeTB();
	 string getData();
	 int getHeight();

 };
#endif /* NodeTB_HPP_ */

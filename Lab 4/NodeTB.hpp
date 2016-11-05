#include <iostream>
 using namespace std;
#ifndef LLNode_HPP_
#define LLNode_HPP_
 class NodeTB{
	 friend class BSTB;
	 int height;
	 string data;
	 NodeTB *left;
	 NodeTB *right;

public:
	 NodeTB(string x);
	 ~NodeTB();
	 string getData();

 };
#endif /* NodeTB_HPP_ */

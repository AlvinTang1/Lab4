/*
 * BSTB.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Alvin
 */
#include "BSTB.hpp"
#include "NodeTB.hpp"
#include<iostream>
using namespace std;
BSTB::BSTB() {
	root = NULL;
	count = 0;
} //BSTB() constructor
BSTB::~BSTB() {
	NodeTB *tmp = root;
	if (tmp == NULL) {
		return;
	} //if
	else {
		destructBSTB(tmp);
	}
} //~BSTB() Destructor
void BSTB::destructBSTB(NodeTB *n) {
	if (n == NULL) {
		return;
	} //if
	else {
		destructBSTB(n->left);
		destructBSTB(n->right);
		delete n;
	}
}
bool BSTB::insert(string word) {
	NodeTB *n = new NodeTB(word);
	int nHeight = 1;
	if (root == NULL) {
		root = n;
		//root->height = nHeight;
		count++;
		cout <<n->getHeight()<<endl;
		return true;
	} else {
		return insert(word, root, nHeight+1);
	}
}

bool BSTB::insert(string word, NodeTB *n,int nHeight) {
	if (n->data > word) {
		if (n->left == NULL) {
			n->left = new NodeTB(word);
			n->left->height = nHeight;
			n->left->parent = n;
			count++;
			cout <<n->left->getHeight()<<endl;
		} else {
			return insert(word, n->left,nHeight+1);
		}
	} //if root's data is greater than input run insert again with root's right node
	else if (n->data < word) {
		if (n->right == NULL) {
			n->right = new NodeTB(word);
			n->right->height = nHeight;
			n->right->parent = n;
			count++;
			cout <<n->right->getHeight()<<endl;
		} else {
			return insert(word, n->right, nHeight+1);
		}
	} //if root's data is less than input run insert with root's left node
	else {
		return false;
	}
}
/*bool BSTB::insert(string word) {
 return insert(word, root);
 } //insert(string word)

 bool BSTB::insert(string word, NodeTB *root) {
 if (!root) {
 NodeTB root = NodeTB(word);
 return true;
 } // if root is Null create a NodeTb to put in its place
 else {
 if (root->data > word) {
 return insert(word, root->right);
 } //if root's data is greater than input run insert again with root's right node
 if (root->data < word) {
 return insert(word, root->left);
 }//if root's data is less than input run insert with root's left node
 else{
 return false;
 }
 }

 }
 */
void BSTB::printTreeio(NodeTB *n) {
	if (n == NULL) {
		return;
	} //if
	else {
		printTreeio(n->left);
		cout << "'" << n->getData() << "', ";
		printTreeio(n->right);
	} //else
} //printTreeio(NodeTB *n) print tree in order recursively
void BSTB::printTreeio() {
	NodeTB *tmp = root;
	if (tmp == NULL) {
		return;
	} //if
	else {
		printTreeio(tmp);
	}
	cout<<endl;
} //printTreeio() prints tree in order
void BSTB::printTreePre(NodeTB *n) {
	if (n == NULL) {
		return;
	} //if
	else {
		cout << "'" << n->getData() << "', ";
		printTreePre(n->left);
		printTreePre(n->right);
	} //else
} //printTree(NodeTB *n) prints tree preorder recursively
void BSTB::printTreePre() {
	NodeTB *tmp = root;
	if (tmp == NULL) {
		return;
	} //if
	else {
		printTreePre(tmp);
	} //else
	cout<<endl;
} //printTreePre() prints tree preorder
void BSTB::printTreePost(NodeTB *n) {
	if (n == NULL) {
		return;
	} //if
	else {
		printTreePost(n->left);
		printTreePost(n->right);
		cout << "'" << n->getData() << "', ";
	} //else
} //printTreePost(NodeTB *n) prints tree postorder recursively
void BSTB::printTreePost() {
	NodeTB *tmp = root;
	if (tmp == NULL) {
		return;
	} //if
	else {
		printTreePost(tmp);
	}
	cout<<endl;
} //printTreePost() prints tree postorder
bool BSTB::search(string x) {
	NodeTB *tmp = root;
	while (tmp != NULL) {
		if (tmp->data == x) {
			return true;
		} //if
		if (tmp->data > x) {
			tmp = tmp->left;
		} //if
		else if (tmp->data < x) {
			tmp = tmp->right;
		} //if
	}
	return false;
} //search(string x) Search a tree for string value x
/*bool BSTB::search(string x) {
 NodeTB *tmp = root;
 while (tmp->left != NULL && tmp->right != NULL) {
 if (root->data == x) {
 return true;
 } //if
 if (root->data > x) {
 tmp = root->left;
 } //if
 if (root->data < x) {
 tmp = root->right;
 } //if
 else {
 return false;
 } //else
 } //while
 } //search(string x) Search a tree for string value x */

/*bool BSTB::search(NodeTB *n, string x) {
 if (x == n->data) {
 return true;
 }
 if (x > n->data) {
 search(n->right, x);
 }
 if (x < n->data) {
 search(n->left, x);
 } else {
 return false;
 }
 } */

NodeTB *BSTB::rotateRight(NodeTB *n) {
	NodeTB *m = n->left;
	NodeTB *tmp = m->right;
	m->right = n;
	n->left = tmp;
	if (n->left->height > n->right->height) {
		n->height = n->left->height + 1;
	} //if
	else {
		n->height = n->right->height + 1;
	} //else
	if (m->left->height > m->right->height) {
		m->height = m->left->height + 1;
	} else {
		m->height = m->right->height + 1;
	}
	return m;
}
/*NodeTB *BSTB::rotateRight(NodeTB *n) {
 NodeTB *m = n->left;
 NodeTB *tmp = m->right;
 m->right = n;
 n->left = tmp;
 if (n->left->height > n->right->height) {
 n->height = n->left->height + 1;
 } //if
 else {
 n->height = n->right->height + 1;
 } //else
 if (m->left->height > m->right->height) {
 m->height = m->left->height + 1;
 } else {
 m->height = m->right->height + 1;
 }
 return m;
 } */
NodeTB *BSTB::rotateLeft(NodeTB *n) {
	NodeTB *m = n->right;
	NodeTB *tmp = m->left;
	m->left = n;
	n->right = tmp;
	if (n->right->height > n->left->height) {
		n->height = n->right->height + 1;
	} //if
	else {
		n->height = n->left->height + 1;
	} //else
	if (m->right->height > m->left->height) {
		m->height = m->right->height + 1;

	} //if
	else {
		m->height = m->left->height + 1;
	} //else
} //rotateLeft(NodeTB *n)
/*void BSTB::adjustBalances(NodeTB *n) {
 NodeTB *p = n->left;
 NodeTB *m = n->right;
 if (n->left->height == n->right->height) {
 return;
 } //if
 else if (n->left->height > n->right->height + 1
 && p->left->height > p->right->height + 1) {
 rotateRight(n);
 rotateRight(p);
 } //else if
 else if (n->right->height > n->left->height + 1
 && m->right->height + 1 > m->left->height + 1) {
 rotateLeft(n);
 rotateLeft(m);
 } //else if
 else if (n->left->height > n->right->height + 1
 && m->right->height > m->left->height + 1) {
 rotateRight(n);
 rotateLeft(m);
 } //else if
 else if (n->right->height > n->left->height
 && p->left->height > p->right->height + 1) {
 rotateLeft(n);
 rotateRight(p);
 } //else if
 else { //else
 return;
 } //adjustBalances(NodeTB *n)
 } */
void BSTB::adjustBalances(NodeTB *n) {
	NodeTB *p = n->left;
	NodeTB *m = n->right;
	if (n->left->height == n->right->height) {
		return;
	} //if
	else if (n->left->height > n->right->height + 1
			&& p->left->height > p->right->height + 1) {
		n->parent->left = rotateRight(n);
		p->parent->right = rotateRight(p);
	} //else if
	else if (n->right->height > n->left->height + 1
			&& m->right->height + 1 > m->left->height + 1) {
		n->parent->right = rotateLeft(n);
		m->parent->left = rotateLeft(m);
	} //else if
	else if (n->left->height > n->right->height + 1
			&& m->right->height > m->left->height + 1) {
		n->parent->left = rotateRight(n);
		m->parent->left = rotateLeft(m);
	} //else if
	else if (n->right->height > n->left->height
			&& p->left->height > p->right->height + 1) {
		n->parent->right = rotateLeft(n);
		p->parent->right = rotateRight(p);
	} //else if
	else { //else
		return;
	} //adjustBalances(NodeTB *n)
}
void BSTB::adjustBalances(){
	NodeTB *tmp = root;
		if (tmp == NULL) {
			return;
		} //if
		else {
			adjustBalances(tmp);
		} //else
	} //adjustBalances()
int BSTB::getScore(NodeTB *n, BSTB *dict, int &score) {
	if (n == NULL) {
		return 0;
	} //if
	else {
		getScore(n->left, dict, score);
		getScore(n->right, dict, score);
		if (dict->search(n->data) == true) {
			++score;
		}
		if(dict->search(n->data)==false){
			score = score - 6;
		}
		//cout << "'" << n->getData() << "', ";
	}
}
	int BSTB::getScore(BSTB *dict) {
		int score;
		//score = new int;
		score = 0;
		NodeTB *tmp = root;
		if (tmp == NULL) {
			return 0;
		} //if
		else {
			getScore(tmp,dict,score);
		}//else
		return score;
	} //printTreePre() prints tree preorder


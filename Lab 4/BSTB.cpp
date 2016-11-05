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
	delete root->left;
	delete root->right;
	delete root;
	count = 0;
} //~BSTB() destructor
bool BSTB::insert(string x) {
	NodeTB *n = new NodeTB(x);
	if (n->data > x) {
		n->left->data = x;
		return true;
	} //if
	if (n->data < x) {
		n->right->data = x;
		return true;
	} //if
	else {
		return false;
	} //else
} //insert(string x) inserts a NodeTB nonrecursively
bool BSTB::insert(string x, NodeTB *n) {
	if (n->left == NULL || n->right == NULL) {
		if (n->data > x) {
			NodeTB *tmp = new NodeTB(x);
			n->left = tmp;
			n->left->data = x;
			return true;
		} //if
		else if (n->data < x) {
			NodeTB *tmp = new NodeTB(x);
			n->right = tmp;
			return true;
		} //else if
	} //if
	if (n->data > x) {
		insert(x, n->left);
	} //if
	if (n->data < x) {
		insert(x, n->right);
	} //if
	else {
		return false;
	} //else
} //insert(string x, NodeTB *n) inserts a NodeTB recursively
void BSTB::printTreeio(NodeTB *n) {
	if (n == NULL) {
		return;
	} //if
	else {
		printTreeio(n->left);
		n->getData();
		printTreeio(n->right);
	} //else
} //printTreeio(NodeTB *n) print tree in order recursively
void BSTB::printTreeio() {
	NodeTB *tmp = root;
	if (tmp == NULL) {
		return;
	} //if
	else {
		printTreeio(root->left);
		root->getData();
		printTreeio(root->right);
	} //else
} //printTreeio() prints tree in order
void BSTB::printTreePre(NodeTB *n) {
	if (n == NULL) {
		return;
	} //if
	else {
		n->getData();
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
		root->getData();
		printTreePre(root->left);
		printTreePre(root->right);
	} //else
} //printTreePre() prints tree preorder
void BSTB::printTreePost(NodeTB *n) {
	if (n == NULL) {
		return;
	} //if
	else {
		printTreePost(n->left);
		printTreePost(n->right);
		n->getData();
	} //else
} //printTreePost(NodeTB *n) prints tree postorder recursively
void BSTB::printTreePost() {
	NodeTB *tmp = root;
	if (tmp == NULL) {
		return;
	} //if
	else {
		printTreePost(root->left);
		printTreePost(root->right);
		root->getData();
	} //else
} //printTreePost() prints tree postorder
bool BSTB::search(string x) {
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
} //search(string x) Search a tree for string value x
bool BSTB::search(NodeTB *n, string x) {
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
}
NodeTB *BSTB::rotateRight(NodeTB *n){
	NodeTB *m = n->left;
	NodeTB *tmp= m->right;
	m->right = n;
	n->left = tmp;
	if(n->left->height>n->right->height){
		n->height = n->left->height + 1;
	}//if
	else{
		n->height = n->right->height + 1;
	}//else
	if(m->left->height> m->right->height){
		m->height = m->left->height +1;
	}
	else{
		m->height = m->right->height +1;
	}
	return m;
}
NodeTB *BSTB::rotateLeft(NodeTB *n){
	NodeTB *m = n->right;
	NodeTB *tmp = m->left;
	m->left = n;
	n->right = tmp;
	if(n->right->height>n->left->height){
		n->height = n->right->height +1;
	}//if
	else{
		n->height = n->left->height +1;
	}//else
	if(m->right->height>m->left->height){
		m->height = m->right->height +1;

	}//if
	else{
		m->height = m->left->height +1;
	}//else
}//rotateLeft(NodeTB *n)
void adjustBalances(NodeTB *n){

}


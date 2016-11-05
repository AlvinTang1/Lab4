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
BSTB::BSTB(){
	root = NULL;
	count = 0;
}
BSTB::~BSTB(){
 delete root->left;
 delete root->right;
 delete root;
	}
bool BSTB::insert(string x){
	NodeTB *n = new NodeTB(x);
	if(n->data>x){
		n->left->data = x;
		return true;
	}
	if(n->data<x){
		n->right->data = x;
		return true;
	}
	else{
		return false;
	}
}
bool BSTB::insert(string x, NodeTB *n){
	if(n->left == NULL || n->right ==NULL){
		if(n->data>x){
			NodeTB *tmp = new NodeTB(x);
			n->left = tmp;
			n->left->data = x;
			return true;
		}
		else if(n->data<x){
					NodeTB *tmp = new NodeTB(x);
					n->right = tmp;
					return true;
	}
	}
	if(n->data>x){
		insert(x, n->left);
	}
	if(n->data<x){
		insert(x,n->right);
	}
	else{
		return false;
	}
}
void BSTB::printTreeio(NodeTB *n){
	if(n==NULL){
		return;
	}//if
	else{
		printTreeio(n->left);
		n->getData();
		printTreeio(n->right);
	}//else
}//printTreeio(NodeTB *n)
void BSTB::printTreeio(){
	NodeTB *tmp = root;
	if(tmp==NULL){
		return;
	}//if
	else{
		printTreeio(root->left);
		root->getData();
		printTreeio(root->right);
	}//else
}//printTreeio()
void BSTB::printTreePre(NodeTB *n){
	if(n==NULL){
		return;
	}//if
	else{
		n->getData();
		printTreePre(n->left);
		printTreePre(n->right);
	}//else
}//printTree(NodeTB *n)
void BSTB::printTreePre(){
	NodeTB *tmp = root;
	if(tmp==NULL){
		return;
	}//if
	else{
		root->getData();
		printTreePre(root->left);
		printTreePre(root->right);
	}//else
}//printTreePre()
void BSTB::printTreePost(NodeTB *n){
	if(n==NULL){
		return;
	}//if
	else{
		printTreePost(n->left);
		printTreePost(n->right);
		n->getData();
	}//else
}//printTreePost(NodeTB *n)
void BSTB::printTreePost(){
	NodeTB *tmp = root;
	if(tmp==NULL){
		return;
	}//if
	else{
		printTreePost(root->left);
		printTreePost(root->right);
		root->getData();
	}//else
}//printTreePost()



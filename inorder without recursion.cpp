#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left=NULL;
	node *right=NULL;
};
node *root=NULL;

node* create(int data){
	node *nn=new node();
	nn->data=data;
	nn->left=nn->right=NULL;
	return nn;
}

node* insert(node* root,int data){
	node *nn=create(data);
	if(root==NULL)
		root=nn;
	else if(data<=root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	return root;
	
}
void inorder(node *root){
	stack<node*> s;
	node *curr=root;
	while(curr!=NULL || s.empty()==false){
		while(curr!=NULL){
			s.push(curr);
			curr=curr->left;
		}
		curr=s.top();
		s.pop();
		cout<<curr->data<<" ";
		curr=curr->right;
	}
}

int main()
{
	root=insert(root,20);
	root=insert(root,14);
	root=insert(root,8);
	root=insert(root,30);
	root=insert(root,10);
	root=insert(root,18);
	root=insert(root,25);
	inorder(root);
}

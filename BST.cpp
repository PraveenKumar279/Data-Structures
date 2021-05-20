#include<iostream>
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
	nn->left=NULL;
	nn->right=NULL;
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


bool search(node* root,int data)
{
	if(root==NULL)
		return false;
	else if(data==root->data)
		return true;
	else if(data<=root->data)
		return search(root->left,data);
	else
		return search(root->right,data);
}

int main()
{
	int n;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	cout<<"Enter no to be search:";
	cin>>n;
	if(search(root,n)==true)
		cout<<"Found"<<endl;
	else
		cout<<"Not found"<<endl;
}

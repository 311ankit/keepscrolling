//#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<queue>
using namespace std;
struct node
{
struct node *left, *right, *next;
int data;
};

int inorder(struct node *);
int lot(struct node *);
struct node *newnode(int data)
{

struct node *n = (struct node *)malloc(sizeof(struct node));
n->data=data;
n->left=NULL;
n->right=NULL;
}

int inorder(struct node *r)
{
if(r==NULL)
return 0;
inorder(r->left);
//printf("%d",r->data);
cout<<r->data;
inorder(r->right);
return 0;
}

int lot(struct node *r)
{
queue <struct node *> q;
while(r!=NULL)
{
if(r==NULL)
return 0;
cout<<r->data;
if(r->left)
q.push(r->left);
if(r->right)
q.push(r->right);
r=q.front();
q.pop();
}
return 0;
}

int con_sub(struct node *r)
{
queue <struct node *> q;
while(r!=NULL)
{
if(r==NULL)
return 0;
cout<<r->data;
if(r->left)
q.push(r->left);
if(r->right)
q.push(r->right);
if(r->left && r->right)
{
r->left->next=r->right;
r->right->next=NULL;
}
r=q.front();
q.pop();
}
return 0;

}

int tra_lev(struct node *r)
{
cout<<"----->"<<r->left->next->data;
cout<<r->right->left->next->data;
}

int main()
{
struct node *root= (struct node *)malloc(sizeof(struct node));
root->data=10;
root->left=newnode(5);
root->right=newnode(15);
root->left->left=newnode(3);
root->left->right=newnode(7);
root->right->left=newnode(12);
root->right->right=newnode(18);
inorder(root);
lot(root);
con_sub(root);
tra_lev(root);
return 0;
}

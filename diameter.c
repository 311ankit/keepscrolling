#include<stdio.h>
#include<malloc.h>

struct node
	{
		int data;
 		struct node *left,*right;
	};


struct node *new_node(int data)
{
struct node *newnode = (struct node *)malloc(sizeof (struct node));

newnode->data=data;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}

int max(int a, int b)
{
if(a>b)
return a;
else
return b;
}

void inorder(struct node *root)
{
if(root!=NULL)
{
inorder(root->left);
printf("%d",root->data);
inorder(root->right);
}
else
{
return;
}
}

int height(struct node *ht)
{
 if(ht!=NULL)
   {
    return 1+max(height(ht->left),height(ht->right));
   }
 else return 0; 
}


int diameter(struct node *t)
{
if(t!=NULL)
{
return max(1+height(t->left)+height(t->right),max(diameter(t->left),diameter(t->right)));
}
}

struct node *create()
{
struct node *root = new_node(500);
root->left= new_node(400);
root->right= new_node(600);
root->left->left= new_node(300);
root->left->right= new_node(450);
root->left->right->left= new_node(325);
root->right->right= new_node(650);
return root;
}


void main()
{
struct node *root1 = create();
inorder(root1);
printf("diameter %d",diameter(root1));

}



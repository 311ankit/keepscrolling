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

struct node *lca(struct node *root, int n1, int n2)
{
	if(root==NULL)
		{
			return NULL;
		}
	if(root->data==n1 || root->data==n2)
		{
			return root;
		}

struct node *leftlca = lca(root->left,n1,n2);
struct node *rightlca = lca(root->right,n1,n2);

	if(leftlca!=NULL && rightlca!=NULL)
		{
			return root;
		}
	if(leftlca == NULL)
		{
			return rightlca;
		}
	else 
		{
			return leftlca;
		}
}

struct node *create()
{
struct node *root = new_node(500);
root->left= new_node(400);
root->right= new_node(600);
root->left->left= new_node(300);
root->left->right= new_node(450);
root->left->right->left= new_node(425);
root->right->right= new_node(650);
return root;
}

/*
                    500
                  /     \
                400     600
               /  \        \
              300 450      650 
                   / 
                 425
*/

void main()
{
struct node *root1 = create();
inorder(root1);
int n1,n2;
printf("enter the nodes");
scanf("%d",&n1);
scanf("%d",&n2);
struct node *finallca = lca(root1,n1,n2); 
printf("lca--> %d", finallca->data);

}



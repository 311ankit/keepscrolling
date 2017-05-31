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


int hrk(struct node *root, int key, int level)
{
if(root == NULL)
{
return -1;
}
if(root->data == key)
{
return level;
}
int t= hrk(root->left, key, level+1);
if(t==-1)
{
return hrk(root->right, key, level+1);
}
else
{
return t;
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

int distancebetween2nodes(struct node *root, int n1, int n2)
{
int l1 = hrk(root,n1,0);
int l2 = hrk(root,n2,0);
int n3 = lca(root,n1,n2)->data;
int l3 = hrk(root,n3,0);

int db2n = l1 + l2 - 2*l3;
return db2n;
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
int n1,n2,key;
printf("enter the nodes");
scanf("%d",&n1);
scanf("%d",&n2);
scanf("%d",&key);
struct node *finallca = lca(root1,n1,n2);
printf("hrk--> %d", hrk(root1,key,0)); 
printf("lca--> %d", finallca->data);
printf("db2n--> %d", distancebetween2nodes(root1,n1,n2));
}



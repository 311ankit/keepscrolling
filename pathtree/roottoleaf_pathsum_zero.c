#include<stdio.h>
#include<malloc.h>
#define bool int

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


int pathsumtozero(struct node *root, int sum)
{
if(root == NULL && sum ==0)
{
return 1;
}
else
{
int cursum = sum-root->data;
bool ans = 0;
if(cursum==0 && root->left==NULL && root->right==NULL)
return 1;
if(root->left)
{
ans = ans || pathsumtozero(root->left, cursum);
}
if(root->right)
{
ans = ans || pathsumtozero(root->right, cursum);
}
return ans;
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
int sum;
printf("enter the sum");
scanf("%d",&sum);
printf("pathsum2zero--> %d", pathsumtozero(root1,sum));
}



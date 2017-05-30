#include<iostream>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};

// First Approch is we can use level order traversing and print the first element of that level for left view 
// And for right view do level order from right to left and print the first element.

//Below are the two method to via recursion



//Left view of tree 
void leftView(struct tree* root, int level, int *maxLevel){
        
    if(root == NULL)
        return;
        
        if(*maxLevel < level){
            printf("%d ", root -> data);
            *maxLevel  = level;
        }
        
    leftView(root -> left, level + 1, maxLevel);
    leftView(root -> right, level + 1, maxLevel);
}

//Right view of tree
void rightView(struct tree* root, int level, int *maxLevel){
        
    if(root == NULL)
        return;
        
        if(*maxLevel < level){
            printf("%d ", root -> data);
            *maxLevel  = level;
        }
        
    rightView(root -> right, level + 1, maxLevel);
    rightView(root -> left, level + 1, maxLevel);
}


void viewCall(struct tree* root){
    
    int maxLevel = 0;
    printf("Left view of tree ---> ");
    leftView(root, 1, &maxLevel);
    printf("\nright view of tree ---> ");
    maxLevel = 0;
    rightView(root, 1, &maxLevel);
}


struct tree* newNode (int data)
{
    struct tree *temp = new struct tree;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main()
{
    struct tree *root = NULL;

    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
 
   viewCall(root);
    return 0;
}
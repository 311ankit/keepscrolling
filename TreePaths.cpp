#include<iostream>

// find the maximum sum from root to leaf and path

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};


bool printPath(struct tree * root, struct tree *targetLeaf){
    
    if(root == NULL)
        return false;
        
        if(targetLeaf == root || printPath(root -> left , targetLeaf) || printPath(root -> right, targetLeaf)){
            printf("%d ", root -> data);
            return true;
        }
    return false;
}

void findMaxPathRootToLeaf(struct tree* root , int curSum, int* maxSum, struct tree** targetLeaf){
    
    if(root == NULL)
        return;
        
        curSum = curSum + root -> data;
        
        if(root -> left == NULL && root -> right == NULL){
            if(curSum > *maxSum){
            *maxSum = curSum;
            *targetLeaf = root;
            }
        }
        
        findMaxPathRootToLeaf(root -> left, curSum, maxSum, targetLeaf);
        findMaxPathRootToLeaf(root -> right, curSum, maxSum, targetLeaf);
}


int maxSumPath (struct tree *root)
{
    if (root == NULL)
        return 0;
 
    struct tree *targetLeaf;
    int maxSum;
    
    findMaxPathRootToLeaf (root, 0, &maxSum , &targetLeaf);
    
    printPath(root, targetLeaf); 
    
    return maxSum; 
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
 
    printf ("Following are the nodes on the maximum "
            "sum path \n");
    int sum = maxSumPath(root);
    printf ("\nSum of the nodes is %d ", sum);
    return 0;
}
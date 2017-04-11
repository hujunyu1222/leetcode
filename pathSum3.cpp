#include <iostream>

using namespace std;

/*

You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but 
it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

*/


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int sumUp(TreeNode*, int, int);

int pathSum(TreeNode *root, int sum){
    if (root == NULL){
        return 0;
    }

    return sumUp(root,0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);

}

int sumUp(TreeNode *root, int pre, int sum){
    if(root == NULL){
        return 0;
    }
    int cur = pre + root->val;

    return ((cur == sum) ? 1 : 0) + sumUp(root->left, cur, sum) + sumUp(root->right, cur, sum);
}


int main(){


    return 0;
}
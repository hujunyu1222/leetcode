#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x):val(x),left(NULL),right(NULL){}


};

TreeNode* cloneTree(TreeNode *root){
    if (root == NULL){
        return NULL;
    }

    TreeNode *newRoot = new TreeNode(root->val);
    newRoot->left = cloneTree(root->left);
    newRoot->right = cloneTree(root->right);

    return newRoot;

}

vector<TreeNode *> generate(int s, int e){
    vector<TreeNode *> res;

    if (s > e){
        res.push_back(nullptr);
    }

    for(int i = s; i <= e; i++){
        TreeNode *head = new TreeNode(i);
        vector<TreeNode *> lSub = generate(s, i - 1);
        vector<TreeNode *> rSub = generate(i + 1, e);

        for (auto l : lSub){
            for (auto r : rSub){
                head->left = l;
                head->right = r;
                res.push_back(cloneTree(head));
            }
        }
    }

    return res;


}

vector<TreeNode *> generateTrees(int n){
    return generate(1, n);
}

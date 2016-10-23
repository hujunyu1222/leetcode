#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}

};

TreeNode* change(TreeNode* node, int offset){
    if (node == NULL){
        return NULL;
    }

    TreeNode *h = new TreeNode(node->val + offset);
    h->left = change(node->left, offset);
    h->right = change(node->right, offset);

    return h;

}

vector<TreeNode*> generateTrees(int n){
    vector<vector<TreeNode*> > res(n + 1);
    int i, j, k;

    res[0].push_back(nullptr);
    if (n == 0){
        return res[0];
    }



    for (i = 1; i <= n; i++){
        for (j = 0; j < i; i++){
            for (auto l : res[j]){
                for (auto r : res[i - j - 1]){
                    TreeNode *h = new TreeNode(j+1);
                    h->left = l;
                    h->right = change(r, j+1);
                    res[i].push_back(h);
                }
            }
        }
    }

    return res[n];


}

int main(){
    generateTrees(1);

    return 0;
}




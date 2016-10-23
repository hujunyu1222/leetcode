#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x):val(x), left(NULL), right(NULL){}

};

int maxLen = -1;

void preOrder(TreeNode *head, int sum, int preSum, int level, unordered_map<int, int> &sumMap){
    if (head == NULL){
        return;
    }

    int curSum = preSum + head->val;

    if (sumMap.find(curSum) == sumMap.end()){
        sumMap[curSum] = level;
    }

    if (sumMap.find(curSum - sum) != sumMap.end()){
        maxLen = max(maxLen, level - sumMap[curSum - sum]);
    }

    preOrder(head->left, sum, curSum, level+1, sumMap);
    preOrder(head->right, sum, curSum, level+1, sumMap);

    if (sumMap[curSum] == level){
        sumMap.erase(curSum);
    }

    return;

}

void getMaxLength (TreeNode *root, int sum){
    unordered_map<int, int> sumMap;
    //添加第一项
    sumMap[0] = 0;

    preOrder(root, sum, 0, 1, sumMap);
}

int main(){
    TreeNode *root = new TreeNode(-3);
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(-9);
    TreeNode *n3 = new TreeNode(1);
    TreeNode *n4 = new TreeNode(0);
    TreeNode *n5 = new TreeNode(2);
    TreeNode *n6 = new TreeNode(1);
    TreeNode *n7 = new TreeNode(1);
    TreeNode *n8 = new TreeNode(6);

    root->left = n1; root->right = n2;
    n1->left = n3; n1->right = n4;
    n2->left = n5; n2->right = n6;
    n4->left = n7; n4->right = n8;

    getMaxLength(root, -9);

    cout << maxLen << endl;


    return 0;
}

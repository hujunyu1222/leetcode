#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 0x7FFFFFFF
#define MIN 0x80000000

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x):val(x), left(NULL), right(NULL){}

};

/*
record[0]: 最大节点数
record[1]：子树节点数最小值
record[2]: 子树节点数最大值


*/
TreeNode* posOrder(TreeNode *head, int record[3]){
    if (head == NULL){
        record[0] = 0;
        record[1] = MAX;
        record[2] = MIN;
    }

    int lSize, rSize;
    int lMin, lMax, rMin, rMax;

    int value = head->val;

    TreeNode *lBST = posOrder(head->left, record);
    lSize = record[0];
    lMin  = record[1];
    lMax  = record[2];

    TreeNode *rBST = posOrder(head->right, record);
    rSize = record[0];
    rMin  = record[1];
    rMax  = record[2];

    record[1] = min(lMin, value);
    record[2] = max(rMax, value);

    if (lBST == head->left && rBST == head->right && value > lMax && value < rMin){
        record[0] = lSize + rSize + 1;
        return head;
    }

    record[0] = max(lSize, rSize);
    return lSize > rSize ? lBST : rBST;



}

void inOrder(TreeNode *root){
    stack<TreeNode *> st;

    if (root == NULL) return;

    st.push(root);

    TreeNode *tmp = root;

    while(!st.empty() || tmp != NULL){

        if (tmp != NULL){
            st.push(tmp);
            tmp = tmp->left;
        }
        else{
            tmp = st.top();
            st.pop();
            cout << tmp->val << endl;
            tmp = tmp->right;
        }
    }

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

    return 0;
}


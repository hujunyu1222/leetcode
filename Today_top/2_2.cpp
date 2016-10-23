#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        val = 0;
        left = right = NULL;
    }
};

int cntNum(TreeNode *vRoot, int a, int m){
    int key = 0x40000000;
    TreeNode *head = vRoot;

    while(key != 0 && head != NULL){
        if (key & a != 0){
            if (head->right == NULL && head->left != NULL){
                a = a - key;
                head = head->left;
            }
            else if {
                head = head->right;
            }
        }else{
            if (head->left != NULL){
                a = a + key;
                head = head->left;
            }
            else{
                head = head->right;
            }

        }


    }


}

void InsertTree(TreeNode *vRoot, int a){
    int key = 0x40000000;
    TreeNode *head = vRoot;
    while (key != 0){
        if (key & tmp != 0 && head->left == NULL){
            head->left = new TreeNode;
            head->val++;
            head = head->left;
        }
        else if (head->right == NULL){
            head->right = new TreeNode;
            head->val++;
            head = head->right;
        }

        key = key >> 1;
    }

}


void BuildTree(TreeNode *vRoot, vector<int> &num){
    int n = nums.size();


    int key = 0x40000000;
    int tmp = num[0];


    for (int i = 1; i < n; i++){

    }



}

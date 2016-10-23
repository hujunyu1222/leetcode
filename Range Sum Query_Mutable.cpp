#include <iostream>
#include <vector>

using namespace std;

//»ù´¡Ïß¶ÎÊ÷
struct SegTreeNode{
    int start, end;
    int sum;
    SegTreeNode *left;
    SegTreeNode *right;

    SegTreeNode():sum(0){}

};

SegTreeNode* buildTree(int begin, int end, vector<int> &nums){
    SegTreeNode *root;
    root = new SegTreeNode;
    root->start = begin;
    root->end = end;

    if (begin == end){

        root->sum = nums[begin];
        root->left = NULL;
        root->right = NULL;

        return root;
    }

    root->left = buildTree(begin, (begin+end)/2, nums);
    root->right = buildTree((begin+end)/2 + 1, end, nums);

    root->sum = root->left->sum + root->right->sum;

    return root;
}

int updateSegTree(int i, int val, SegTreeNode *root){
    if (root == nullptr) return 0;

    int gap;
    if (root->start == i && root->end == i){
        gap = val - root->sum;
        root->sum = val;
        return gap;
    }

    int mid = (root->start + root->end) / 2;
    if (i > mid) gap = updateSegTree(i, val, root->right);
    else gap = updateSegTree(i, val, root->left);

    root->sum += gap;
    return gap;

}


int queryTree(int i, int j, SegTreeNode* root) {
    if (root == nullptr) return 0;
    if (root->start == i && root->end == j){
        return root->sum;
    }

    int mid = (root->start + root->end) / 2;

    if (i > mid) return queryTree(i, j, root->right);
    else if (j <= mid) return queryTree(i, j, root->left);
    else return queryTree(i, mid, root->left) + queryTree(mid+1, j, root->right);

}


int main(){
    int a[3] = {1, 3, 5};
    vector<int> nums(a, a+3);
    SegTreeNode *root = buildTree(0, 2, nums);

    cout << queryTree(0,2, root) << endl;
    updateSegTree(1, 2, root);
    cout << queryTree(0,2, root) << endl;

    return 0;
}

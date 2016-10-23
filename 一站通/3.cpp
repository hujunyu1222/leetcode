#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

struct element{
    TreeNode *t;
    int val;
};

int LongestPath = 1;


int findPath(TreeNode* root) {
    stack<element> s;
    vector<int> res;
    element start = {root,1};
    s.push(start);
    res.push_back(1);
    int maxlength = 1;
    int tmp;

    while (!s.empty()){
        element node = s.top();
        TreeNode *cur = node.t;
        tmp = node.val;
        s.pop();


        if (node.val > maxlength){
            maxlength = node.val;
        }


        if (cur->left != NULL){
            if (cur->val == cur->left->val){
                node.val = tmp + 1;

            }
            else{
                node.val = 1;
            }
            node.t = cur->left;

            s.push(node);
        }

        if (cur->right != NULL){
            if (cur->val == cur->right->val){
                node.val = tmp + 1;
            }
            else{
                node.val = 1;
            }
            node.t = cur->right;
            s.push(node);
        }

    }
    return maxlength;

}

int findPath2(TreeNode* root){
    int l, r;
    l = r = 0;
    int maxPath = 1;
    int tmp = 1;

    if (root->left != NULL){
        l = findPath2(root->left);
    }

    if (root->right != NULL){
        r = findPath2(root->right);
    }

    if (root->left == NULL && root->right == NULL){
        return 1;
    }
    else{
        if (root->left != NULL && root->left->val == root->val){
            tmp += l;
        }
        if (root->right != NULL && root->right->val == root->val){
            tmp += r;
        }

        if (tmp > LongestPath){
            LongestPath = tmp;
        }

        maxPath = max(l,r)+1;
        return maxPath;
    }

}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(1);
    TreeNode* t3 = new TreeNode(1);
    TreeNode* t4 = new TreeNode(1);
    TreeNode* t5 = new TreeNode(0);

    root->left = t1;
    root->right = t2;
    t2->left = t3;
    t3->left = t4;
    t3->right = t5;

    findPath2(root);

    cout << LongestPath;
    return 0;
}

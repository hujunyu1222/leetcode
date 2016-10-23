#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    bool isLeaf(TreeNode *node){
        return (node->left == NULL && node->right == NULL);
    }
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        cout << DFS(root, true) << endl;
        cout << DFS(root, false) << endl;

        return max(DFS(root, true), DFS(root, false));

    }

    int DFS(TreeNode* start, bool vis){
        int left = 0;
        int right = 0;
        int sum = 0;
        if (!vis){
            if (start->left != NULL){
                if (isLeaf(start->left)){
                    left = start->left->val;
                }
                else{
                    left = max(DFS(start->left, true), DFS(start->left, false));
                }
            }
            if (start->right != NULL){
                    if (isLeaf(start->right)){
                        right = start->right->val;
                    }
                    else{
                        right = max(DFS(start->right, true), DFS(start->right, false));
                    }

            }
        }
        else{
                sum += start->val;

            if (start->left != NULL){
                left = DFS(start->left, false);
            }
            if (start->right != NULL){
                right = DFS(start->right, false);
            }

        }

        return sum + left + right;
    }

};

int main(){
    TreeNode *root = new TreeNode(6);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *l2 = new TreeNode(3);
    TreeNode *l3 = new TreeNode(3);
    TreeNode *l4 = new TreeNode(1);
    TreeNode *l5 = new TreeNode(100);

    root->left = l1;
    root->right = l2;
    l1->right = l3;
    l2->right = l4;
    l3->right = l5;


    Solution cp;
    cout << cp.rob(root);
    return 0;

}

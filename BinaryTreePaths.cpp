#include <iostream>
using namespace std;

//输出树的所有路径
//以“1->2->3”,"1->2->4"的形式


//思路：以栈的形式存放Path的中间值，当遇到根节点，则将完整路径
//存进vector
//遍历的方式是类似广度优先遍历
vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        stack<string> pathStack;
        s.push(root);
        pathStack.push(to_string(root->val));

        while (!s.empty()) {
            TreeNode * curNode = s.top(); s.pop();
            string tmpPath = pathStack.top(); pathStack.pop();

            //找到叶子节点，则将完整路径存至res
            if (curNode->left == NULL && curNode->right == NULL) {
                res.push_back(tmpPath); continue;
            }

            if (curNode->left != NULL) {
                s.push(curNode->left);
                pathStack.push(tmpPath + "->" + to_string(curNode->left->val));
            }

            if (curNode->right != NULL) {
                s.push(curNode->right);
                pathStack.push(tmpPath + "->" + to_string(curNode->right->val));
            }
        }

        return res;
}
int main(){

    return 0;
}

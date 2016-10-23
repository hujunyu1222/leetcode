#include <iostream>
using namespace std;

//�����������·��
//�ԡ�1->2->3��,"1->2->4"����ʽ


//˼·����ջ����ʽ���Path���м�ֵ�����������ڵ㣬������·��
//���vector
//�����ķ�ʽ�����ƹ�����ȱ���
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

            //�ҵ�Ҷ�ӽڵ㣬������·������res
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

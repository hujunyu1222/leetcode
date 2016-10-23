#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x):val(x),left(NULL),right(NULL){}

};

//�ݹ�
vector<int> postorderTraversal1(TreeNode* root, vector<int> &res){
    if (root == NULL){
        return NULL;
    }

    postorderTraversal2(root->left);
    postorderTraversal2(root->right);
    res.push_back(root->val);

    return res;

}



//�ǵݹ�1��˫ջʵ��
vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > s1;
        stack<TreeNode* > s2;
        TreeNode *p = root;

        if (root == NULL){
            return res;
        }

        s1.push(root);

        while(!s1.empty()){
            p = s1.top();
            s1.pop();

            s2.push(p);
            if (p->left != NULL){
                s1.push(p->left);
            }
            if (p->right != NULL){
                s1.push(p->right);
            }
        }

        while(!s2.empty()){
            p = s2.top();
            s2.pop();

            res.push_back(p->val);
        }



        return res;
}

//�ǵݹ�2����ջʵ��
//h: ��һ�ε�������ӡ�Ľڵ�
//c: ջ���ڵ�
vector<int> postorderTraversal3(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > s;

        TreeNode *p = root;
        TreeNode *h, *c;

        if (root == NULL){
            return res;
        }

        s.push(root);
        h = p;

        while(!s.empty()){
            c = s.top();
            if (c->left != NULL && h != c->left && h != c->right){
                s.push(c->left);
            }
            else if (c->right != NULL && h != c->right){
                s.push(c->right);
            }
            else{
                res.push_back(c->val);
                h = c;
                s.pop();
            }
        }



        return res;
    }

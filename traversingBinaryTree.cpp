#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

//后续遍历用于标记节点
enum Tags {Left,Right};

struct element{
    TreeNode *pointer;
    Tags tag;
};

//前序遍历 非递归
void PreOrder(TreeNode *root){
    stack<TreeNode*> aStack;
    TreeNode *p = root;
    aStack.push(NULL);

    while(p != NULL){
        //先访问根
        cout << p->val;
        //右子数入栈
        if (p->right != NULL){
            aStack.push(p->right);
        }
        //左子树下降
        if (p->left != NULL){
            p = p->left;
        }
        else{
            p = aStack.top();
            aStack.pop();
        }
    }

}

//中序遍历 非递归
void InOrder(TreeNode *root){
    stack<TreeNode *> aStack;
    TreeNode *p = root;

    while (!aStack.empty() || p != NULL){
        if(p != NULL){
            aStack.push(p);
            p = p->left;
        }
        else{
            p = aStack.top();
            aStack.pop();
            cout << p->val;
            p = p->right;
        }
    }
}

//后续遍历 非递归
void PostOrder(TreeNode *root){
    stack<element> aStack;
    element node;
    TreeNode *p = root;

    while (!aStack.empty() || p != NULL){
        while(p != NULL){
            node.pointer = p;
            //左路下降，tag至左
            node.tag = Left;
            aStack.push(node);
            p = p->left;
        }

        node = aStack.top();
        aStack.pop();
        p = node.pointer;

        if (node.tag == Left){
            node.tag = Right;
            //回到栈中
            aStack.push(node);
            p = p->right;
        }
        else{
            cout << p->val;
            //置p为NULL，使其继续弹栈
            p = NULL;
        }
    }
}

int main()
{
    TreeNode A(1), B(2), C(3), D(4), E(5), F(6), G(7), H(8), I(9);
    A.left = &B;
    A.right = &C;
    B.left = &D;
    B.right = &E;
    E.left = &G;
    C.right = &F;
    F.left = &H;
    F.right = &I;

    cout <<"前序遍历：\n";
    PreOrder(&A);
    cout <<"\n中序遍历：\n";
    InOrder(&A);
    cout <<"\n后序遍历：\n";
    PostOrder(&A);
    return 0;
}



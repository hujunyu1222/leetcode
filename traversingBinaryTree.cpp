#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

//�����������ڱ�ǽڵ�
enum Tags {Left,Right};

struct element{
    TreeNode *pointer;
    Tags tag;
};

//ǰ����� �ǵݹ�
void PreOrder(TreeNode *root){
    stack<TreeNode*> aStack;
    TreeNode *p = root;
    aStack.push(NULL);

    while(p != NULL){
        //�ȷ��ʸ�
        cout << p->val;
        //��������ջ
        if (p->right != NULL){
            aStack.push(p->right);
        }
        //�������½�
        if (p->left != NULL){
            p = p->left;
        }
        else{
            p = aStack.top();
            aStack.pop();
        }
    }

}

//������� �ǵݹ�
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

//�������� �ǵݹ�
void PostOrder(TreeNode *root){
    stack<element> aStack;
    element node;
    TreeNode *p = root;

    while (!aStack.empty() || p != NULL){
        while(p != NULL){
            node.pointer = p;
            //��·�½���tag����
            node.tag = Left;
            aStack.push(node);
            p = p->left;
        }

        node = aStack.top();
        aStack.pop();
        p = node.pointer;

        if (node.tag == Left){
            node.tag = Right;
            //�ص�ջ��
            aStack.push(node);
            p = p->right;
        }
        else{
            cout << p->val;
            //��pΪNULL��ʹ�������ջ
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

    cout <<"ǰ�������\n";
    PreOrder(&A);
    cout <<"\n���������\n";
    InOrder(&A);
    cout <<"\n���������\n";
    PostOrder(&A);
    return 0;
}



#include <iostream>
#include <deque>
#include <vector>

using namespace std;

//ʹ��˫�˶���ʵ�ֶ�������ZigZag��ӡ

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<int> line;
    vector<vector<int> > res;

    deque<TreeNode*> q;
    bool lr = true;
    TreeNode *head = root;
    TreeNode *last, *nLast;

    last = head;
    nLast = NULL;

    q.push_back(head);

    if (head == NULL) return res;

    while (!q.empty()){
        if (lr){
            head = q.front();
            q.pop_front();
            //���������Һ��ӵ�˳��Ӷ�β���
            if (head->left != NULL){
                nLast = nLast == NULL ? head->left : nLast;
                q.push_back(head->left);
            }
            if (head->right != NULL){
                nLast = nLast == NULL ? head->right : nLast;
                q.push_back(head->right);
            }

        }
        else{
            head = q.back();
            q.pop_back();
            //���Һ��������ӵ�˳��Ӷ�ͷ���
            if (head->right != NULL){
               nLast = nLast == NULL ? head->right : nLast;
               q.push_front(head->right);
            }
            if (head->left != NULL){
               nLast = nLast == NULL ? head->left : nLast;
               q.push_front(head->left);
            }
        }

        line.push_back(head->val);

        if(head == last){
            lr = !lr;
            last = nLast;
            nLast = NULL;
            res.push_back(line);
            line.resize(0);
        }

    }
    return res;

}


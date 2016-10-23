#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Codec {
    void serializeByPre(TreeNode *root, stringstream &out){
        if (root == nullptr){
            out << "# ";
        }
        out << root->val << " ";
        serializeByPre(root->left, out);
        serializeByPre(root->right, out);

    }

    TreeNode* deserializeByPre(stringstream &in){
        string val;
        in >> val;
        if(val == "#"){
            return NULL;
        }

        TreeNode *head = new TreeNode(stoi(val), in);
        head->left = deserializeByPre(in);
        head->right = deserializeByPre(in);

        return head;

    }


public:


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream out;
        serializeByPre(root, out);

        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream in(data);

        return deserializeByPre(in);

    }
};
*/

//广度优先
string serialByLevel(TreeNode *root){
    if (root == NULL){
        return "#!";
    }

    string res = "";
    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()){
        TreeNode *tmp = q.front();
        q.pop();
        if (tmp != NULL){
            res += '0'+tmp->val;
        }
        else{
            res += "#!";
        }

        if (tmp == NULL) continue;

        if (tmp->left != NULL){
            q.push(tmp->left);
        }
        else{
            q.push(NULL);
        }

        if (tmp->right != NULL){
            q.push(tmp->right);
        }
        else{
            q.push(NULL);
        }

    }
    return res;

}

string serialByLevelPre(TreeNode *root){
    if (root == NULL) return "#!";

    stack<TreeNode *> s;
    s.push(root);

    string res = "";

    while(!s.empty()){
        TreeNode *tmp = s.top();
        s.pop();

        if (tmp == NULL) {
            res += "#!";
            continue;
        }
        else{
            res += '0' + tmp->val;
            res += "!";
        }

        if (tmp->right != NULL){
            s.push(tmp->right);
        }
        else{
            s.push(NULL);
        }

        if (tmp->left != NULL){
            s.push(tmp->left);
        }
        else{
            s.push(NULL);
        }


    }
    return res;
}


int main(){
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);

    root->left = n1; root->right = n2;
    n2->left = n3; n2->right = n4;


    cout << serialByLevelPre(root) << endl;

    //Codec codec;
    //codec.deserialize(codec.serialize(root));

    //cout << codec.serialize(root) << endl;


    return 0;
}

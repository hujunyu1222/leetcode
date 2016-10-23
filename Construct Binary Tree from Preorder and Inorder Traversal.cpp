#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* DFSbuild(vector<int> &pre, int ps, int pe, vector<int> &in, int is, int ie){
    int i, j;
    if (pe - ps < 0 || ie - is < 0) return NULL;

    TreeNode *root = nullptr;

    for (i = is; i <= ie; i++){
        if (in[i] == pre[ps]){
            root = new TreeNode(in[i]);
            root->left = DFSbuild(pre, ps+1, ps + i - is, in, is, i-1);
            root->right = DFSbuild(pre, ps + i - is+1, pe, in, i+1, ie);
            break;
        }
    }

    return root;

}

int main(){
    TreeNode *root = nullptr;
    int apre[10] = {5,4,2,1,3,6,8,7,9,10};
    int ain[10] = {1,2,3,4,5,6,7,8,9,10};

    vector<int> pre(apre, apre+10);
    vector<int> in (ain, ain+10);

    root = DFSbuild(pre, 0, 9, in, 0, 9);

    cout << root->val << root->left->val << root->right->val;


    return 0;


}

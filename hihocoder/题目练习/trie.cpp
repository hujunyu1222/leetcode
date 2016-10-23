#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int cnt;
    Node *nxt[26];

    Node():cnt(0){
        memset(nxt, 0, sizeof(nxt));
    }

};

void insert(Node *root, string &s){
    Node *head = root;
    for (int i = 0; i < s.size(); i++){
        int idx = s[i] - 'a';
        if (head->nxt[idx] == NULL){
            head->nxt[idx] = new Node;
        }
        head = head->nxt[idx];
        head->cnt++;
    }

}

int query(Node *root, string &s){
    Node *head = root;
    for (int i = 0; i < s.size(); i++){
        int idx = s[i] - 'a';
        if (head->nxt[idx] == NULL){
            return 0;
        }
        head = head->nxt[idx];
    }

    return head->cnt;

}

int main(){
    freopen("trie.txt", "r", stdin);

    int n, m;
    string dictS, queryS;

    Node *root = new Node;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> dictS;
        insert(root, dictS);
    }

    cin >> m;

    for (int i = 0; i < m; i++){
        cin >> queryS;
        cout << query(root, queryS) << endl;
    }





    return 0;
}

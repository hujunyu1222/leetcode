#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_CHILD 26
struct Trie{
    int count;
    Trie *child[MAX_CHILD];
};

Trie* creatNode(){
    Trie *node = new Trie();
    memset(node, 0, sizeof(Trie));
    return node;
}

void insertNode(Trie *root, char *str){
    Trie *t = root;
    while((*str) != '\0'){
        if (t->child[(*str) - 'a'] == NULL){
            Trie *node = creatNode();
            t->child[(*str) - 'a'] = node;
        }
        t = t->child[(*str) - 'a'];
        str++;
    }

    t->count++;
}

bool searchNode(Trie *root, char *str){
    if(NULL==root || *str=='\0')
    {
        cout << "trie is empty or str is null\n" << endl;
        return false;
    }

    Trie *t = root;
    while ((*str) != '\0'){
        if (t->child[(*str) - 'a'] != NULL){
            t = t->child[(*str) - 'a'];
            str++;
        }
        else{
            break;
        }
    }

    if ((*str) != '\0'){
        cout << "Can't Find the word!" << endl;
        return false;
    }
    else if (t->count == 0){
        cout << "It's a substr of a word!" << endl;
        return false;
    }
    else{
        cout << "Find the word!" << endl;
        return true;
    }


}

//递归释放整个Trie树占的堆空间
void del(Trie *root)
{
    int i;
    for(i=0;i<MAX_CHILD;i++)
    {
     if(root->child[i]!=NULL)
            del(root->child[i]);
    }
    delete root;
}

int main(){
    char word[100];
    Trie *root = creatNode();
    int n;
    int i;

    cin >> n;
    cout << "Tire树插入word：" << endl;
    for (i = 0; i < n; i++){
        cin >> word;
        cout << word << endl;
        insertNode(root, word);
    }

    cout << "Tire树查找word：" << endl;

    cin >> word;
    searchNode(root, word);

    del(root);





    return 0;
}

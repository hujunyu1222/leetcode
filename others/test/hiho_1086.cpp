#include <iostream>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include <cstdio>

using namespace std;

//
struct Node{
    string url;
    Node *pre;
    Node *next;
    Node(string key):url(key){}
};

class List{
private:
    Node *head;
    Node *tail;

public:

    List():head(NULL),tail(NULL){}

    //add new Node to the tail
    void addNode(Node *newNode){
        if (newNode == NULL){
            return;
        }
        else if (this->head == NULL){
            this->head = newNode;
            this->tail = newNode;
        }
        else{
            this->tail->next = newNode;
            newNode->pre = this->tail;
            this->tail = newNode;
        }
    }

    //move the Node to the tail (newest)
    void moveToTail(Node *p){
        if (p == tail){
            return;
        }
        else if (p == head){
            head = p->next;
            head->pre = NULL;
        }
        else{
            p->pre->next = p->next;
            p->next->pre = p->pre;
        }

        tail->next = p;
        p->pre = tail;
        p->next = NULL;
        tail = p;
    }

    //remove the node from head, and return the node's pointer.
    Node* removehead(){
        if (head == NULL){
            return NULL;
        }
        Node *res = head;
        if (head == tail){
            head = tail = NULL;
        }
        else{
            head = res->next;
            res->next->pre = NULL;
            res->next = NULL;
            
        }

        return res;

    }

};

class MyCache{
private:
    int cSize;
    List cacheList;
    unordered_map<string, Node*> keyNodeMap;
    unordered_map<Node*, string> nodeKeyMap;

public:

    MyCache(int n): cSize(n){}

    void removeMostUnusedCache(){
        Node *removeNode = cacheList.removehead();
        string key = nodeKeyMap[removeNode];
        keyNodeMap.erase(key);
        nodeKeyMap.erase(removeNode);
        // release memory
        delete removeNode;
    }

    void get(string key){
        Node *tmp = NULL;
        if (keyNodeMap.find(key) != keyNodeMap.end()){
            cout << "Cache" << endl;
            tmp = keyNodeMap[key];
            cacheList.moveToTail(tmp);
        }
        else{
            cout << "Internet" << endl;
            tmp = new Node(key);
            keyNodeMap[key] = tmp;
            nodeKeyMap[tmp] = key;
            cacheList.addNode(tmp);
            if (keyNodeMap.size() == cSize + 1){
                removeMostUnusedCache();
            }
        }

    }
};

int main(){

    freopen("1086.txt","r", stdin);

    int N, M;
    string queryUrl;
    cin >> N >> M;
    MyCache mC(M);

    for (int i = 0; i < N; i++){
        cin >> queryUrl;
        mC.get(queryUrl);
    }

    system("pause");
    return 0;
}

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode *a, ListNode *b){
    ListNode *head, *cur;
    ListNode dummy(0);
    head = cur = &dummy;
    //����������������
    while(a!=NULL && b!=NULL){
        if (a->val > b->val){
            cur->next = b;
            b = b->next;
            cur = cur->next;
        }
        else{
            cur->next = a;
            a = a->next;
            cur = cur->next;
        }
    }

    cur->next = (a==NULL)? b : a;

    return head->next;
}

ListNode* sortList(ListNode* head) {
    ListNode *a, *b;

    if(head == NULL || head->next == NULL){
        return head;
    }

    a=b=head;

    //������������
    while(b->next && b->next->next){
        a = a->next;
        b = b->next->next;
    }
    b = a->next;
    a->next = NULL;

    //�������򣺵ݹ�
    return merge(sortList(head),sortList(b));

}

int main(){
    ListNode L(10);

    cout<<L.val<<endl;
    return 0;
}

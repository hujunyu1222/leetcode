#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}

};


//�ж������Ƿ��ֻ�����Ѱ������Ļ�����ڡ�
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA==NULL || headB==NULL) return NULL;
    if (headA==headB) return headA;
    ListNode *tailA=headA;
    while (tailA->next!=NULL){
        tailA=tailA->next;
    }
    tailA->next = headB;
    ListNode *slow=headA,*fast=headA;
    while (fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if (slow==fast){
            fast = headA;
            while (fast!=slow){
                fast = fast->next;
                slow = slow->next;
            }
            tailA->next = NULL;
            return fast;
        }
    }
    tailA->next = NULL;
    return NULL;
}

int main(){
    return 0;
}

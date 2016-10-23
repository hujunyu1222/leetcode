#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *cur;
    ListNode *left, *right, *pre;
    ListNode *temp;
    int count = 1;

    left = right = pre = NULL;
    cur = head;

    if (head == NULL || head->next == NULL){
        return head;
    }

    while (count <= n){
        // m = 1 & m > 1
        if(m == 1 && count == 1){
            right = cur;
            pre = cur;
            cur = cur->next;
            count ++;
        }
        else if (count == m -1){
            left = cur;
            cur = cur->next;
            right = cur;
            pre = left;
        }

        if (count >= m){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;

            count ++;
        }
        else{
            pre = cur;
            cur = cur->next;
            count ++;
        }
    }

    if (m == 1){
        right->next = cur;
        head = pre;
    }
    else{
        left->next = pre;
        right->next = cur;
    }
    return head;

}


//使用dummy节点，不需要再考虑拆成 m=1和m>1的情况。
ListNode* reverseBetweenBetter(ListNode* head, int m, int n) {
        ListNode zero(0);
        ListNode *dummy = &zero;  dummy->next = head;
        ListNode *prev = dummy, *cur = head, *conn0=prev, *newTail = cur;
        for (int i=0; i<m-1; ++i) {
            prev = cur;  conn0 = prev;
            cur = cur->next;  newTail = cur;
        }
        for (int i=0; i<n-m+1; ++i) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        conn0->next = prev;
        newTail->next = cur;
        return dummy->next;
    }


int main(){

    return 0;
}

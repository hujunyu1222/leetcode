#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    ListNode dummy(INT_MIN), *cur, *temp;
    cur = &dummy;
    while(head){
            if(cur->val>head->val) cur = &dummy; // trick, reset cur only when needed ��֦��cur����ÿ�ζ������ڱ��ڵ�
            for (;cur->next && cur->next->val < head->val;) cur=cur->next;
            temp = head->next;
            head->next = cur->next;
            cur->next = head;
            head = temp;
    }
    return dummy.next;

int main(){

    return 0;
}

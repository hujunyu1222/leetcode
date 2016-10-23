#include <iostream>
using namespace std;



 struct ListNode {
      int val;
      ListNode *next;
      ListNode() {}
      ListNode(int x, ListNode * nxt) : val(x), next(nxt) {}
 };

 //递归的方法
 ListNode* mergeTwoListsRecur(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoListsRecur(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoListsRecur(l1, l2->next);
        return l2;
    }
}

//非递归方法
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newhead;
        ListNode *cur;
        ListNode dummy(-1);

        newhead = cur = &dummy;

        if (l1 == NULL || l2 == NULL){
            newhead->next = (l1 == NULL ? l2 : l1);
            return newhead->next;
        }

        while(l1 != NULL && l2 != NULL){
            if (l1->val < l2->val){
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }

        }

        cur->next = (l1 == NULL ? l2 : l1);

        return newhead->next;

}

int main(){

    return 0;
}

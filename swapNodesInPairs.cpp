#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

//递归解法
ListNode* swapPairsRecur(ListNode* head) {
        ListNode *cur, *beh;

        if (head == NULL || head->next == NULL){
            return head;
        }

        cur = beh = head;

        if (cur !=NULL && beh != NULL){
            beh = cur->next;
            cur->next = swapPairsRecur(beh->next);
            beh->next = cur;
            //cur = cur->next;
        }

        return beh;

}

//非递归
ListNode* swapPairs(ListNode* head) {

    ListNode *cur = head,*beh = head->next;

    if (!head || !(head->next) )    return head;
    head = head->next;//说明总个数不止1一个，改变head
    while(beh){
        beh = beh->next;//next->3
        cur->next->next =cur;//2->1

        if(!beh || !(beh->next)) {
            cur->next = beh;//1->3;
            return head;
        }

        cur->next = beh->next;//否则 1->4
        cur = beh;// cur ->3
        beh = beh->next;//next->4  最终 2->1->4 3->4->5->6...
    }
    return head;
}

int main(){

    return 0;
}


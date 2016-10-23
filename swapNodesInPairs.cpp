#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

//�ݹ�ⷨ
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

//�ǵݹ�
ListNode* swapPairs(ListNode* head) {

    ListNode *cur = head,*beh = head->next;

    if (!head || !(head->next) )    return head;
    head = head->next;//˵���ܸ�����ֹ1һ�����ı�head
    while(beh){
        beh = beh->next;//next->3
        cur->next->next =cur;//2->1

        if(!beh || !(beh->next)) {
            cur->next = beh;//1->3;
            return head;
        }

        cur->next = beh->next;//���� 1->4
        cur = beh;// cur ->3
        beh = beh->next;//next->4  ���� 2->1->4 3->4->5->6...
    }
    return head;
}

int main(){

    return 0;
}


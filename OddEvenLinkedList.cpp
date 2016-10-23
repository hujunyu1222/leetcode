#include <iostream>
using namespace std;



 struct ListNode {
      int val;
      ListNode *next;
      ListNode() {}
      ListNode(int x, ListNode * nxt) : val(x), next(nxt) {}
 };

 ListNode* oddEvenList(ListNode* head) {
        ListNode *oddp, *evenp;
        ListNode *otail, *etail;

        if (head == NULL || head->next == NULL){
            return head;
        }

        oddp = head;
        evenp = head->next;

        otail = evenp;
        etail = NULL;


        while(evenp !=NULL && evenp->next != NULL ){
            oddp->next = evenp->next;
            evenp->next = oddp->next->next;

            oddp = oddp->next;
            etail = evenp;
            evenp = evenp->next;
        }
        oddp->next = otail;
        if(evenp !=NULL){
            evenp->next = NULL;
        }
        else{
            etail->next = NULL;
        }

        return head;



}


 int main() {
    ListNode* a1 = new ListNode(1, NULL);
    ListNode* a2 = new ListNode(2, NULL);
    ListNode* a3 = new ListNode(3, NULL);
    ListNode* a4 = new ListNode(4, NULL);
    ListNode* head;
    a1 ->next = a2;
    a2 ->next = a3;
    a3 ->next = a4;

    head = oddEvenList(a1);
    while(head!=NULL){
        cout<<head->val<<" -> ";
        head = head->next;
    }
    cout<<"NULL";

    return 0;
}

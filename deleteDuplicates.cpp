#include <iostream>
using namespace std;



 struct ListNode {
      int val;
      ListNode *next;
      ListNode() {}
      ListNode(int x, ListNode * nxt) : val(x), next(nxt) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre, *cur, *beh;
        ListNode *ini;
        ListNode dummy(0, NULL);

        int curVal = 0;

        pre = &dummy;



        if(head == NULL || head->next == NULL){
            return head;
        }
        cur = head;
        curVal = cur->val;




        beh = cur->next;


        while(cur !=NULL){
            if (beh!=NULL && cur->val == beh->val){
                curVal = cur->val;

                while(beh!=NULL && beh->val == curVal){
                    beh = beh->next;
                }
                if (beh!=NULL){
                    cur = beh;
                    beh = beh->next;
                }
                else {
                    pre->next = NULL;
                }
            }
            else {

                if (cur->next == beh){
                    pre->next = cur;
                    //cout<<cur->val<<endl;
                    pre = cur;
                }
                cur = beh;
                if (beh != NULL)
                {
                    beh = beh->next;
                }

            }
        }

        pre->next = NULL;

        return dummy.next;

    }
};

int main() {
    ListNode* a1 = new ListNode(1, NULL);
    ListNode* a2 = new ListNode(2, NULL);
    ListNode* a3 = new ListNode(3, NULL);
    ListNode* a4 = new ListNode(4, NULL);
    ListNode* head;
    a1 ->next = a2;
    a2 ->next = a3;
    a3 ->next = a4;

    Solution op;
    head = op.deleteDuplicates(a1);
    while(head!=NULL){
        cout<<head->val<<" -> ";
        head = head->next;
    }
    cout<<"NULL";

    return 0;
}

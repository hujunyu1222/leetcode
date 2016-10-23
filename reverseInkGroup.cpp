#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

//递归方法
ListNode* reverseKGroupRecur(ListNode* head, int k) {
        ListNode *cur, *beh;
        ListNode *temp;
        int i = 0;
        cur = head;

        if (head == NULL || head->next == NULL){
            return head;
        }

        beh = cur->next;

        for (i=0; i<k; i++){
            if (cur == NULL){
                return head;
            }
            cur = cur->next;
        }

        cur = head;
        //cout << "pass" << endl;
        for (i=0; i<k-1; i++){
            temp = beh->next;
            beh->next = cur;
            cur = beh;
            beh = temp;
        }
        //cout << beh->val;
        head->next = reverseKGroupRecur(beh, k);

        return cur;

}
//非递归
//先算出分成几个group
ListNode* reverseKGroup(ListNode* head, int k)
{
    int len =  listLen(head), times = len / k;
    if (head == NULL || times <= 0) {
        return head;
    }
    ListNode *p1, *p2, *p3, *ansHead = head, *tail = head;
    while (times --) {
        p1 = head;
        p2 = p1 -> next;
        p1 -> next = NULL;
        int cnt = 0;
        while (p2 && cnt ++ < k - 1) {
            p3 = p2 -> next;
            p2 -> next = p1;
            p1 = p2;
            p2 = p3;
        }
        //判断是否为第一个group，是则确定整个链表的头部
        if(times == len / k - 1){
            ansHead = p1;
        }
        //连接相邻两个group
        else{
            tail -> next = p1;
            tail = head;
        }
        head = p2;

    }
    while (head) {
        tail -> next = head;
        tail = tail -> next;
        head = head -> next;
    }
    return ansHead;
}

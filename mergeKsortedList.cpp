#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

bool compare(ListNode *a, ListNode *b){
    return (a->val > b->val);

}

//利用最小堆求解
ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector <ListNode*> heapList;
    ListNode *pre, *cur;
    ListNode *top;

    pre = new ListNode(-1);
    cur = pre;

    int k = lists.size();
    int i = 0;
    for (i=0; i<k; i++){
        if(lists[i] != NULL){
            heapList.push_back(lists[i]);
        }
    }
    //构建最小堆
    make_heap(heapList.begin(), heapList.end(), compare);

    while (!heapList.empty()){

        top = heapList.front();
        cur->next = top;
        cur = cur->next;
        //堆做完pop操作，其实将元素放到了最后一个
        //所以需要用heapList再pop一次。
        pop_heap(heapList.begin(), heapList.end(), compare);
        heapList.pop_back();

        top = top->next;
        if (top != NULL){
            heapList.push_back(top);
            push_heap(heapList.begin(), heapList.end(), compare);
        }

    }

    return pre->next;

}

ListNode* mergeKListsDiv(vector<ListNode*>& lists){
    ListNode *newhead = NULL;
    int n = lists.size();
    if (n == 0){
        return NULL;
    }
    else{
        return mergeLists(lists, 0, n-1);
    }

}

ListNode* mergeLists(vector<ListNode*>& lists, int begin, int end){
    int mid = 0;
    ListNode *first, *second;
    if (begin > end) return NULL;
    if (begin == end) return lists[begin];

    mid = begin + (end - begin)/2;

    first = mergeLists(lists, begin, mid);
    second = mergeLists(lists, mid+1, end);

    return mergeTwoList(first, second);


}


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


    vector<struct ListNode> list;
    ListNode *temp = NULL;
    ListNode a1(10);
    ListNode a2(91);
    ListNode a3(15);
    ListNode a4(9);
    ListNode a5(41);

    list.push_back(a1);
    list.push_back(a2);
    list.push_back(a3);
    list.push_back(a4);
    list.push_back(a5);






    vector<struct ListNode>::iterator iter = list.begin();
    for (iter; iter != list.end(); iter++){
        cout << iter->val << endl;
    }


    return 0;
}


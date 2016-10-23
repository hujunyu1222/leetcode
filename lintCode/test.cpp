#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> reverseQ(vector<int> &nums){
    deque<int> q;

    int n = nums.size();
    int i;

    q.push_back(nums[n-1]);


    int tail, head;
    vector<int> res(n);

    for (i = n - 2; i >= 0; i--){
        tail = q.back();
        q.pop_back();
        q.push_front(nums[i]);
        q.push_front(tail);
    }

    i = 0;
    while(!q.empty()){
        res[i++] = q.front();
        q.pop_front();
    }

    return res;
}

int main(){
    vector<int> nums{1,2,3,4,5,6,7};
    vector<int> res = reverseQ(nums);

    for (auto x:res){
        cout << x << ",";
    }

    return 0;
}

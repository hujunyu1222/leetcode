#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first + a.second > b.first + b.second ? true : false;
}


vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1, n2;

        n1 = nums1.size();
        n2 = nums2.size();

        vector<pair<int, int> > res;
        vector<pair<int, int> > heap;
        int i, j;

        for (i = 0; i < n1; i++){
            for (j = 0; j < n2; j++){
                pair<int, int> tmp = make_pair(nums1[i], nums[j]);
                heap.push_back(tmp);
            }
        }

        make_heap(heap.begin(), heap.end(), compare);

        while(k && !heap.empty()){
            res.push_back(heap.front());
            pop_heap (heap.begin(),heap.end(), compare);
            heap.pop_back();
        }

        return res;

}

int main(){

    return 0;
}

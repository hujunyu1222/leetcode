#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//默认以第一个数为轴
int partition(vector<int> &nums, int s, int e){
    if (s == e){
        return s;
    }

    int i, j;
    int pivot = nums[s];
    i = s;

    for (j = i+1; j <= e; j++){
        if (nums[j] < pivot){
            swap(nums[j], nums[++i]);
        }
    }

    swap(nums[s], nums[i]);

    return i;


}

int findKth(vector<int> &nums, int s, int e, int k){
    if (s == e){
        return nums[s];
    }

    int index = partition(nums, s, e);
    //cout << "s:"<<s<< "e:" << e << " "<< index << endl;
    if ( (index - s) == k - 1){
        return nums[index];
    }
    else if ((index - s) > k - 1){
        return findKth(nums, s, index - 1, k);
    }
    else{
        return findKth(nums, index + 1, e, k - (index - s + 1));
    }


}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return findKth(nums, 0, n - 1, n - k + 1);
}

int main(){
    vector<int> nums{3,2,1,5,6,4};
    //partition(nums, 0, 5);
    /*
    for (auto x:nums){
        cout << x << endl;
    }
    */

    cout << findKthLargest(nums, 1);

    int k = 1;

    //库提供的quickSelect
    //greater<int>() : 让其变成从大到小排列
    //从小到大则是（求第k小的）：nth_element(nums.begin(), nums.begin() + k - 1, nums.end());
    nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());


    return 0;
}

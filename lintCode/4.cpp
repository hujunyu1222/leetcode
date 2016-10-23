#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//øÏ≈≈
int partition(vector<int> &nums, int p, int q){
    int pivot = nums[p];
    int index = p;

    for (int j = p + 1; j <= q; j++){
        if (nums[j] <= pivot){
            swap(nums[++index], nums[j]);
        }
    }

    swap(nums[p],nums[index]);

    return index;
}

void quickSort(vector<int> &nums, int s, int e){
    if (s >= e) return;

    int p = partition(nums, s, e);
    quickSort(nums, s, p-1);
    quickSort(nums, p+1, e);

}

int main(){
    vector<int> nums{5,8,1,3,6,12,54,41,18,22};
    quickSort(nums, 0, nums.size()-1);

    for (auto x:nums){
        cout << x << ",";
    }

    return 0;
}

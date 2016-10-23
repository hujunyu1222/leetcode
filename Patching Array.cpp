#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int minPatches(vector<int> &nums, int n) {
    long miss = 1, cnt = 0, i = 0;
    long nSize = nums.size();
    while(miss <= n){
        if (i < nSize && nums[i] <= miss){
            miss += nums[i];
        }
        else{
            miss <<= 1;
            cnt++;
        }
    }

    return cnt;

}


int main(){

    return 0;
}

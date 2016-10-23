#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define INT_MIN 0x80000000

//不大于k的最大子数组累加和
int findSubarr(vector<int> &line, int k){
        int n = line.size();
        vector<int> pre_sum(n, 0);
        set<int> s;
        set<int>::iterator it;

        int sum = 0;
        int i;
        int maxSum = INT_MIN;

        s.insert(0);

        for (i = 0; i < n; i++){
            sum += line[i];
            pre_sum[i] = sum;
            it = s.lower_bound(pre_sum[i] - k);
            if ( it != s.end()){
                maxSum = max(maxSum, pre_sum[i] - *it);
            }

            s.insert(pre_sum[i]);
        }

        return maxSum;

}


int main(){
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << findSubarr(nums, -2);


    return 0;
}

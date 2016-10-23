#include <iostream>
#include <vector>

using namespace std;

//DP 时间复杂度O(n^2)
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;

        vector<int> dp(n,1);

        int i, j;
        int tmp = 0;
        int maxLength = 1;

        for (i = 0; i < n; i++){
            for (j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    tmp = max(dp[i], dp[j] + 1);
                    dp[i] = tmp;
                    if (tmp > maxLength){
                        maxLength = tmp;
                    }
                }

            }
        }


        return maxLength;


}

//解法2：单调队列，时间复杂度O(n*logn)
int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;

        vector<int> array;
        array.push_back(nums[0]);

        int i, length;
        int l, r, mid;

        for (i = 1; i < n; i++){
            l = 0;
            r = array.size() - 1;
            while (l <= r){
                mid = (l + r) / 2;
                if(array[mid] < nums[i]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }

            if (array[mid] > nums[i]){
                array[mid] = nums[i];
            }
            else if (array[mid] < nums[i] && mid == array.size() - 1){
                array.push_back(nums[i]);
            }
            else{
                array[mid+1] = nums[i];
            }

        }

        return array.size();


}

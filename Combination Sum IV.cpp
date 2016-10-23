#include <iostream>
#include <vector>

using namespace std;

#define INT_MAX 0x7FFFFFFF


int combinationSum4(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> dp(target+1, 0);

    dp[0] = 1;
    int i, j;
    for (i = 1; i <= target; i++){
        for (j = 0; j < n; j++){
            if (i - nums[j] >= 0){
                dp[i] += dp[i - nums[j]];
            }
        }
    }

    return dp[target];


}

//±©Á¦µÝ¹é
int dfs(vector<int> &nums, int target){
    if (target == 0){
        return 1;
    }


    int n = nums.size();
    int i;
    int res = 0;

    for (i = 0; i < n; i++){
        if (target - nums[i] >= 0){
            res += dfs(nums, target - nums[i]);
        }
    }

    return res;

}


int main(){
    vector<int> nums{1,2,3};

    int res = dfs(nums, 6);
    cout << res << endl;

    cout << combinationSum4(nums, 6) << endl;

    return 0;
}

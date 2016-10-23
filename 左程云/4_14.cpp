#include <iostream>
#include <vector>

using namespace std;

int maxFirst(vector<int> &nums){
    int n = nums.size();

    vector<vector<int> > f(n, vector<int>(n, 0));
    vector<vector<int> > s(n, vector<int>(n, 0));

    int i, j;
    for (j = 0; j < n; j++){
        f[j][j] = 1;
        for (i = j - 1; i >= 0; i--){
            f[i][j] = max(nums[i] + s[i+1][j], nums[j] + s[i][j-1]);
            s[i][j] = min(f[i+1][j], f[i][j-1]);
        }
    }

    return max(f[0][n-1], s[0][n-1]);
}


int main(){
    int a[] = {1, 2, 100, 4};
    vector<int> nums(a, a+4);
    cout << maxFirst(nums);

    return 0;
}

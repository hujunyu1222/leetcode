#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
//函数规律
int integerBreak(int n) {
    int res = 1;

    if (n <= 3){
        res = n - 1;
        return res;
    }

    while(n > 4){
        res *= 3;
        n -= 3;
    }

    res *= n;

    return res;
}
*/
//动归
int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], (max(j, dp[j]) * max(i - j, dp[i - j])));
            }
        }
        return dp[n];
}

int main(){
    int n;
    while (cin >> n){
       cout << integerBreak(n) << endl;
    }

    return 0;
}

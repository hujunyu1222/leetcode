#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INT_MAX 0x7FFFFFFF

int getMoneyAmount(int n) {
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

    int i, j, k;

    for (i = 1; i <= n; i++){
        for (j = i - 1; j >= 1; j--){
            int mixValue = 0x7FFFFFFF;
            for (k = j; k <= i; k++){
                int maxValue = k + max(dp[j][k-1], dp[k+1][i]);
                minValue = min(maxValue, minValue);
            }

            dp[j][i] = minValue;
        }
    }

    return dp[1][n];
}


int getMoneyAmount2(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = 1; i <= n; ++i){
            for (int j = i - 1; j >= 1; --j){
                int min_value = INT_MAX;
                for (int k = j; k <= i; ++k){
                    int tmp = k + max(dp[j][k - 1], dp[k + 1][i]);
                    min_value = min(min_value, tmp);
                }
                dp[j][i] = min_value;
            }
        }
        return dp[1][n];
}

int main(){
    cout << getMoneyAmount(12);
    cout << getMoneyAmount2(124);


    return 0;
}

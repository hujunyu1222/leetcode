#include <iostream>
#include <bits/stdc++.h>

using namespace std;


const int mx = 1e3 + 7;

int MOD = 799999;

int dp[mx][mx] = {0};


int solve(int n){

    int res = 0;

    for (int s = 0; s < 3; s++){
        memset(dp, 0, sizeof(dp));
        dp[1][s] = 1;
        for (int i = 2; i <= n ; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    if (k != j){
                        dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                    }
                }
            }

        }

        for (int e = 0; e < 3; e++){
            if (e != s){
                res += dp[n][e];
            }
        }
    }


    return res;

}


int main(){
    int n = 5;

    cout << solve(n) << endl;

    return 0;
}

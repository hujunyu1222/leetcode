#include <iostream>
#include <string>
#include <vector>

using namespace std;


int minHP(){
    int mp[3][3] = {{-2, -3, 3}, {-5, -10, 1}, {0, 30, -5} };
    int i, j;

    int dp[3][3] = {0};

    dp[2][2] = mp[2][2] >= 0 ? 1 : -mp[2][2] + 1;

    for (i = 1; i >= 0; i--){
        dp[i][2] = mp[i][2] >= dp[i+1][2] ? 1 : dp[i+1][2] - mp[i][2];
    }
    for (j = 1; j >=0; j--){
        dp[2][j] = mp[2][j] >= dp[2][j+1] ? 1 : dp[i][j+1] - mp[2][j];
    }

    for (i = 1; i >= 0; i--){
        for (j = 1; j >= 0; j--){
            if (mp[i][j] >= min(dp[i+1][j], dp[i][j+1]) - 1){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = min(dp[i+1][j] - mp[i][j], dp[i][j+1] - mp[i][j]);
            }
        }
    }

    return dp[0][0];
}

int main(){
    cout << minHP();
    return 0;
}

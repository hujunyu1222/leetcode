#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5 + 7;

struct Node{
    int val;
    float f;

};

int main(){
    long long dp[mx] = {0};
    int n;

    while(cin >> n){
        int k, m4, m7;
        m4 = m7 = 0;
        k = 1;
        while(k <= n){
            long long minTmp = min(dp[m4]*10 + 4, dp[m7]*10 + 7);
            dp[k++] = minTmp;
            if (minTmp == dp[m4]*10 + 4){
                m4++;
            }

            if (minTmp == dp[m7]*10 + 7){
                m7++;
            }
        }

        cout << dp[n] << endl;
    }


    return 0;
}

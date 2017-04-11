#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <memory.h>


using namespace std;

#define MAX_COLS 5
const int MOD = 1e9 + 7;

int dp[2][1 << MAX_COLS]; 
int N, M, curr;
int up[1 << MAX_COLS];
int f[]={3,6,12,24,15,27,30};



int main(){

    cin >> N >> M;
    if (N < M)
    {
        int tmp = N;
        N = M;
        M = tmp;
    }
    curr = 0;
    int state = (1 << M) - 1;
    dp[0][state] = 1;

    

    for (int i = 1; i <= N; i++)
    {
        curr = curr ^ 1;
        memset(dp[curr], 0, sizeof(dp[curr]));

        for (int j = 0; j <= state; j++)
        {
            dp[curr][j] = (dp[curr][j] + dp[1 -curr][state ^ j]) % MOD;

            for (int k = 0; k < 7; k++){
                if (f[k] > state || (f[k] & j)) continue;
                up[f[k] | j]  = (up[f[k] | j] + dp[curr][j]) % MOD;  
            }
        }

        for(int j = 0; j <= state; j++){
            dp[curr][j] = (dp[curr][j] + up[j]) % MOD;
            up[j]=0;
        }
    }

    printf("%d\n", dp[curr][state]);

    system("pause");
    return 0;

}
#include <iostream>
#include <string>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <algorithm>

using namespace std;

const int mx = 1e3 + 7;
const int maxM = 10;
int w[mx];
int dp[mx][(1 << maxM) - 1];

int N, M, Q;

int maxProfit = -1;

int countOne(int n){
    int cnt = 0;
    while(n){
        n = n & (n - 1);
        cnt++;
    }

    return cnt;
}

const int b[11]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

int f[2][1024];
int cnt[1024];

// AC code
int compare(){
    //for (int i=1; i<=N; ++i) cin >> w[i];
    memset(f, 0, sizeof f);
    cnt[0]=0;cnt[1]=1;
    for (int i=2; i<b[M]; ++i) cnt[i]=cnt[i>>1]+cnt[i&1];
    for (int i=1; i<=N; ++i)
        for (int j=0; j<b[M]; ++j) if (cnt[j]<=Q)
            f[i&1][j]=max(f[(i&1)^1][j>>1], f[(i&1)^1][(j>>1)+b[M-1]])+(j&1)*w[i];
    int ans=0;
    for (int j=0; j<b[M]; ++j)
        ans=max(ans, f[N&1][j]);
    
    return ans;
}

int foo(int a, int b){
    char * c;
    c = (char*)a;

    return (int)&c[b];
}

int main(){
    freopen("hiho_1044.txt","r",stdin);

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++){
        cin >> w[i];
    }

    int state = (1 << M) - 1;
    int offset = 1 << (M - 1);

    //dp[0][(1<< (M - 2))] = w[1];

    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= state; j++){
            //if ( (i < M - 1) && ((j & (-j)) < (1 <<(M - i - 1))) ) continue;
            int newState = (j>> 1) + offset;
            if ( countOne(newState) <= Q){
                dp[i][newState] = max(dp[i][newState], dp[i-1][j] + w[i]);
            }
            if (countOne(j >> 1) <= Q){
                dp[i][j >> 1] = max(dp[i][j >> 1], dp[i-1][j]);
            }
        }
    }

    for (int j = 0; j <= state; j++){
        maxProfit = max(maxProfit, dp[N][j]);
    }
    
    cout << maxProfit << endl;

    cout << compare() << endl;

    //cout << foo(2,3) << endl;

    system("pause");
    return 0;
}
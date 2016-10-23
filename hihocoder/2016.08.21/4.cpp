#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 7;


int m[15][15];
int F[MAX];
int main(){
    int N, M;

    freopen("4.txt","r", stdin);

    cin >> N >> M;
    memset(m,0,sizeof(m));
    memset(F,0,sizeof(F));

    for (int i = 0; i < N; i++){
        int w, p;
        cin >> w >> p;
        //多重背包：计算总件数
        m[w][p]++;
    }

    int maxP = 0x80000000;

    for (int W = 1; W <= 10; W++){
        for (int P = 1; P <= 10; P++){
            int sum = m[W][P];

            int k = 1;
            while(k <= sum){
                //01packet
                for (int i = M; i - k*W >= 0;i--){
                    F[i] = max(F[i], F[i - k*W]+k*P);
                }
                sum -= k;
                k = k * 2;
            }
            if (sum){
                //01packet
                for (int i = M; i - sum*W >= 0;i--){
                    F[i] = max(F[i], F[i - sum*W]+k*P);
                }
            }

            maxP = max(maxP, F[M]);
        }
    }

    cout << maxP << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <windows.h>

using namespace std;

template <class T>
void Print(vector<T> &v){
    for (auto x:v){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    int K;
    freopen("4.txt", "r", stdin);
    cin >> K;

    vector<double> p(K,0.0);
    vector<int>  a(K,1);
    vector<vector<double>> dp(2, vector<double>(1<<K,0));



    int i, j;
    int sum = 0;
    double eps = 10e-6;
    int res = (1<<K) - 1;
    int cur, pre;

    for (i = 0; i < K; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (i = 0; i < K; i++){
        p[i] = (1.0 *a[i]) / sum;
    }
    //需要这个初始值来初始化走第一步的概率
    dp[1][0] = 1;


    int step = 0;
    double ans = 0.0;

    cur = 1; pre = 0;
    while(true){
        swap(cur,pre);//用于不停地滚动、迭代
        for (i = 0; i < 1<<K; i++){
                dp[cur][i] = 0;
            for (j = 0; j < K; j++){
                if ((1<<j) & i){
                    dp[cur][i] += dp[pre][i] * p[j];
                    dp[cur][i] += dp[pre][i^(1<<j)] * p[j];
                }
            }
        }
        for(auto x:dp[cur]){
            cout << x << "|";
        }
        cout << endl;

        step++;
        //cout << step << " "<<dp[cur][res] << endl;
        //Sleep(1000);
        ans += dp[cur][res]*step;
        if (dp[cur][res]*step != 0 && dp[cur][res]*step < eps) break;
        dp[cur][res] = 0;

    }

    printf("%.6f\n", ans);


    return 0;
}

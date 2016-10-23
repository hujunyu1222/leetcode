#include <iostream>
#include <bits/stdc++.h>

using namespace std;


//01 packet problem without optimization
int maxPrice(vector<int> &weight, vector<int> &price, int volume){
    int wL, pL;

    wL = weight.size();
    pL = price.size();

    vector<vector<int> > dp(wL, vector<int>(volume+1, 0));

    int i, j;
    for (j = 1; j <= volume; j++){
        if (weight[0]<=j){
            dp[0][j] = price[0];
        }
    }

    for (i = 1; i < wL; i++){
        for (j = 1; j <= volume; j++){
            dp[i][j] = dp[i-1][j];
            if (j - weight[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j - weight[i]] + price[i]);
            }
        }
    }

    return dp[wL-1][volume];

}
//N: the number of the products
//M: the capacity of the Packet
int N, M;

//01 packet
void ZeroOnePack(vector<int> &F, int weight_i, int price_i){
    for (int i = M; i >= weight_i; i--){
        F[i] = max(F[i], F[i - weight_i] + price_i);
    }
}

//complete packet
void CompletePack(vector<int> &F, int weight_i, int price_i){
    //Notice: the index 'i' begin in weight_i and end in M (different from 01pack problem)
    for (int i = weight_i; i <= M; i++){
        F[i] = max(F[i], F[i - weight_i] + price_i);
    }
}

//MultiplePack
//sum is the total number of the product_i
void MultiplePack(vector<int> &F, int weight_i, int price_i, int sum){
    if (sum * weight_i >= M){
        CompletePack(F, weight_i, price_i);
        return ;
    }

    int k = 1;
    while(k <= sum){
        //optimize the Time Complexity to O(log(sum))
        ZeroOnePack(F, weight_i*k, price_i*k);
        sum -= k;
        k = k * 2;
    }
    if (sum){
        ZeroOnePack(F, weight_i*sum, price_i*sum);
    }
}

const int mx = 1e7 + 7;

int main(){

    freopen("D:\\leetcode\\hihocoder\\2016.08.21\\4.txt", "r", stdin);

    vector<int> weight;
    vector<int> price;

    //int N, M;
    int maxP = 0x80000000;
    vector<int> F(mx,0);

    while(cin >> N >> M){

        weight = vector<int>(N,0);
        price = vector<int>(N,0);

        for (int i = 0; i < N; i++){
            cin >> weight[i] >> price[i];
        }

        for (int i = 0; i < N; i++){
            ZeroOnePack(F, weight[i], price[i]);
        }

        cout << F[M] << endl;

        cout << maxPrice(weight, price, M) << endl;
    }

    return 0;
}

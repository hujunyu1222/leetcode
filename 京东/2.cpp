#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long f(int x){
    long long res = 0;
    while(x != 0){
        res += x % 10;
        x = x / 10;
    }

    return res;

}

long long g(int x){
    long long res = 0;

    while(x != 0){
        if (x & 1 == 1){
            res += 1;
        }

        x = x >> 1;
    }

    return res;

}

int main(){
    int T;
    int n,cnt;

    long long dp[100005];

    for (int i = 1; i <= 100000; i++){
        if(f(i) == g(i)){
            dp[i] = dp[i-1] + 1;
        }
        else{
            dp[i] = dp[i-1];
        }
    }


    cin >> T;

    while(T--){
        cin >> n;

        cout << dp[n] << endl;

    }




    return 0;
}

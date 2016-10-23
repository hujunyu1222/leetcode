#include <iostream>
#include <cmath>

using namespace std;

int dp[501] = {0};

int cal(int n){
    int result = 0;
    int step = 3;
    while (n - step > 0){
        result += n - step;
        step += 2;
    }
    return result;
}

void init(){
    dp[1] = 1;
    int i;
    for (i = 2; i <= 500; i++){
        dp[i] = dp[i-1] + i*(i-1)/2 + cal(i) + 2*i - 1;
    }

}

long long calTri(int n){
    return dp[n];

}

int main(){
    init();
    int k;
    while (cin >> k){
       cout << calTri(k) << endl;
    }



    return 0;
}

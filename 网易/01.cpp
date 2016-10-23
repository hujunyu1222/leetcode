#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int num[105];
int N;

int solve(){
    cin >> N;
    int i;
    int sum, res;
    int avgApple;

    sum = 0;
    res = 0;

    for (i = 0; i < N; i++){
        cin >> num[i];
        sum += num[i];
    }

    avgApple = sum / N;
    if (sum % N != 0) return -1;

    for (i = 0; i < N; i++){

            if (abs(avgApple - num[i]) % 2 != 0) return -1;

            res += abs(avgApple - num[i]) / 2;
    }


    return res / 2;
}

int main(){
    cout <<solve() << endl;

    return 0;
}

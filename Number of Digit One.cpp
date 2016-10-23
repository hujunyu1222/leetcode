#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int countDigitOne(int n) {
    int round, weight, former;
    int base = 1;
    int res = 0;

    former = 0;

    while(n){
        weight = n % 10;
        round = n / 10;

        if (weight == 0){
            res += round * base;
        }
        else if (weight == 1){
            res += round * base + former + 1;
        }
        else{
            res += (round + 1) * base;
        }

        former = weight * base + former;
        base *= 10;
        n = n / 10;
    }

    return res;

}

int main(){
    int n;
    cin >> n;

    cout << countDigitOne(n) << endl;



    return 0;
}

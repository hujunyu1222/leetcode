#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long

ll passLine(ll A, ll B, ll K){
    ll a, b, gap;
    a = A * 10;
    b = B * 10;
    gap = 5;

    ll tS = a;
    ll aS = b + gap;

    for (int i = 0; i < K - 1; i++){
        if (tS < aS){
            tS += a;
        }
        else{
            aS += b;
        }
    }


    return tS < aS ? 0 : 1;
}

int main(){
    ll A, B, K;
    cin >> A >> B >> K;

    if (passLine(A, B, K)) cout << "Aoki\n";
    else cout << "Takahashi\n";

    return 0;
}

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long A, B;

int main(){
    long minFare, maxFare;
    long cnt = 0;
    while (cin >> A >> B){
        cnt = 0;
        if (A >= B || A < 5) {
            cout << cnt << endl;
            continue;
        }
        minFare = ceil(A / 0.95);
        maxFare = long(A / 0.90);
        //cout << minFare << " " << maxFare << endl;
        long i = minFare;
        while(i % 5 != 0 )i++;
        while(i <= B && i <= maxFare){
            if (i != A){
              cnt++;
            }

            i = i + 5;
        }
        cout << cnt << endl;

    }

    return 0;
}

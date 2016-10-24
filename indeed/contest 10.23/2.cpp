#include <iostream>

using namespace std;


int main(){
    int K, T;
    long long maxN = -1;
    long long sum, tmp;

    sum = tmp = 0;

    cin >> K >> T;

    for (int i = 0; i < T; i++){
        cin >> tmp;
        if (tmp > maxN){
            maxN = tmp;
        }

        sum += tmp;

    }

    long long res = 2 * maxN - sum - 1;

    if (res <= 0){
        cout << "0" << endl;
    }
    else{
        cout << res << endl;
    }

    return 0;
}

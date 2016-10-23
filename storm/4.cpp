#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll S, r, ret = 0;
    while (cin >> S) {
        ret = 0;
        r = ceil(sqrt(S));
        for (ll i = 1; i < r; i++) {
            ll j = sqrt(S - i * i);
            if (i * i + j * j == S || i * i + (j + 1) * (j + 1) == S || i * i + (j - 1) * (j - 1) == S)
                ret ++;
        }
        ret = (ret + 1) * 4;
        if (r * r != S) ret -= 4;
        cout << ret << endl;
    }
    return 0;
}




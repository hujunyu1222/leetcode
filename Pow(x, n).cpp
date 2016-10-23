#include <iostream>
#include <string>

using namespace std;

string repeat(string s, int n){
    string res;
    while (true){
        if (n % 2 == 1){
            res += s;
        }
        if (n == 1){
            return res;
        }
        s += s;
        n /= 2;
    }
    return res;
}

double myPow(double x, int n) {
        double res = 1.0;
        long long N = 0;
        bool flag = true;
        N = n;
        if (N < 0) flag = false;
        N = abs(N);

        if (N == 0 || x == 1.0) return res;

        while (true){
            if (N & 1){
                res *= x;
            }
            if (N == 1){
                if (flag){
                   return res;
                }
                else{
                    return 1.0 / res;
                }

            }
            x *= x;
            N >>= 1;
        }

}


int main(){
    cout << repeat("kid", 5);
    return 0;
}



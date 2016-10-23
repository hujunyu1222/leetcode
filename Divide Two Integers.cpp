#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == 0xFFFFFFFF){
        if (divisor == 1) return dividend;
        if (divisor == -1) return 0x7FFFFFFF;
    }


    int dd = abs(dividend);
    int ds = abs(divisor);
    int i, res;

    res = 0;

    while(dd > ds){
        int tmp = ds;
        for (i = 0; tmp <= dd; i++){
            dd = dd - tmp;
            res += 1 << i;
            tmp = tmp << 1;
        }
    }



    return (dividend ^ divisor)>>31 ? -res : res;
}

int main(){
    cout << divide(8,3);
    return 0;
}

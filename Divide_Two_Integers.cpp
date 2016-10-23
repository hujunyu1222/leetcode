#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
    if (divisor == 0){
        return 0x7FFFFFFF;
    }

    if (dividend < divisor){
        return 0;
    }

    int res = 0;

    while (dividend - divisor >= 0)
    {
        divisor += divisor;
    }


}

int main(){

    return 0;
}

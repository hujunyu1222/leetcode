#include <iostream>
#include <cmath>

using namespace std;

//Use Newton method
// X_{n+1} = X_{n} - (f(X_{n}) / f'(X_{n}))
int mySqrt(int x) {
    double g = x;
    //Newton method
    while (abs(g*g - x) > 0.000001){
        g = (g + x / g) / 2;
    }

    return (int)g;
}

int main(){
    cout << mySqrt(2);
    return 0;
}

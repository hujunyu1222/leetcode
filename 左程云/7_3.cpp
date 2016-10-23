#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int multi(int a, int b){
    int res = 0;
    int sign = ((a >> 31) & 1) ^ ((b >> 31) & 1);

    a = abs(a);
    b = abs(b);

    while(b != 0){
        if (b & 1){
            res += a;
        }
        b = b >> 1;
        a = a << 1;
    }

    return sign == 1 ? ~res+1 : res;

}

int divide(int a, int b){
    //change a and b into positive number

    int res = 0;

    for (int i = 31; i >= 0; i--){
        if ((a >> i) >= b){
            res |= 1 << i;
            a =  a - (b << i);
        }

    }

    return res;


}

int main(){
    cout << multi(2, -13) << endl;
    cout << divide(68, 4) << endl;

    return 0;
}

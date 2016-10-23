#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
        int tmp = 0x40000000;
        int res = 0;


        while(tmp != 0 && (tmp & n) == 0){
            tmp = tmp >> 1;
        }

        while(tmp != 0 && ((tmp & m) == (tmp & n)) ){
            if ((tmp & m ) != 0){
                res += tmp;
            }
            tmp = tmp >> 1;
        }

        return res;
}

int main(){
    int tmp = 0x40000000;
    int n = 7;

    /*
    while (tmp != 0){
        cout << tmp << endl;
        tmp = tmp >> 1;
    }
    */

    cout << rangeBitwiseAnd(5,5) << endl;





    return 0;
}

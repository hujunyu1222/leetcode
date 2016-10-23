#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long quickSqrt(long long h){
    long long i = 0;
    long long l, r, mid, tmp;

    l = 0;
    r = h;
    tmp = 0;

    while(l <= r){
        mid = (l + r) / 2;
        tmp = mid * mid;
        if (tmp == h){
            return mid - 1;
        }
        else if (tmp > h){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    tmp = mid * mid;
    if(tmp > h){
       tmp = (mid - 1)*mid;
       return tmp > h ? mid - 2 : mid - 1;
    }
    else{
        tmp = (mid + 1) * mid;
        return tmp > h ? mid - 1 : mid;
    }


}

int main(){
    long long A;

    cin >> A;

    cout << quickSqrt(A) << endl;

    return 0;
}

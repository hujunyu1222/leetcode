#include <iostream>
#include <bits/stdc++.h>

using namespace std;


long long minStep(long long x){
    x = abs(x);

    long long tmp = (-1 + sqrt(1 - 4 * 1*(-2 * x))) / 2;


    if ((tmp*(tmp+1)) / 2 > x) tmp--;
    //cout << tmp << endl;

    long long res;

    res = 2 * (x - (tmp*(tmp+1)) / 2) + tmp;
    tmp++;
    res = min(res, 2 * ((tmp*(tmp+1)) / 2 - x) + tmp);


    return res;

}

int main(){
    long long x;

    while(cin >> x){
      cout << minStep(x) << endl;
    }




    return 0;
}

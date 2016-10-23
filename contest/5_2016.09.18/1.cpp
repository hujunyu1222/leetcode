#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findNthDigit(int n) {
    long long base = 9;
    long long tmp = n, cnt = 1;

    while ((tmp - base*cnt) > 0){
        tmp = tmp - base*cnt;
        cnt++;
        base = base *10;
    }


    long long num = ceil(1.0*tmp / cnt);

    long long remain = tmp % cnt;
    int res = 0;

    num = pow(10, cnt-1) + num - 1;
    cout << num << ":" << remain << endl;
    if (remain == 0){
        return num % 10;
    }
    else{
        while(remain){
            res = num / (pow(10, cnt-1));
            num = num % (int)(pow(10, cnt-1));
            cnt--;
            remain--;
        }
    }

    return res;




}

int main(){
    int n;
    cin >> n;

    cout << findNthDigit(n) << endl;


    return 0;
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cntZero(int n){
    int cnt = 0;
    int tmp = 5;

    while (n / tmp != 0){
        cnt += n / tmp;
        tmp = tmp * 5;
    }

    return cnt;

}

int main(){
    int num;
    cin >> num;

    cout << cntZero(num);

    return 0;
}

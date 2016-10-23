#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int digitCounts(int k, int n) {
    // write your code here
    int cnt = 0, base = 1, num = 0;
    int pre = 0, end = 0;

    if (n == 0) return k == 0 ? 1 : 0;

    while(n){
        num = n % 10;
        pre = n / 10;

        if (num < k){
            cnt += pre * base;
        }
        else if (num == k){
            cnt += pre * base + end + 1;
        }
        else{
            cnt += (pre + 1) * base;
        }
        end = num * base + end;
        base *= 10;

        n = n / 10;
    }

    return cnt;

}


//ËûÈË´úÂë
int digitCounts2(int k, int n) {
        int count = 0;
        int base = 1;
        while (n / base >= 1) {
            int curBit = n % (base*10) / base;
            int higher = n / (base*10);
            int lower = n % base;
            if (curBit < k) {
                count += higher * base;
            }
            else if (curBit == k) {
                count += higher * base + lower + 1;
            }
            else {
                count += (higher + 1) * base;
            }
            base *= 10;
        }
        return count;
}


int main(){
    cout << digitCounts(1,21345) << endl;
    cout << digitCounts2(0,0) << endl;

    return 0;
}

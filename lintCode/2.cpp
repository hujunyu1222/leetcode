#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long trailingZeros(long long n) {
        long long i;
        long long cnt = 0;
        for (i = 1; (long long)pow(5,i) <= n; i++){
            cnt += n / (long long)pow(5,i);
        }

        return cnt;
}

void fun(int (*a)[10]){
    cout << "Size: " << (*a)[0] << endl;
}

int main(){
    vector<int> v{1,3,5,7,9};

    vector<int>::iterator it;
    it = lower_bound(v.begin(), v.end(), 0);
    cout << *it << endl;

    it = upper_bound(v.begin(), v.end(), 0);
    cout << *it << endl;

    return 0;
}

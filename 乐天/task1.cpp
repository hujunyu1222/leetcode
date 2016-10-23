#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) {

    const int mx = 100005;
    vector<int> cnt(mx, 0);
    for (int i = 0; i < (int) A.size(); i++)
        cnt[A[i]] ++;
    for (int i = 0; i < mx; i++) {
        if (cnt[i]) {
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] = cnt[i] % 2;
        }
    }
    int ret = 0;
    for (int i = 0; i < mx; i++)
        if (cnt[i]) ret ++;

    return ret;
}




int main(){
    vector<int> A{0,1};

    cout << solution(A);

}

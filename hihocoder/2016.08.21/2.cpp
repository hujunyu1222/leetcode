#include <iostream>
#include <bits/stdc++.h>

using namespace std;




const int mx = 1e4;

int high[mx];
int N, M, L;

bool canFix(int x) {
    vector<int> res;

    for(int i = 0; i < N; i++){
        if(high[i] >= x){
            res.resize(0);
            for(int j = (i + 1) % N; j != i; j = (j + 1) % N)
                res.push_back(high[j]);

            int cnt = 0;

            for(int k = 0; k < res.size(); ){
                if(res[k] < x){
                    cnt ++;
                    k += L;
                }
                else k++;
            }
            if(cnt <= M) return true;
        }
    }
    return false;
}


int main() {
    cin >> N >> M >> L;

    int tallest = 0;
    int res = 0;
    for(int i = 0; i < N; i++){
        cin >> high[i];
        tallest = max(tallest, high[i]);
    }
    int l = 0, r = tallest;
    int mid;

    while(l + 1 < r){
        mid = (l + r) >> 1;
        if(canFix(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    res = canFix(r) ? r : l;

    cout << res << endl;

    return 0;
}

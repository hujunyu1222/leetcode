#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lowbit(int num){
    int cnt = 0;
    while (num != 0){
        num -= num & (-num);
        cnt++;
    }

    return cnt;
}

vector<string> hour(int n){
    vector<string> res;
    string s;

    for (int i = 0; i <= 12; i++){
        if (lowbit(i) == n){
            s = to_string(i);
            res.push_back(s);
        }
    }

    return res;

}

vector<string> minute(int n){
    vector<string> res;
    string s;

    for (int i = 0; i <= 59; i++){
        if (lowbit(i) == n){
            if (i < 10) s += '0';
            s += to_string(i);
            res.push_back(s);
        }
    }

    return res;

}

int main(){
    int n;

    vector<string> res;
    vector<string> h;
    vector<string> m;

    for (int i = 0; i <= n; i++){
        h = hour(i);
        m = minute(n - i);
        for (int j = 0; j < h.size(); j++){
            for (int k = 0; k < m.size(); k++){
                string tmp = h[j] + ':' + m[k];
                res.push_back(tmp);
            }
        }

        h.resize(0);
        m.resize(0);
    }


    return 0;
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


vector<int> getNext(string s){
    int n = s.size();

    vector<int> next(n+1, 0);


    next[0] = -1;
    next[1] = 0;

    int pos, cn;

    pos = 2;
    cn = 0;

    while(pos <= s.size()){
        if (s[pos - 1] == s[cn]){
            next[pos++] = ++cn;
        }
        else if (cn == 0){
            next[pos++] = 0;
        }
        else{
            cn = next[cn];
        }

    }
    return next;
}

int cntMatch(string &s, string &m){
    vector<int> next = getNext(m);

    int i, j;
    i = j = 0;
    int sizeS, sizeM;

    sizeS = s.size();
    sizeM = m.size();

    int cnt = 0, start = 0;

    for (i = 0, j = 0; i < sizeS; i++){
        if (j < sizeM && s[i] == m[j]){
            j++;
        }
        else{
            while(j > 0){
                j = next[j];
                if (s[i] == m[j]){
                    j++;
                    break;
                }
            }
        }

        if (j == sizeM) {
            cnt++;
        }

    }



    return cnt;

}

int main(){

    freopen("KMP.txt", "r", stdin);

    int N;
    string s, m;

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> m >> s;
        cout << cntMatch(s, m) << endl;
    }




    return 0;
}


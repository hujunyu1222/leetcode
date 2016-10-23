#include <iostream>
#include <bits/stdc++.h>

using namespace std;


vector<int> getNextArray(string &ms){
    vector<int> next;
    int n = ms.size();
    if (n == 0) return next;
    if (n == 1){
        next.push_back(-1);
        return next;
    }

    next = vector<int>(n, 0);
    next[0] = -1;
    next[1] = 0;

    int pos = 2;
    //cn: 要比较的那个字符
    int cn = 0;
    while(pos < n){
        if (ms[pos-1] == ms[cn]){
            next[pos++] = ++cn;
        }
        else if (cn > 0){
            cn = next[cn];
        }
        else{
            next[pos++] = 0;
        }
    }

    return next;


}

int KMP(string &s, string &m){
    if (s.size() < m.size()){
        return -1;
    }

    vector<int> next = getNextArray(m);
    int i, j;
    int index = 0;
    i = j = 0;
    while(i < s.size() && j < m.size()){
        if (s[i] == m[j]){
            i++;
            j++;
        }
        else if (next[j] == -1){
            i++;
        }
        else{
            j = next[j];
        }
    }

    return j == m.size() ? i - m.size() : -1;

}


int main(){
    string s= "abc1bdabc1";
    string m = "bda";

    cout << KMP(s, m);


    return 0;
}

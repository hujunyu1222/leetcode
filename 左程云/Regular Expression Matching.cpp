#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//
bool isValid(string s){
    int n = s.size();
    int i;

    for (i = 0; i < n; i++){
        if (s[i] == '*' && (i == 0 || s[i-1] == '*')){
            return false;
        }
    }

    return true;
}

bool process(string &s, string &e, int si, int ei){
    if(ei == e.size()){
        return si == s.size();
    }

    //
    if (ei + 1 == e.size() || (e[ei + 1] != '*')){
        return (si != s.size() && (s[si] == e[ei] || e[ei] == '.') && process(s, e, si+1, ei+1) );
    }
    //when e[ei+1] == '*'
    while(si != s.size() && (s[si] == e[ei] || e[ei] == '.')){
        if (process(s, e, si, ei + 2)){
            return true;
        }
        si++;
    }

    return process(s, e, si, ei +2 );

}

bool isMatch(string s, string p) {
    if (s == NULL || p == NULL){
        return false;
    }

    return process(s, p, 0, 0);
}


int main(){

    return 0;
}

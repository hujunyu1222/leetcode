#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//暴力递归
bool process(string &s, string &p, int si, int pi){
        if (pi == p.size()){
            return si == s.size();
        }

        if (p[pi] == s[si] || p[pi] == '?'){
            return process(s, p, si+1, pi+1);
        }
        else if (p[pi] == '*'){
            while(si <= s.size()){
                if (process(s, p, si, pi+1)){
                    return true;
                }
                si++;
            }

            return false;
        }
        else{
            return false;
        }
}

//DP
//时间消耗很大
bool isMatchDP(string s, string p) {
    int M, N;
    M = s.size();
    N = p.size();


    vector<vector<bool> > dp(M+1, vector<bool>(N+1, false));
    int i, j;

    dp[0][0] = true;

    for (j = 1; j <= M; j++){
        if (p[j-1] != '*' ){
            break;
        }
        dp[0][1] = true;
    }


    for (i = 1; i <= M; i++){
        for (j = 1; j <= N; j++){
            if (p[j-1] == '*'){
                //这步没太懂
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else if ((s[i - 1] == p[j - 1]) || p[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }

    return dp[M][N];


}

//更好的做法
bool isMatch(string s, string p){
    int startS, startP;
    startS = startP = -1;
    int ss, ps;

    ss = ps = 0;
    while(ss != s.size()){
        if (s[ss] == p[ps] || p[ps] == '?'){
            ++ss;
            ++ps;
            continue;
        }

        if (p[ps] == '*'){
            while(p[ps] == '*'){
                ps++;
            }
            startS = ss;
            startP = ps;

            continue;
        }

        //说明前面存在'*'
        if (startP != -1){
            ps = startP;
            ss = (++startS);
            continue;
        }

        return false;

    }

    while(p[ps] == '*')ps++;

    return ps == p.size();


}

int main(){
    string s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    string p = "a*******b";

    if (isMatch(s, p)){
        cout << "True\n";
    }
    else{
        cout << "False\n";
    }

    return 0;
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//'.'
//'*'

//递归方法
bool process(string &s, string &e, int si, int ei){
    if (ei == e.size()){
        return si == s.size();
    }

    if (ei + 1 == e.size() || e[ei+1] != '*'){
        return si < s.size() && (s[si] == e[ei] || e[ei] == '.')
                && process(s, e, si+1, ei+1);
    }


    while (si < s.size() && (s[si] == e[ei] || e[ei] == '.')){
        if(process(s, e, si, ei+2)){
            return true;
        }
        si++;
    }


    return process(s, e, si, ei+2);


}

//动态规划
//DP solution
bool isMatchDP(string &s, string &e){
    int M, N;
    M = s.size();
    N = e.size();

    vector<vector<int> > dp(M + 1, vector<int>(N + 1, 0));



    dp[M][N] = 1;
    int i, j;


    cout << "1" << endl;

    for (j = N - 1; j >= 0; j--){
        if ((N - j) % 2 == 0){
            if (e[j+1] == '*'){
                dp[M][j] = dp[M][j + 2];
            }
        }
    }
    cout << "2" << endl;

    if ((M - 1 >= 0) && (N - 1 >= 0) && ((s[M-1] == e[N-1]) || (e[N-1] == '.')) ){
        dp[M-1][N-1] = 1;
    }

    cout << "3" << endl;

    for (i = M - 1; i >= 0; i--){
        for (j = N - 2; j >= 0; j--){
            if (s[i] == e[j] || e[j] == '.'){
                dp[i][j] = dp[i+1][j+1];
            }
            if (dp[i][j] == 0 && e[j+1] == '*'){
                for (int k = i; k <= M; k++){
                    dp[i][j] = dp[k][j+2];

                    if (k!= M && s[k] != e[j] && e[j] != '.'){
                        break;
                    }
                    if (dp[i][j] == 1){
                        break;
                    }
                }
            }
        }
    }




    return dp[0][0] == 1 ? true : false;



}

//正向DP
bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, 0));

        dp[0][0] = true;
        for (int i = 1; i <= (int)p.size(); i++) dp[0][i] = p[i - 1] == '*' && dp[0][i - 2];
        for (int i = 1; i <= (int)s.size(); i++) {
            for (int j = 1; j <= (int)p.size(); j++) {
                if (p[j - 1] == '*') dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (p[j - 2] == '.' || s[i - 1] == p[j - 2])); // 取0次或1+次
                else dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
        return dp[s.size()][p.size()];
}

int main(){
    string s = "";
    string e = ".";
    if (isMatchDP(s,e)){
        cout << "True\n";
    }
    else{
        cout << "False\n";
    }


    return 0;
}

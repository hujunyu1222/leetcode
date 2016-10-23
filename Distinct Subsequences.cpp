#include <iostream>
#include <string>
#include <vector>

using namespace std;

int process(string &S, string &T, int ss, int se, int ts, int te){
    if (ts > te){
        return 1;
    }

    int i;
    int res = 0;
    for (i = ss; i < se - (te - ts)+1; i++){
        if (T[ts] == S[i]){
            res += process(S, T, i+1, se, ts + 1, te);
        }
    }

    return res;

}

//dp
int process2(string &S, string &T){
    int i, j;
    vector<vector<int> > dp(S.size()+1, vector<int>(T.size()+1, 0));
    /*dp[i][j]的含义：
    S(0~i-1)包含多少种T(0~j-i)的组成。
    为什么是i-1和j-1，因为加入了空串的处理
    */


    for(i = 0; i <= S.size(); i++){
        dp[i][0] = 1;
    }
    for(j = 1; j <= T.size(); j++){
        dp[0][j] = 0;
    }

    for (j = 1; j <= T.size(); j++){
        for (i = j; i <= S.size(); i++){
            if (T[j-1] == S[i-1]){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    for (i = 0; i <= S.size(); i++){
        for (j = 0; j <= T.size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }


    return dp[S.size()-1][T.size()-1];


}


int main(){
    string S = "a";
    string T = "b";

    cout << process(S, T, 0, S.size()-1, 0, T.size()-1) << endl;
    cout << process2(S,T);
    return 0;
}

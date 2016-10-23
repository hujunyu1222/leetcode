#include <iostream>
#include <string>
#include <vector>

using namespace std;
int cal(char a, char b){
    return (a - '0')*10 + (b - '0');
}
//处理长度大于等于2的s
int numDecodings(string s) {
    vector<int> dp(s.size());
    int i = 0;

    if (s[0] != '0'){
        dp[0] = 1;
    }
    else{
        return 0;
    }
    if (s.size() > 1){

        if (cal(s[0], s[1]) % 10 == 0 && (s[0] != '1' && s[0] != '2')){
                return 0;
        }
        else if (cal(s[0], s[1]) == 10 || cal(s[0], s[1]) == 20){
            dp[1] = 1;
        }
        else if (cal(s[0], s[1]) >= 11 && cal(s[0], s[1]) <= 26){
            dp[1] = 2;
        }
        else{
            dp[1] = 1;
        }
    }

    for (i = 2; i < s.size(); i++){
        if (cal(s[i-1], s[i]) % 10 == 0 && (s[i-1] != '1' && s[i-1] != '2')){
            return 0;
        }
        else if (cal(s[i-1], s[i]) == 10 || cal(s[i-1], s[i]) == 20){
            dp[i] = dp[i-2];
        }
        else if (cal(s[i-1], s[i]) >= 11 && cal(s[i-1], s[i]) <= 26){
             dp[i] = dp[i-2] + dp[i-1];
        }
        else{
            dp[i] = dp[i-1];
        }
    }

    return dp[s.size() - 1];

}

int main(){
    int n;
    string s = "1121";
    n = numDecodings(s);
    cout << n <<endl;

    return 0;
}

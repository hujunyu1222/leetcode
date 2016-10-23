#include <iostream>
#include <string>
#include <vector>

using namespace std;

int num(string &str){
    int n = str.size();
    int i;
    vector<int> dp(n+1, 0);

    if (str[0] == '0') return 0;
    dp[1] = dp[0] = 1;
    for (i = 2; i <= n; i++){
        int tmp = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');
            if (tmp <= 26 && tmp > 10){
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else if (tmp <= 10){
                dp[i] = dp[i - 2];
            }
            else if (tmp > 26 && tmp % 10 != 0){
                dp[i] = dp[i - 1];
            }
            else{
                return 0;
            }
    }

    return dp[n];

}

int main(){
    string a = "221";

    cout << num(a) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INT_MAX 0x7FFFFFFE

int minCut(string s) {
        if(s=="") return 0;
        int sz = s.size(), i = 0;
        vector<int> dp(sz,INT_MAX);
        dp[0] = 0;
        //dp[i]表示子串0~i的最小回文划分
        while(i<sz){
            int j = i;
            while(s[i] == s[j+1])j++;

            for (int k = i; k <= j; k++){
                for (int m = k; m <= j; m++){
                    dp[m+1] = min(dp[m+1],dp[k]+1);
                }
            }
            int l, r;
            l = i - 1;
            r = j+1;
            while(l >=0 && r < sz && s[l] == s[r]){
                ++r;
                dp[r] = min(dp[r], dp[l--]+1);
            }

            i = j+1;
        }

        return dp[sz]-1;
}

int main(){

    cout << minCut("acbba") << endl;

    return 0;
}

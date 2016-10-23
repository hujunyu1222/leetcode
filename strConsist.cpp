#include <iostream>
#include <string>

using namespace std;

//×Ö·û´®str1, str2½»´í×é³Éstr3
bool isCross(string &a, string &b, string &tar){
    bool *dp = new bool[b.size() + 1];
    int i, j;
    dp[0] = true;

    bool tmp = true;

    if (tar.size() != a.size() + b.size()) return false;

    for (j = 1; j <= b.size(); j++){
        if (tar[j-1] != b[j - 1]){
            tmp = false;
        }
        dp[j] = tmp;
    }

    for (i = 1; i <= a.size(); i++){
        dp[0] = dp[0] && (a[i-1] == tar[i - 1]);
        for (j = 1; j <= b.size(); j++){
            if ((dp[j] && (a[i - 1] == tar[i+j-1])) ||
                (dp[j - 1] && (b[j - 1] == tar[i+j-1]))){

                dp[j] = true;
            }
            else{
                dp[j] = false;
            }
        }
    }

    return dp[b.size()];

}

int main(){
    string str1 = "AB";
    string str2 = "12";
    string tar = "A21B";

    if (isCross(str1, str2, tar)) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

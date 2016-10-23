#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/* �ݹ鳬ʱ
int minDistance(string word1, string word2) {
    int n1, n2;
    n1 = word1.size();
    n2 = word2.size();

    if (n1 == 0 || n2 == 0) return abs(n1-n2);

    int step = 0;

    if (word1[0] == word2[0]){
        step = minDistance(word1.substr(1), word2.substr(1));
    }
    else{
        step = min( (minDistance(word1.substr(1), word2.substr(1)) + 1),
                    (minDistance(word1, word2.substr(1)) + 1) );
    }

    return step;
}
*/

int minDistance(string word1, string word2) {
    const int n1 = word1.size();
    const int n2 = word2.size();


    if (n1 == 0 || n2 == 0) return abs(n1-n2);

    int **dp = new int*[n1+1];

    for (int k = 0; k <= n1; k++){
        dp[k] = new int[n2+1];
    }

    int i, j;
    for (i = 0; i <= n1; i++){
        dp[i][0] = i;
    }
    for (j = 0; j <= n2; j++){
        dp[0][j] = j;
    }

    for (i = 1; i <= n1; i++){
        for (j = 1; j <= n2; j++){
            if (word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min( min(dp[i-1][j-1], dp[i][j-1]),dp[i-1][j]) + 1;
            }
        }
    }

    return dp[n1][n2];
}

int main(){
    string s1 = "abc";
    string s2 = "abdce";

    cout << minDistance(s1, s2) << endl;



    return 0;
}

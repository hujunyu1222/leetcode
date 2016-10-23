#include <iostream>
#include <vector>
using namespace std;



int uniquePaths(int m, int n) {
    int dp[m][n];
    int i = 0, j = 0;

    dp[0][0] = 1;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            if (i - 1 >=0 && j - 1 >=0){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            else if (i - 1 >= 0){
                dp[i][j] = dp[i-1][j];
            }
            else if (j - 1 >=0){
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}

int main(){
    int a[2][3] = {{1,2,3},{4,5,6}};
    int i,j;

    for (i=0; i<2; i++)
        for (j = 0; j < 3; j++)
            cout << a[i][j] << endl;

    cout << "dynamic:" << endl;
    cout << uniquePaths(3, 2);


    return 0;
}

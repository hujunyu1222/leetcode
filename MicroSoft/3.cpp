#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

char maze[1000][1000];
int dp[1000][1000][2];

void PrintMaze(int N, int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int N, M;
    int i, j;
    cin >> N >> M;

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            cin >> maze[i][j];
        }
    }

    if (maze[0][0] == 'b'){
        dp[0][0][0] = 1;
        dp[0][0][1] = 2;
    }
    else{
        dp[0][0][0] = 0;
        dp[0][0][1] = 1;
    }
    if (maze[0][1] == 'b'){
        dp[0][0][1] = 0;
    }

    for (i = 1; i < N; i++){
        dp[i][0][0] = 10001;
        if (maze[i][0] == 'b'){

            dp[i][0][1] = dp[i-1][0][1] + 1;
        }
        else{
            dp[i][0][1] = dp[i-1][0][1];
        }
    }

    for (j = 1; j < M; j++){
        dp[0][j][1] = 10001;
        if (maze[0][j] == 'b'){
            dp[0][j][0] = dp[0][j-1][0] + 1;
        }
        else{
            dp[0][j][0] = dp[0][j-1][0];
        }
    }


    for (i = 1; i < N; i++){
        for (j = 1; j < M; j++){
            if (i + 1 != N && maze[i+1][j-1] != 'b'){
               dp[i][j][0] = min(dp[i][j-1][0], dp[i][j-1][1] + 1);
            }
            else{
              dp[i][j][0] = min(dp[i][j-1][0], dp[i][j-1][1]);
            }

            if (j + 1 != M && maze[i-1][j+1] != 'b')
            {
                dp[i][j][1] = min(dp[i-1][j][0] + 1, dp[i-1][j][1]);
            }
            else{
               dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][1]);
            }

            if (maze[i][j] == 'b'){
                dp[i][j][0]++;
                dp[i][j][1]++;
            }
        }
    }
    //PrintMaze(N, M);
    int res = min(dp[N-1][M-1][0],dp[N-1][M-1][1]);
    cout << res;

    return 0;

}

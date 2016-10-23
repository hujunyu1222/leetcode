#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mp[100][100];
int value[100][100];

int getS(int x1, int y1, int x2, int y2){
    if ((x1 == x2) && (y1 == y2)){
        return mp[x1][y1];
    }

    //if (x2 == 1 || y2 == 1) return value[x2][y2] - value[x1][y1] + mp[x1][y1];


    return value[x2][y2] - value[x2][y1-1] - value[x1-1][y2] + value[x1-1][y1-1];

}

int getMin(int row[], int col[], int n, int m){
    vector<int> tmp(16,0);
    int i, j, k;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){

        }
    }


}

int solve(){
    int n, m;
    cin >> n >> m;
    int manSum = -1;

    int i, j;

    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            cin >> mp[i][j];
        }
    }

    for (j = 1; j <= m; j++){
        value[1][j] = mp[1][j] + value[1][j-1];
    }
    for (i = 1; i <= n; i++){
        value[i][1] = mp[i][1] + value[i-1][1];
    }

    for (i = 2; i <= n; i++){
        for (j = 2; j <= m; j++){
            value[i][j] = mp[i][j] + value[i-1][j] + value[i][j-1] - value[i-1][j-1];
        }
    }

    int row[4];
    int col[4];

    row[4] = n;
    col[4] = m;


    for (row[0] = 1; row[0] <= n - 3; row[0]++){
        for (row[1] = 2; row[1] <= n - 2; row[1]++){
            for (row[2] = 3; row[2] <= n-1; row[2]++){
                for (col[0] = 1; col[0] <= n - 2; col[0]++){
                    for (col[1] = 2; col[1] <= n - 1; col[1]++){
                        for (col[2] = 3; col[2] <= n; col[2]++){
                            maxSum = max(maxSum, getMin(row, col, n, m);
                        }
                    }
                }
            }
        }
    }




}

int main(){

    return 0;
}

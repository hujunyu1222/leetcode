#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int H, W, D;


int main(){

    freopen("3.txt","r", stdin);

    cin >> H >> W >> D;
    vector<vector<int> > m(H, vector<int>(W,0));
    vector<vector<int> > B(D,vector<int>(D,0));

    vector<vector<int> > line(D*D, vector<int>(D*D, 0));
    vector<int> y(D*D , 0);


    int i, j, k;
    for (i = 0; i < H; i++){
        for (j = 0; j < W; j++){
            cin >> m[i][j];
        }
    }

    int cnt = 0;

    for (i = 0; i < D; i++){
        for (j = 0; j < D; j++){
            cin >> B[i][j];
            y[cnt++] = B[i][j];
        }
    }

    for (int row = 0; row < H - D + 1; row++){
        for (int col = 0; col < W - D + 1; col++){

            for (i = 0; i < D; i++){
                for (j = 0; j < D; j++){
                    line[row*D+col][i*D+j] = m[i+row][j+col];
                }
            }
        }
    }

    for (auto x : line){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }








    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
int space[101][101][101];
int vis[101][101][101];

void PrintSpace(){
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            for (int k = 0; k < 101; k++){
                printf("%d ", space[i][j][k]);
            }
        }
    }
}

bool near(int x, int y, int z, int flag){
    if (space[x-1][y][z] != flag &&
        space[x][y-1][z] != flag &&
        space[x][y][z-1] != flag &&
        space[x+1][y][z] != flag &&
        space[x][y+1][z] != flag &&
        space[x][y][z+1] != flag
         ){
            return false;
    }
    else{
        return true;
    }

}

int main(){
    memset(space, -1, sizeof(int) * 101*101*101 );
    int N, M;

    cin >> N;
    int i, j, k;
    for ()
    //PrintSpace();
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

/*
state transition:
    0:  die  -> die
    1:  live -> live
    2:  live -> die
    3:  die  -> live
*/


void gameOfLife(vector<vector<int>>& board) {
    vector<pair<int, int> > direct{{-1,-1}, {-1,0}, {-1,1}, {0,-1},
                                    {0,1}, {1,-1}, {1,0}, {1,1}};

    int m = board.size();
    if (m == 0) return;

    int n = board[0].size();

    int i, j;
    int cnt = 0;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            cnt = 0;
            for (auto tmp : direct){
                int x = i + tmp.first;
                int y = j + tmp.second;

                if (x >= 0 && x < m && y >= 0 && y < n
                    && (board[x][y] == 1 || board[x][y] == 2)){
                        cnt++;
                }
            }

            if (board[i][j] == 1 && (cnt > 3 || cnt < 2)){
                board[i][j] = 2;
            }
            else if (board[i][j] == 0 && cnt == 3){
                board[i][j] = 3;
            }
        }
    }

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            board[i][j] = board[i][j] % 2;
        }
    }


}

int main(){
    vector<vector<int> > m;
    gameOfLife(m);

    return 0;


}

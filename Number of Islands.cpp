#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numIslands(vector<vector<char>>& grid) {
    queue<pair<int, int> > q;

    vector<pair<int, int> > direct{{-1,0}, {1,0}, {0,-1}, {0,1}};
    int i, j;
    int cnt = 0;

    int m = grid.size();
    if (m == 0) return 0;

    int n = grid[0].size();

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            if (grid[i][j] == '1'){
                cnt++;
                grid[i][j] = '0';

                q.push(make_pair(i,j));

                while(!q.empty()){
                    pair<int, int> tmp = q.front();
                    q.pop();
                    for (auto d : direct){
                        int x = tmp.first + d.first;
                        int y = tmp.second + d.second;

                        if (x >= 0 && x < m && y >=0 && y < n && grid[x][y] == '1'){
                            q.push(make_pair(x, y));
                            grid[x][y] = '0';
                        }

                    }
                }


            }
        }
    }

    return cnt;
}

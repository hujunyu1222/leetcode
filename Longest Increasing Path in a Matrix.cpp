#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int DFS(int x, int y, vector<pair<int, int> > &ori, vector<vector<int> > &m,vector<vector<int>> &matrix){
    int i;
    int maxLen = 1;
    m[x][y] = 1;
    for (i = 0; i < ori.size(); i++){

            int xx = ori[i].first + x;
            int yy = ori[i].second + y;

            if (xx >= 0 && xx < matrix.size() && yy >= 0 && yy < matrix[0].size()
                && matrix[xx][yy] > matrix[x][y]){
                if (m[xx][yy] != 0){
                    m[x][y] = max(m[x][y], m[xx][yy] + 1 );
                }
                else{
                    m[x][y] = max(m[x][y], DFS(xx, yy, ori, m, matrix) + 1);
                }
            }

    }
    maxLen = max(m[x][y], maxLen);

    return maxLen;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
   int m, n;
   m = matrix.size();

   if (m == 0) return 0;

   n = matrix[0].size();

   //ori : orientation: up, left ,right, down
   vector<pair<int, int> > ori{{-1,0},{0,-1},{0,1},{1,0}};
   vector<vector<int> > lenMap(m, vector<int>(n, 0));

   int maxLen = -1;

   for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            maxLen = max(maxLen, DFS(i, j, ori, lenMap, matrix));
        }
   }

   return maxLen;

}

int main(){
    vector<vector<int> > matrix{{3,4,5},{3,2,6},{2,2,1}};
    cout << longestIncreasingPath(matrix) << endl;
    return 0;
}

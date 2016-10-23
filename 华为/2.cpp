#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int vis[2000][2000] = {0};

bool canArr(vector<vector<char> > &mp, int x, int y, pair<int, int> &des){
    if (x == des.first && y == des.second){
        return true;
    }

    int m, n;
    m = mp.size();
    n = mp[0].size();

    vector<pair<int, int> > ori{{-1,0},{1,0},{0,-1},{0,1}};

    for (int i = 0; i < 4; i++){
        int xx = x + ori[i].first;
        int yy = y + ori[i].second;

        if (xx >= 0 && xx < m && yy >=0 && yy < n && !vis[xx][yy] && mp[xx][yy] != '#'){
            vis[xx][yy] = 1;
            if (canArr(mp, xx, yy, des)){
                return true;
            }
            vis[xx][yy] = 0;
        }
    }

    return false;

}

int main(){
    int M, N;
    //freopen("2.txt","r",stdin);

    cin >> M >> N;

    int startX, startY;
    pair<int, int> des;

    vector<vector<char> > mp(M, vector<char>(N,'-'));

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cin >> mp[i][j];
            if (mp[i][j] == 'B'){
                startX = i;
                startY = j;
            }
            else if (mp[i][j] == 'H'){
                des.first = i;
                des.second = j;
            }
        }
    }

    if (canArr(mp, startX, startY, des)){
        cout << "Y" << endl;
    }
    else{
        cout << "N" << endl;
    }


    return 0;
}

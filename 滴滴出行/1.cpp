#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mx = 1e3 + 7;

bool vis[mx][mx] = {false};
int maxP = -1;

int N, M, P;

vector<pair<int, int> > path;

bool DFS(vector<vector<int> > &m, int x, int y, int p, vector<pair<int,int> > &res){
    if (x == 0 && y == M - 1 ){
        if (p > maxP){
            maxP = p;
            path.resize(0);
            path = res;
        }
        return true;
    }
    else if (p == 0) return false;

    vector<pair<int, int> > ori{{-1,0},{1,0},{0,1},{0,-1}};
    bool flag = false;

    for (int i = 0; i < 4; i++){
        int cost = 0;
        if (i == 2 || i == 3){
            cost = 1;
        }
        else if (i == 0){
            cost = 3;
        }

        int xx = x + ori[i].first;
        int yy = y + ori[i].second;
        pair<int, int> tmp;

        if (xx >= 0 && xx < N && yy >= 0 && yy < M && !vis[xx][yy] && (p - cost >= 0) && m[xx][yy] == 1){
            tmp.first = xx;
            tmp.second = yy;
            res.push_back(tmp);

            vis[xx][yy] = true;

            if(DFS(m, xx, yy, p - cost, res)){
                flag = true;
            }

            vis[xx][yy] = false;
            res.pop_back();

        }

    }

    return flag;

}

int main(){
    freopen("1.txt","r", stdin);
    cin >> N >> M >> P;

    vector<pair<int, int> > res;
    vector<vector<int> > mp(N, vector<int>(M,0));

    res.push_back({0,0});

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> mp[i][j];
            vis[i][j] = false;
        }
    }

    if (DFS(mp,0,0,P,res)){
        for (int i = 0; i < path.size(); i++){
            cout << "[" << path[i].first << "," << path[i].second<< "]";
            if (i != path.size() - 1){
                cout << ",";
            }
        }
    }
    else{
        cout << "Can not escape!" << endl;
    }


    return 0;
}

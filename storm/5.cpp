#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int mx = 6;

int N;
int mp[mx][mx];
int ret = 0;
int vis[mx];
string S[mx];


void dfs(int n){
    int j;
    if (n == N){
        ret++;
        return;
    }

    for (j = 0; j < mx; j++){
        if (mp[n][j] && !vis[j]){
            vis[j] = 1;
            dfs(n+1);
            vis[j] = 0;
        }
    }

    return;
}

int main(){
    while (cin >> N) {
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < N; i++) {
            cin >> S[i];
            for (int j = 0; j < S[i].size(); j++)
                mp[i][S[i][j] - '0'] = 1;
        }
        ret = 0;
        memset(vis, 0, sizeof(vis));
        dfs(0);
        cout << ret << endl;
    }

    return 0;

}

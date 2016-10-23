#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mx = 1e3 + 7;

int mp[mx][mx] = {0};

int vis[mx] = {0};

int minCost = 0x7FFFFFFF;


bool isAll(int n){
    for (int i = 0; i < n; i++){
        if (vis[i] == 0) return false;
    }

    return true;

}

void DFS(int pos, int n, int res){
    if (isAll(n)){
        minCost = min(minCost, res);
        return;
    }

    vis[pos] = 1;
    for (int i = (pos+1) % n; i != pos ; i= (i + 1) % n){
        if (!vis[i]){
            vis[i] = 1;
            res += mp[pos][i];

            DFS(i, n, res);

            res -= mp[pos][i];
            vis[i] = 0;
        }
    }

    vis[pos] = 0;



}



int main(){
    freopen("3.txt", "r", stdin);

    int n;
    int tmp;
    char ch;
    string s;
    getline(cin, s);
    stringstream sN(s);

    sN >> n;



    for (int i = 0; i < n; i++){
        getline(cin, s);
        stringstream ss(s + ',');



        for (int j = 0; j < n; j++){
            ss >> tmp >> ch;
            mp[i][j] = tmp;
        }
    }
    for (int i= 0; i < 4; i++)
        DFS(i, n, 0);

    cout << minCost << endl;




    return 0;
}

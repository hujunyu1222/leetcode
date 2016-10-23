#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

int vis[26];
string name[100];
int num[100];

int numofCh(string &a){
    string res;
    int cnt = 0;
    int i;
    memset(vis, 0, sizeof(vis));

    for (i = 0 ; i < a.size(); i++){
        if (a[i] == ' ')continue;
        else if (!vis[a[i] - 'A']){
            cnt++;
            vis[a[i] - 'A'] = 1;
        }
    }
    return cnt;

}

int cmp(int idxa, int idxb){
    int i, j;
    if (num[idxa] != num[idxb]){
        return num[idxa] > num[idxb] ? idxa : idxb;
    }
    else{

        return name[idxa] < name[idxb] ? idxa : idxb;

    }

}

int main(){
    string a = "GOOGLE";
    string b = "APAC CODE JAM";

    freopen("A-large-practice.in", "r", stdin);
    freopen("2017_A_1_large.txt", "w", stdout);
    int caseNum = 1;
    int T, N;



    cin >> T;

    while(T--){
        cin >> N;
        memset(num, 0, sizeof(num));

        string s;
        int index = 0;
        getline(cin, s);
        for (int k = 0; k < N; k++){
            getline(cin, s);
            name[index] = s;
            num[index] = numofCh(s);
            index++;
        }
        int res = 0;

        for (int i = 1; i < N; i++){
            res = cmp(res, i);
        }
        printf("Case #%d: %s\n", caseNum++, name[res].c_str());
    }


    return 0;
}



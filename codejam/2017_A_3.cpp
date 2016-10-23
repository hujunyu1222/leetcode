#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

#define ll long long

//small case
ll M;
int N;
int T;

//attack power
ll attack[13][11] = {0};
//cost
ll cost[13][11] = {0};
//
int initLevel[13] = {1};
int maxLevel[13];

ll maxPower = -1;

void DFS(int cardNum, int level, ll restMoney, ll totPower){
    if (cardNum == N || restMoney == 0){
        maxPower = max(maxPower, totPower);
        return;
    }



    if (level != maxLevel[cardNum]){
        if (restMoney - cost[cardNum][level - 1] >= 0)
        DFS(cardNum, level+1, restMoney - cost[cardNum][level - 1], totPower + attack[cardNum][level] - attack[cardNum][level-1]);
    }
    //if (restMoney - cost[cardNum+1][initLevel[cardNum+1] - 1] >= 0)

    DFS(cardNum+1, initLevel[cardNum+1], restMoney, totPower + attack[cardNum+1][initLevel[cardNum+1]-1]);



    return;


}

void Print(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < maxLevel[i] - 1; j++){
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    for (int j = 0; j < N; j++){
        cout << maxLevel[j] << " ";
    }
    cout << endl;
}

int main(){


    int caseNum = 1;
    int money = 0;



    freopen("D-small-practice.in", "r", stdin);
    freopen("2017_A_3_out.txt", "w", stdout);
    cin >> T;

    while(T--){
       cin >> M >> N;
       memset(initLevel, 0, sizeof(initLevel));
       memset(maxLevel, 0, sizeof(maxLevel));
       memset(attack, 0, sizeof(attack));
       memset(cost, 0, sizeof(cost));
       maxPower = -1;
       //money = M;
       int i, j;
       for (i = 0; i < N; i++){
            cin >> maxLevel[i] >> initLevel[i];
            for (j = 0; j < maxLevel[i]; j++){
                cin >> attack[i][j];
            }
            for (j = 0; j < maxLevel[i] - 1; j++){
                cin >> cost[i][j];
            }
       }
       //Print();
       DFS(0,initLevel[0], M, attack[0][initLevel[0] - 1]);
       printf("Case #%d: %d\n", caseNum++, maxPower);

    }



    return 0;
}

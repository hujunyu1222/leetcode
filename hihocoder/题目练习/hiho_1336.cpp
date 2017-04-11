#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

//树状数组的二维拓展
const int maxN = 1005;
const ll MOD = 1e10 + 7;

ll c[maxN][maxN] = {0};
int N, M;

int lowbit(int k){
    return k & -k;
}

void add(int x, int y, ll value){
    for (int i = x; i < maxN; i += lowbit(i)){
        for (int j = y; j < maxN; j += lowbit(j)){
            c[i][j] += value;
        }
    }

}

//从(x,y)到左上角
ll getSum(int x, int y){
    ll res = 0;

    for (int i = x; i != 0; i -= lowbit(i)){
        for (int j = y; j != 0; j -= lowbit(j)){
            res += c[i][j];
        }
    }

    return res;

}


int main(){
    freopen("1336.txt","r",stdin);


    char s[10];
    int x1, y1, x2, y2;
    int v;
    ll res = 0;

    memset(c, 0, sizeof(c));

    cin >> N >> M;


    while(M--){
        cin >> s;
        if (s[0] == 'A'){
            cin >> x1 >> y1 >> v;
            add(x1+1, y1+1, v); //树状数组从(1,1)开始
        }
        else{
            cin >> x1 >> y1 >> x2 >> y2;
            //多减去的块要加回来
            res = getSum(x2+1, y2+1) - getSum(x2+1, y1) - getSum(x1, y2+1) + getSum(x1, y1);
            res %= MOD;
            if (res < 0){
                res += MOD;
            }
            cout << res << endl;
        }
    }



    return 0;
}


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

//��״����Ķ�ά��չ
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

//��(x,y)�����Ͻ�
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
            add(x1+1, y1+1, v); //��״�����(1,1)��ʼ
        }
        else{
            cin >> x1 >> y1 >> x2 >> y2;
            //���ȥ�Ŀ�Ҫ�ӻ���
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


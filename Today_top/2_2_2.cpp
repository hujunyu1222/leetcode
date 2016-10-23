#include <iostream>
#include <bits/stdc++.h>

using namespace std;


const int mx = 1e5 + 7;


long long val[32 * mx];
int num[32 * mx];
int sizeOfN;

int trie[32*mx][2];




void insert(long long a){
    int cn=0;
    int key = 0x40000000;

    while(key != 0){
        int aBit= a & key;
        if (aBit != 0) aBit = 1;

        if(!trie[cn][aBit]){
            memset(trie[sizeOfN],0, sizeof(trie[sizeOfN]));
            val[sizeOfN] = 0;
            num[sizeOfN] = 0;
            trie[cn][aBit]= sizeOfN++;
        }
        cn=trie[cn][aBit];
        num[cn]++;
        key = key >> 1;
    }

    val[cn] = a;
}

long long countN(long long a,long long m){
    int cn = 0;
    long long res = 0;
    int key = 0x40000000;

    while(key != 0){
        int aBit= a & key;
        int mBit= m & key;

        if (aBit != 0) aBit = 1;
        if (mBit != 0) mBit = 1;

        if(mBit == 0){
            if(trie[cn][aBit^1] && num[trie[cn][aBit^1]])
            {
                    res+=num[trie[cn][aBit^1]];
            }
            if(trie[cn][aBit] && num[trie[cn][aBit]]) {
                    cn = trie[cn][aBit];
            }
            else
                return res;
        }
        else{
            if(trie[cn][aBit^1]&&num[trie[cn][aBit^1]]) {
                    cn=trie[cn][aBit^1];
            }
            else
                return res;
        }

        key = key >> 1;
    }
    return res;
}


int main(){
    freopen("in2.txt","r",stdin);

    memset(trie[0],0,sizeof(trie[0]));

    sizeOfN = 1;

    int N, M;
    long long res=0;

    cin>>N>>M;

    vector<int> num(mx, 0);

    for(int i=1; i<=N; i++){
        cin >> num[i];
        insert(num[i]);
    }

    for(int i=1; i <= N; i++){
        res += countN(num[i],M);
    }

    res = res >> 1;

    cout<< res <<endl;

    return 0;
}

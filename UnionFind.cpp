#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int maxSize = 1e7 + 7;

int father[maxSize];

int find(int x){
    if (x != father[x]){
        father[x] = find(father[x]);
    }

    return father[x];
}

void init(){
    for (int i = 0; i < maxSize; ++i){
        father[i] = i;
    }

}

int main(){
    int a, b;

    while(1){
        cin >> a >> b;
        if (a == -1 && b == -1) break;

        int x = find(a);
        int y = find(b);

        if (x != y){
            father[y] = x;
        }

    }



    return 0;
}

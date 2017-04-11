#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int tree[8] = {0};
int arrSize = 8;


int lowbit(int k){
    return k&-k;
}

void add(int i, int num){
    //下标从0开始
    i = i + 1;
    while(i <= arrSize){
        tree[i-1] += num;
        i += lowbit(i);
    }

}

//计算1~n的总和
int sum(int n){
    n = n + 1;
    int sum = 0;
    while (n){
        sum += tree[n-1];
        n -= lowbit(n);
    }

    return sum;

}


int main(){
    for (int i = 0; i < arrSize; ++i){
        add(i,i+1);
        cout << tree[i] << endl;
    }

    cout << sum(7) - sum(2) << endl;



    return 0;
}

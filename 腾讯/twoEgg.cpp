#include <iostream>
#include <bits/stdc++.h>

using namespace std;


//有n层楼，扔两个鸡蛋，找到临界楼层（即改喽礽鸡蛋不会碎，再上一层则会碎）

int level;

int f(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;

    int tmp, minL;

    minL = 0x7FFFFFFF;

    for (int i = 1; i <= n; i++){
        tmp = 1 + max(i - i, f(n - i));
        if (tmp < minL){
            minL = tmp;
            level = i;
        }
    }

    return minL;

}

//数学方法
int f2(int n){
    //求根公式
    int res = ceil((-1+ceil(sqrt(1 - 4*1*(-2*n))) ) / 2);

    return res;

}

int main(){


    cout << f2(39);

    return 0;
}

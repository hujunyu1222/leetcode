#include <iostream>
#include <bits/stdc++.h>

using namespace std;


//��n��¥���������������ҵ��ٽ�¥�㣨����ඵi���������飬����һ������飩

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

//��ѧ����
int f2(int n){
    //�����ʽ
    int res = ceil((-1+ceil(sqrt(1 - 4*1*(-2*n))) ) / 2);

    return res;

}

int main(){


    cout << f2(39);

    return 0;
}

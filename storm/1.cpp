#include <iostream>
#include <algorithm>

using namespace std;

#define N 1000000

int f[N+1] = {0};

void init(){
    int a1, a2, tmp;
    a1 = a2 = 1;
    int i, j;

    for (i = 1; i <= N; i++){
        f[i] = 0x7FFFFFFF;
    }

    f[a1] = 1;
    while(a1+a2 <= N){
        tmp = a2;
        a2 = a1 + a2;
        f[a2] = 1;
        a1 = tmp;
    }




}

int main(){
    init();
    int a1, a2, tmp;
    int k;

    a1 = a2 = 1;

    while(cin >> k){
        for (int i = 1; i <= k; i++){
            for (a1 = 1, a2 = 1; i+a1+a2 <= k ; tmp = a2, a2 = a1 + a2, a1 = tmp ){
                f[i + a1 + a2] = min(f[i]+1, f[i + a1 + a2]);
            }
        }
        cout << f[k] << endl;
    }

    return 0;
}

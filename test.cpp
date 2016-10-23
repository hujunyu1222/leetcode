#include <iostream>
using namespace std;
int Max = 0;

int f(int n){
    return Max += n + (n && f(n-1));
}

int main(){
    int a;
    int n = 10;
    f(n);
    //cout << (a = 3);
    cout << Max-n+1;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int xorProduct(int a, int b){
    if (a == b) return a;

    int mid;

    int res = 0;

    mid = (a + b) / 2;
    res = xorProduct(a,mid) ^ xorProduct(mid + 1, b);

    return res;

}

long long f(long long a) {
     long long res[] = {a,1,a+1,0};
     return res[a%4];
}

long long getXor(long long a, long long b) {
     return f(b)^f(a-1);
}


int main(){
    cout << xorProduct(1,1) << endl;
    cout << getXor(5,8) << endl;


    return 0;
}

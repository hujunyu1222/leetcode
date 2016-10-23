#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string toBinary(int a){
    string c;
    const int N = 0x00000001;
    int i = 0;
    for (i = 7; i >=0 ;i--){
        c += (a & N) + '0';
        //cout <<c[i] << endl;
        a = a >> 1;
    }
    reverse(c.begin(),c.end());
    return c;
}

int main(){

    int a;
    cin >> a;
    string res = toBinary(a);
    cout << res;

    return 0;
}

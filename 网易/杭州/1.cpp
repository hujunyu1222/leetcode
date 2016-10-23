#include <iostream>
#include <bits/stdc++.h>

using namespace std;


const char& f(char a[]){

    return a[0];
}

void mySwap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

}


int main(){
    int a, b;

    a = 2;
    b = 5;

    cout << a << " " << b << endl;
    mySwap(a, b);
    cout << a << " " << b << endl;



    return 0;
}

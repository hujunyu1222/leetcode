#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main(){

    freopen("dataInput.txt", "r", stdin);

    string s;

    while(getline(cin, s)){
        stringstream ss(s + ' ');
        int v;
        ss >> v;
        cout << "father:\n" << v << endl;
        int tmp;
        cout << "child:\n";
        while(ss >> tmp){
             cout << tmp << " ";
        }
        cout << endl;
    }



    return 0;
}

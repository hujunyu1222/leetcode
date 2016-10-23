#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main(){
    unordered_multimap<int, int> mm;
    pair<int, int> tmp;
    tmp.first = 2;
    tmp.second = 3;

    mm.insert({2,3});
    mm.insert({2,5});

    for (auto x : mm){
        cout << x.first << " : "<< x.second << endl;
    }

    return 0;
}

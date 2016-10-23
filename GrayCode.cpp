#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<int> grayCode(int n) {
    vector<int> res;

    for (int i = 0; i < pow(2,n); i++){
        cout << (i ^(i >> 1));
        res.push_back(i ^(i >> 1));
    }

    return res;
}

int main(){

    return 0;
}

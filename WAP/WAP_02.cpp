#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

#define MAX_SIZE 100000
#define INT_MIN 0x8000000000000000

long long num[MAX_SIZE];
int N;

int main(){
    ifstream fin;
    int index = 0;
    fin.open("02input.txt");
    cout << "Size long long:" << sizeof(long long) << endl;

    fin >> N;

    while(fin >> num[index++]);

    int i, j;
    long long pre, suf;
    long long maxNum = INT_MIN;
    pre = suf = 0;

    cout << maxNum << endl;

    for(i = 0; i < N; i++){
        pre = pre ^ num[i];
        if (pre > maxNum){
            maxNum = pre;
        }
    }

    for (j = N - 1; j >=0; j--){
        suf = suf ^ num[j];
        if (suf > maxNum){
            maxNum = suf;
        }
    }

    cout << maxNum << endl;


    return 0;
}

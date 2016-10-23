#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

#define MAX_SIZE 100000

int num[MAX_SIZE];
int N;

int main(){
    ifstream fin;
    int index = 0;
    fin.open("02input.txt");
    fin >> N;

    while(fin >> num[index++]);

    for(int i = 0; i < N; i++){
        cout << num[i] << endl;
    }


    return 0;
}

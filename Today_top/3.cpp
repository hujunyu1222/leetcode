#include <iostream>
#include <string>
#include <cmath>

using namespace std;


const int P = 283;

unsigned long long seed[20];

void initSeed(){
    int i;
    seed[0] = 1;
    for (i = 1; i < 20; i++){
        seed[i] = (seed[i - 1] * P) ;
    }
}

void PrintSeed(){
    for (int i = 0; i < 20; i++){
        cout << seed[i] << " ";
    }
    cout << '\n';
}

unsigned long long strHash(string s){
    unsigned long long res = 0;
    int i = 0;
    int n = s.size();
    for (i = n - 1; i >=0; i--){
        res = res * P + (s[i]+1 - 'A');
    }

    return res;
    //return (res & 0x7FFFFFFF);

}

int calWeight(string s){
    int weight = 0;
    int i;
    int length = s.size();

    unsigned long long oriNum = strHash(s);
    cout << "ori:" << oriNum  << endl;
    unsigned long long tmp = oriNum;
    cout << "tmp:" << oriNum  << endl;

    for (i = 0; i < length; i++){
        tmp = (tmp - (s[i]+1 - 'A')) / P  + (s[i]+1 - 'A') * seed[length - 1];

        //tmp = (tmp & 0x7FFFFFFF);
        cout << tmp << endl;

        if (tmp == oriNum){
            weight++;
        }
    }

    return weight;
}



int main(){
    string s = "ABRAABRA";
    initSeed();
    PrintSeed();
    vector<int> index;
    int cnt = 0;


    next_permutation(index.begin(),index.end() - 1);
    //cout << strHash(s);
    cout << calWeight(s);

    return 0;
}

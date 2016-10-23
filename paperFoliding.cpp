#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//从下往上依次折纸N次，
//从上往下依次打印折痕

//true表示下，false表示上
void printFolds(int i, int N, bool down){
    if (i > N){
        return;
    }

    printFolds(i + 1, N, true);

    if (down){
        cout << "down" << endl;
    }
    else{
        cout << "up" << endl;
    }

    printFolds(i + 1, N, false);


}

void printAllFolds(int N){
    printFolds(1, N, true);

}

int main(){
    int N;
    cin >> N;

    printAllFolds(N);

    return 0;
}


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//��������������ֽN�Σ�
//�����������δ�ӡ�ۺ�

//true��ʾ�£�false��ʾ��
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


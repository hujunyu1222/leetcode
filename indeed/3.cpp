#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

vector<vector<char> > mp(6,vector<char>(6,'.'));

int col[6] = {0};
int row[6] = {0};
int cnt = 0;

bool isCorr(){
    for (int i = 0; i < 6; i++){
        if (col[i] != 3 || row[i] != 3) return false;
    }
    return true;
}

void backtracking(int posi, int posj){
    if (posi >=6 || posj >= 6) {
            if (isCorr())
            cnt ++;
            return;
    }
    if (posj == 5){
        if (mp[posi][posj] == 'o' && col[posi] < 3)
            return;
        else if (mp[posi][posj] == '.' && col[posi]+1 < 3)
            return;
    }
    if (posi == 5){
        if (mp[posi][posj] == 'o' && row[posj] < 3)
            return;
        else if (mp[posi][posj] == '.' && row[posj]+1 < 3)
            return;
    }

    if (mp[posi][posj] == 'o'){
       backtracking(posi+(posj+1)/6, (posj+1) % 6);
    }
    else{
        mp[posi][posj] = 'o';
        col[posi]++;
        row[posj]++;
        if (col[posi] > 3 || row[posj] > 3){
           col[posi]--;
           row[posj]--;
        }
        else{
           backtracking(posi+(posj+1)/6, (posj+1) % 6);
           col[posi]--;
           row[posj]--;
        }
        mp[posi][posj] = '.';

        backtracking(posi+(posj+1)/6, (posj+1) % 6);
    }
}

/*
void Print(){
    for (auto x:mp){
        for (auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }
}
*/

int main(){
    int i, j;
    //freopen("3.txt","r",stdin);
    for (i = 0; i < 6; i++){
        for (j = 0; j < 6; j++){
            cin >> mp[i][j];
            if (mp[i][j] == 'o'){
                col[i]++;
                row[j]++;
                if (col[i] > 3 || row[j] > 3){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }



    if (isCorr())
    {

        cout << 0 <<endl;
        return 0;
    }

    backtracking(0,0);
    cout << cnt << endl;






    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
//row 标记行，b是下标，表示该行中是否已出现b这个数字。
//colum，block同理
bool isValidSudoku(vector<vector<char> >& board){
    int b, row[9][9] = {}, column[9][9] = {}, block[9][9] = {};
    for (int i=0; i<9; i++){

        for (int j=0; j<9; j++){

            if ((b = board[i][j] - '1') >= 0 &&
                (row[i][b]++ | column[j][b]++ | block[i/3*3+j/3][b]++))
                {
                    return false;
                }
        }
    }

    return true;
}


int main(){

    return 0;
}

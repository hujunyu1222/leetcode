#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <unordered_map>
#include <sstream>

using namespace std;

char alp[9] = {'1','2','3','4','5','6','7','8','9'};

unordered_map<char, bool> row[9];
unordered_map<char, bool> col[9];
unordered_map<char, bool> block[3][3];

void init(vector<vector<char>>& board){
    int i, j;
    char c;
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            if (board[i][j] !='.'){
                c = board[i][j];
                row[i][c] = true;
                col[j][c] = true;
                block[i/3][j/3][c] = true;
            }
        }
    }
}


//一定记得状态复原
bool solveBacktracking(vector<vector<char>>& board, int x, int y){
    int i, j;
    int index;
    int nextX, nextY;
    bool flag = true;

    if (x >= 9){
        return true;
    }
    i = x; j = y;

    if (board[i][j] == '.'){
            //cout << "in" << i << " " << j << endl;
        for (index = 0; index < 9; index ++){
            if (row[i].find(alp[index]) == row[i].end() &&
                col[j].find(alp[index]) == col[j].end() &&
                block[i/3][j/3].find(alp[index]) == block[i/3][j/3].end() )
            {
                    board[i][j] = alp[index];
                    row[i][alp[index]] = true;
                    col[j][alp[index]] = true;
                    block[i/3][j/3][alp[index]] = true;
                    nextY = (j + 1) % 9;
                    nextX = i + ( (j+1) /9);
                    flag = false;
                    if(solveBacktracking(board, nextX, nextY)){
                        return true;
                    }
                    else{
                       //backtracking
                        board[i][j] = '.';
                        row[i].erase(alp[index]);
                        col[j].erase(alp[index]);
                        block[i/3][j/3].erase(alp[index]);
                        flag = true;
                    }

            }
        }
        if (flag){
            return false;
        }
    }
    else{
        nextY = (j + 1) % 9;
        nextX = i + ( (j+1) /9);
        return solveBacktracking(board, nextX, nextY);
    }

}

void solveSudoku(vector<vector<char>>& board) {
    init(board);
    solveBacktracking(board, 0, 0);


}
//= {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."}
void PrintBoard(vector<vector<char>>& board){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}


int main(int argc, char *argv[]){
    vector<vector<char>> board(9);
    string inputS = "..9748...7.........2.1.9.....7...24..64.1.59..98...3.....8.3.2.........6...2759..";
    stringstream ss(inputS);
    char matrix[9][9];
    char c;
    for (int i = 0;i < 9; i++){
        for (int j = 0; j < 9; j++){
           ss >> c;
           board[i].push_back(c);
        }
    }

    PrintBoard(board);
    solveSudoku(board);
    PrintBoard(board);


    return 0;
}

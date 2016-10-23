#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int N;

vector<int> x;

vector<vector<int>> m(N, vector<int>(N,0));

vector<vector<string>> res;

vector<string> eachRes;

void init(){
    //m = vector<vector<int>>(N, vector<int>(N,0));
    string s = "";
    for (int i = 0; i < N; i++){
        s +=".";
    }
    eachRes = vector<string> (N,s);

}

void Print(){

    for (auto x:res){
        for (auto y:x){
            cout << y << endl;
        }
        cout << "----------------" << endl;
    }




}

bool isSafe(int k){
    int i;
    for (i = 1; i < k; i++){
        //同一列以及斜率为1和-1的直线上不能有皇后
        if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k])){
            return false;
        }
    }
    return true;
}

void queen(int n){
    x = vector<int>(N+1, 0);
    int k = 1;
    int i;
    while(k >= 1){
        //cout << k << endl;
        x[k] = x[k] + 1;

        while(x[k] <= n && !isSafe(k)){
            x[k] = x[k] + 1;
        }

        if (x[k] <= n && k == n){

            for (i = 0; i < n; i++){
                eachRes[i][x[i+1]-1] = 'Q';
            }
            res.push_back(eachRes);

            init();
        }
        else if(x[k]<= n && k < n)
            k = k + 1;//放置下一个皇后
        else
        {
            x[k] = 0; //重置x[k],回溯
            k = k - 1;
        }
    }
}


//利用位图的方法！！
public class Solution {

    int board = 0;    // All available columns to place queens
    int cnt = 0;

    // row: row constraint
    // ld: left diagonal constraint
    // rd: right diagonal constraint
    void DFS(int row, int ld, int rd) {
        if(row == board) {
            ++cnt;
            return;
        }
        int avail = board & (~(row | ld | rd));   // Available positions
        while(avail != 0) {   // Separately try every available positions
            int pos = avail & (-avail);  // Extract every possible position
            avail -= pos;
            DFS(row | pos, (ld | pos) << 1, (rd | pos) >>> 1);    // Add constraint for row, ld, rd
        }
    }

    public int totalNQueens(int n) {
        board = (1 << n) - 1;
        DFS(0, 0, 0);
        return cnt;
    }
}


int main(){
    cin >> N;

    init();

    queen(N);
    Print();
    return 0;
}




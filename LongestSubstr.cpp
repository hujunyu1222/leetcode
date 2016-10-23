#include <iostream>
#include <string>


using namespace std;

string longestSubstr(string &a, string &b){
    int **dp = new int*[a.size()];
    int i, j;
    for (i = 0; i < b.size(); i++){
        dp[i] = new int[b.size()];
    }

    int tail;

    string res = "";

    int maxLen = -1;
    cout << "1" << endl;
    //第一列
    for (i = 0; i < b.size(); i++){
        if (a[0] == b[i]){
            dp[i][0] = 1;
        }

    }

    cout << "2" << endl;

    //第一行
    for (j = 0; j < a.size(); j++){
        if (a[j] == b[0]){
            dp[0][j] = 1;
        }
    }

    cout << "3" << endl;

    for(i = 1; i < b.size(); i++){
        for (j = 1; j < a.size(); j++){
            if (a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > maxLen){
                    maxLen = dp[i][j];
                    tail = i;
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    cout << maxLen << endl;
    res = a.substr(tail - maxLen + 1, maxLen);

    cout << "5" << endl;

    return res;
}

string longestSubstr2(string &a, string &b){
    int len = 0;
    int row, col;

    row = 0;
    col = a.size() - 1;

    int i, j;
    int maxNum = -1;
    int tail;


    while(row < b.size()){
        i = row;
        j = col;
        len = 0;

        while(i < b.size() && j < a.size()){
            if (a[j] != b[i]){
                len = 0;
            }
            else{
                len++;
            }

            if (len > maxNum){
                maxNum = len;
                tail = j;
            }
            i++;
            j++;

        }

        if (col > 0){
            col--;
        }
        else{
            row++;
        }
    }

    return a.substr(tail - maxNum + 1, maxNum);
}

int main(){
    string str1 = "1AB2345CD";
    string str2 = "12345EF";

    cout << longestSubstr2(str1, str2) << endl;

    return 0;
}


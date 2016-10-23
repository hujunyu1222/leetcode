#include <iostream>
#include <vector>
#include <string>

using namespace std;

string phone[8] = {"abc", "def", "ghi", "jkl", "mno","pqrs", "tuv", "wxyz"};

int N;

void backtracking(string &digit, int pos, string s, vector<string> &res){
    if (pos == N){
        res.push_back(s);
        return;
    }
    int i, j;
    string tmp = phone[digit[pos] - '0' - 2];
    //cout << tmp << endl;

        for (j = 0; j < tmp.size(); j++){
            backtracking(digit, pos+1, s + tmp[j], res);
        }

}

int main(){
    string digit = "234";
    vector<string> res;
    string s = "";
    N = digit.size();

    if (N == 0){
        cout << "NULL" << endl;
    }

    backtracking(digit, 0, s, res);

    for (vector<string> :: iterator iter = res.begin(); iter!= res.end(); iter++){
        cout << *iter << endl;
    }

    return 0;
}

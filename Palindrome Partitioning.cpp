#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isPal(string s){
    string tmp = s;
    reverse(s.begin(), s.end());
    return s == tmp;
}

void dp(vector<vector<int>> &mp, string &s){
    int i, j;
    for(i = s.size() - 1; i >= 0; i--){
        for (j = i; j < s.size(); j++){
            if (i == j){
                mp[i][j] = 1;
            }
            else if (s[i] == s[j]){
                if (j == i+1 || mp[i+1][j-1] == 1){
                    mp[i][j] = 1;
                }
            }
        }
    }


}

void backtracking(int pos, string &s, vector<string> &sig, vector<vector<int>> &mp, vector<vector<string>> &res){
    int i;
    if (pos == s.size()){
        res.push_back(sig);
        return;
    }
    for (i = pos; i < s.size(); i++){
        if (mp[pos][i] == 1){
            sig.push_back(s.substr(pos, i-pos+1 ));
            backtracking(i+1, s, sig, mp, res);
            sig.pop_back();
        }


    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> sig;

    if (s.size() == 0) return res;

    vector<vector<int>> mp(s.size(), vector<int>(s.size(),0));
    dp(mp,s);

    for (auto x:mp){
        for (auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }

    backtracking(0, s, sig, mp, res);

    return res;
}

int main(){
    string s = "aabbaa";
    vector<vector<string>> res;
    res = partition(s);

    for (auto x:res){
        for (auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}



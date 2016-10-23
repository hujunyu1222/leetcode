#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool backtracking(string s, string res, unordered_set<string>& wordDict,unordered_set<string>& vis){
        if (s == res){
            return true;
        }

        string tmp = res;

        for(auto x:wordDict){
            //cout << res << ":" <<x << endl;
            if (vis.count(x) <= 0){
                vis.insert(x);
                int totSize = tmp.size() + x.size();
                if (totSize <= s.size() && (backtracking(s, tmp + x, wordDict, vis) || backtracking(s, x + tmp, wordDict, vis))){
                    return true;
                }
                vis.erase(x);
            }
        }

        return false;
}

int main(){
    unordered_set<string> wordDict;
    unordered_set<string> vis;
    wordDict.insert("leet");
    wordDict.insert("code");

    string s = "leetcode";
    string res = "";




    if (backtracking(s, res, wordDict, vis)){
        cout << "True\n";
    }
    else{
        cout << "False\n";
    }


    return 0;

}

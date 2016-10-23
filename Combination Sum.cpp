#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<vector<int>> res;

void backtracking(vector<int>& candidates, vector<int>& seq, int pos, int target){
    int n = candidates.size();
    int i;
    for (i = pos; i < n; i++){
        if (target == 0){
            res.push_back(seq);
            return;
        }
        else if (target < 0){
            return;
        }
        else{
            seq.push_back(candidates[i]);
            target -= candidates[i];
            backtracking(candidates, seq, i,target);

            seq.pop_back();
            target += candidates[i];
        }
    }

    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> seq;
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, seq, 0, target);

    return res;
}

void PrintBoard(vector<vector<int>>& res){
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    vector<int> candidates;
    string inputS = "2 3 6 7";
    stringstream ss(inputS);
    int tmp;
    while(ss >> tmp){
        candidates.push_back(tmp);
    }
    int target = 7;
    combinationSum(candidates, target);
    PrintBoard(res);

    return 0;

}

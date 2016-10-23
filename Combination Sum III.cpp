#include <iostream>
#include <vector>

using namespace std;

void backtracking(int pos, int cnt, int k, int sum, int n,
                  vector<int> &item, vector<vector<int> > &res){
    if (cnt == k && sum == n){
        res.push_back(item);
        return;
    }

    int i;

    for (i = pos; i <= 9; i++){
        if(sum + i <= n && cnt < k){
            item.push_back(i);
            backtracking(i+1, cnt+1, k, sum+i, n, item, res);
            item.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int> > res;
    if (n <= 0 || n > 45){
        return res;
    }

    vector<int> item;

    backtracking(1, 0, k, 0, n, item, res);


    return res;



}

int main(){
    vector<vector<int> > res;

    res = combinationSum3(3, 9);


    for (auto x : res){
        for (auto y : x){
            cout << y << " ";
        }
        cout << '\n';
    }

    return 0;
}

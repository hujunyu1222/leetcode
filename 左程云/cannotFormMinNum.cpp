#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void process(vector<int> &arr, int pos, int sum, unordered_set<int> &res){
    if (pos == arr.size()){
        res.insert(sum);
        return;
    }

    process(arr, pos + 1, sum, res);
    process(arr, pos + 1, sum + arr[pos], res);

}

int main(){
    vector<int> nums{3,2,5};
    unordered_set<int> res;

    process(nums, 0, 0, res);

    for (auto x : res){
        cout << x << endl;
    }

    return 0;
}

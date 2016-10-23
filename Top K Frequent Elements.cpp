#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> mp;
    vector<int> res;

    int i, j;
    for (auto x:nums){
        freq[x]++;
    }

    for (auto y:freq){
        mp[y->second].push_back(y->first);
    }

    for (i = nums.size(); i >= 1 ; i--){
        if (mp.find(i) != mp.end()){
            for (j = 0; j < mp[i].size(); j++){
                res.push_back(mp[i][j]);
            }
        }
    }

    return res;

}

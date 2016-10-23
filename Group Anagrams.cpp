#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int alp[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
                53,59,61,67,71,73,79,83,89,97,101};

long long changeToInt(string &s){
    long long sum = 1;
    for(int i = 0; i < s.size(); i++){
        sum  *= alp[s[i] - 'a'];
    }

    return sum;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<long long, int> m;
    vector<string> s;
    int i;
    int cnt = 0;
    long long tmp = 0;

    for (i = 0; i < strs.size(); i++){
        tmp = changeToInt(strs[i]);
        if (m.find(tmp) != m.end()){
            res[m[tmp]].push_back(strs[i]);
        }
        else{
            m[tmp] = cnt;
            s.push_back();
            res.push_back(s);
            s.pop_back();
            cnt++;
        }
    }

    return res;

}


int main(){

    return 0;
}

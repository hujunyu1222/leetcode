#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int longestSubstring(string s, int k) {
    unordered_map<char, int> chMap;
    unordered_set<char> chSet;
    int cnt[26] = {0};

    int start, end;
    int maxLen = 0;
    int i, j;

    for (i = 0; i < s.size(); i++){
        cnt[s[i] - 'a']++;
    }

    start = end = 0;
    while(end < s.size()){
        int num = cnt[s[end] - 'a'];
        if (num < k){
            while(!chSet.empty() && start < end){
                if(chSet.count(s[start]) > 0){
                   chMap[s[start]]--;
                   cnt[s[start] - 'a']--;
                }

                if (chMap[s[start]] == 0){
                    chSet.erase(s[start]);
                }
                start++;
            }
            if (chSet.empty()){
               maxLen = max(maxLen, end - start);
            }

            start = end + 1;
            end = start;
            for (auto x:chMap){
                cnt[x.first - 'a'] -= x.second;
            }
            chMap.clear();
            chSet.clear();
        }
        else{

            if (chMap.find(s[end]) == chMap.end()){
                chMap[s[end]] = 1;
                chSet.insert(s[end]);
            }
            else{
                chMap[s[end]]++;
            }
            if (chMap[s[end]] == k){
                    chSet.erase(s[end]);
            }
            end++;
        }

        if (chSet.empty()){
            maxLen = max(maxLen, end - start);
        }
    }



    return maxLen;


}

int main(){
    string s = "ababcdcc";
    int k = 3;

    cout << longestSubstring(s, k) << endl;

    return 0;
}

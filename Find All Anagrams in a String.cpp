#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

int vis[26] = {0};

//滑动窗口
vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int l, r;
        int match = p.size();

        for (int i = 0; i < p.size(); ++i){
            int index = p[i] - 'a';
            ++vis[index];
        }

        l = r = 0;

        while(r < s.size()){
            int tmpR = s[r] - 'a';
            --vis[tmpR];
            if (vis[tmpR] >= 0){
                match--;
            }

            if (match == 0){
                int tmpL = s[l] - 'a';
                while(vis[tmpL] < 0){
                    vis[tmpL]++;
                    tmpL = s[++l] - 'a';
                }
                if(r - l + 1 == p.size())
                {
                    res.push_back(l);
                }
                match++;
                vis[tmpL]++;
                l++;
            }

            r++;
            
        }

        return res;
}


int main(){
    string s, p;
    s = "cbaebabacd";
    p = "abc";

    vector<int> res;

    res = findAnagrams(s, p);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }

    system("pause");


    return 0;
}
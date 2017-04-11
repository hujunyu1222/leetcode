#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string minWindow(string s, string t) {
    string res = "";
    unordered_map<char, int> m;
    int cnt = t.size();
    int l, r;
    int minSize = 0x7FFFFFFF;

    for (int i = 0; i < t.size(); ++i){
        if (m.find(t[i]) == m.end()){
            m[t[i]] = 1;
        }
        else{
            ++m[t[i]];
        }
    }

    l = r = 0;

    while(r != s.size()){
        char rch = s[r];
        if (m.find(rch) == m.end()){
            r++;
            continue;
        }
        else{
            m[rch]--;
            if (m[rch] >= 0){
                cnt--;
            }
            if (cnt == 0){
                while(l <= r){
                    char lch = s[l];
                    if (m.find(lch) != m.end()){
                        m[lch]++;
                        if (m[lch] > 0){
                            res = r - l + 1 < minSize ? s.substr(l, r - l + 1) : res;
                            minSize = min(minSize, r - l + 1);
                            cnt++;
                            l++;
                            break;
                        }
                    }

                    l++;

                }


            }

        }
        r++;

    }



    return res;


}


int main(){
    string s, t;
    s = "AB";
    t = "B";

    cout << minWindow(s, t) << endl;


    return 0;
}

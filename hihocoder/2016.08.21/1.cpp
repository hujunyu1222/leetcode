#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void change(string &s, vector<string> &res){
    bool vis[26] = {false};
    vis['J' - 'A'] = true;

    int i, j;
    int cnt = 0;

    j = 0;
    string tmp = "";
    for (i = 0; i < s.size(); i++){
        if (s[i] == 'J' && vis['I' - 'A'] == false){
            vis['I' - 'A'] = true;
            res[j] += 'I';
            cnt++;
            if (cnt > 0 && cnt % 5 == 0){
                j++;
            }
        }
        else if (vis[s[i] - 'A'] == false){
            vis[s[i] - 'A'] = true;
            res[j] += s[i];
            cnt++;
            if (cnt > 0 && cnt % 5 == 0){
                j++;
            }
        }



    }




    for (i = 0; i < 26; i++){
        char tmp = 'A';
        if (vis[i] == false){

            res[j] += char('A' + i);

            cnt++;
            if (cnt > 0 && cnt % 5 == 0){
                j++;
            }
        }

    }




}

int main(){
    vector<string> res(5, "");

    string s = "";

    while(cin >> s){
       change(s, res);

        for (auto x : res){
            cout << x << endl;
        }

        for (int i = 0; i < 5; i++){
            res[i] = "";
        }

    }




    return 0;
}

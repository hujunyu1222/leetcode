#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool compare(const string &s1, const string &s2){
    return s1.size() > s2.size();
}


string longestStr(vector<string> &str){

    sort(str.begin(), str.end(), compare);
    string res;

    /*
    for (auto x : str){
        cout << x << endl;
    }
    */


    int l, r;

    for (int i = 0; i < str.size() - 2; i++){
        l = i + 1;
        r = str.size() - 1;
        while (l < r){
            if (str[l].size() + str[r].size() > str[i].size()){
                l++;
            }
            else if (str[l].size() + str[r].size() < str[i].size()){
                r--;
            }
            else{
                break;
            }
        }

        for (int j = l; j < r; j++){
                for (int k = j + 1; k <= r; k++){
                    if (str[i] == str[j] + str[k] || str[i] == str[k] + str[j]){
                            return str[i];
                    }
                }
        }
    }

    return res;



}

int main(){
    vector<string> str;

    freopen("1.txt", "r", stdin);

    string s;

    while(cin >> s){
        str.push_back(s);
    }

    cout << longestStr(str);



    return 0;
}

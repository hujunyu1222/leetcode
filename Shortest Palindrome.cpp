#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getNextArray(string &s){
    vector<int> next(s.size(),0);
    next[0] = -1;
    next[1] = 0;

    int pos = 2;
    int cn = 0;
    while (pos < s.size()){
        if (s[pos-1] == s[cn]){
            next[pos++] = ++cn;
        }
        else if (cn > 0){
            cn = next[cn];
        }
        else{
            next[pos++] = 0;
        }
    }

    return next;
}

string shortestPalindrome(string s) {
    if (s.size() == 0) return "";
    string oriS = s;
    reverse(s.begin(), s.end());

    string combS = oriS + "#" + s + "&";
    vector<int> next = getNextArray(combS);

    cout << combS << endl;

    for (auto x:next){
        cout << x << " ";
    }
    cout << "\n";


    int index = next[next.size() - 1];
    //cout << index << endl;

    if (index < oriS.size()){
        string add = oriS.substr(index);
        reverse(add.begin(), add.end());
        return add + oriS;
    }
    else{
        return oriS;
    }
}

int main(){
    string s = "aabba";

    cout << shortestPalindrome(s);

    return 0;
}

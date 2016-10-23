#include <iostream>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

bool isVowel(char c){

    if (c == 'a' || c == 'e'||c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E'||c == 'I' || c == 'O' || c == 'U' )
        return true;

    return false;

}

int main(){
    string s;
    string res;
    int cnt1, cnt2, cnt3;

    set<char> chSet;

    //freopen("1.txt", "r", stdin);

    getline(cin, s);

    for (int i = 0; i < s.size(); i++){
        if (isVowel(s[i])){
            chSet.insert(s[i]);
            res += s[i];
        }
    }
    cnt1 = chSet.size();
    cnt2 = res.size();
    cnt3 = s.size() - res.size();

    cout << cnt1 <<" "<< cnt2 << " "<< cnt3 << endl;
    cout << res << endl;

    return 0;



}

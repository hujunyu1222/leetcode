#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
    string str = "#";
    string res = "";
    int i, n, maxl;
    n = s.size();
    maxl = 0;

    if (n == 0 || n == 1) return s;

    for (i = 0; i < s.size(); i++){
        str += s[i];
        str += "#";
    }
    cout << str << endl;

    vector<int> pArr(str.size(),0);
    int pR, index;
    int cnt;
    int start, end;

    pR = index = -1;

    for (i = 0; i < str.size(); i++){
        cnt = 0;
        if (i < pR){
            pArr[i] = (pArr[2*index - i] > pR - i ? pR - i : pArr[2*index - i]);
        }
        else {
            pArr[i] = 1;
        }

        while (i - pArr[i] >=0 && (str[i - pArr[i]] == str[i + pArr[i]])) pArr[i]++;

        if (i + pArr[i] > pR){
            pR = i + pArr[i];
            index = i;
        }

        if (pArr[i] > maxl){
            maxl = pArr[i];
            start = i - pArr[i] + 1;
            end = i + pArr[i] - 1;
        }
    }
    cout << maxl << endl;
    cout << start << end << endl;
    for (i = start; i <= end; i++){
        if (str[i] != '#') res += str[i];
    }

    return res;
}

int main(){
    string s = "abcba";
    cout << longestPalindrome(s);
    return 0;
}

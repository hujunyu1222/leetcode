#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//×îÐ¡×Ó´®¸²¸Ç
string minWindow(string &source, string &target) {
    // write your code here
    int map[256] = {0};
    int left, right, match;
    string res = "";
    int minLength = 0x7FFFFFFF;

    left = right = 0;
    match = target.size();

    int i, j;
    for (i = 0; i < target.size(); i++){
        map[target[i]]++;
    }

    while(right < source.size()){
        map[source[right]]--;
        if (map[source[right]] >= 0){
            match--;
        }
        if (match == 0){
            while(map[source[left]] < 0){
                map[source[left++]]++;
            }

            if (right - left + 1 < minLength){
                minLength = right - left + 1;
                res = source.substr(left, minLength);
            }

            match++;
            map[source[left++]]++;
        }

        right++;
    }

    return res;
}

int main(){
    string s1 = "abscbssabeeeec";
    string s2 = "abc";

    string s3 = minWindow(s1,s2);

    cout << s3 << endl;

    return 0;
}

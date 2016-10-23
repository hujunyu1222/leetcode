#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> getNext(const char *target){
        int n = strlen(target);
        vector<int> next(n,0);
        next[0] = -1;

        int cn = 0, pos = 2;

        while(pos < n){
            if (*(target+pos-1) == *(target + cn)){
                next[pos++] = ++cn;
            }
            else if (cn < 0){
                next[pos++] = 0;
            }
            else{
                cn = next[cn];
            }
        }

        return next;

    }

int strStr(const char *source, const char *target) {
        // write your code here
        int sl, tl;
        sl = strlen(source);
        tl = strlen(target);


        if (sl < tl) return -1;

        vector<int> next = getNext(target);
        int i, j;
        i = j = 0;
        while(i < sl && j < tl){
            if (j < 0){
                i++;
                j = 0;
            }
            else if (*(source+i) == *(target+j)){
                i++;
                j++;
            }
            else{
               j = next[j];
            }
        }

        cout << i << j << endl;

        if (j == tl) return i - tl;


        return -1;
}

int main(){
    const char *s1 = "source";
    const char *s2 = "target";

    cout << strStr(s1,s2);


    return 0;
}

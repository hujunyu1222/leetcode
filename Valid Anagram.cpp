#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
        int alp[26]={0};
        int l1, l2;
        int i, j;

        l1 = s.length();
        l2 = t.length();
        i=j=0;

        if (l1 != l2)
        {
            return false;
        }

        for(i=0; i<l1; i++)
        {
            alp[s[i]-'a'] += 1;
        }

        for(j=0; j<l2; j++)
        {
            alp[t[j]-'a'] -= 1;
            if (alp[t[j]-'a'] < 0)
            {
                return false;
            }
        }

        return true;
}

int main(){
    string s1, s2;
    s1 = "";

    return 0;
}

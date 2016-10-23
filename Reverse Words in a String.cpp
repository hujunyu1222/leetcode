#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void removeSpace(string &s){
        while(s.size() > 0 && s[0] == ' '){
            s.erase(0,1);
        }
        //add one space to the end.
        s += ' ';

        for (int i = 0; i < s.size(); i ++)
        {
          while (s[i] == ' ' && s[i + 1] == ' ')
          {
    	    s.erase(i, 1);
          }
        }
        // Remove last space
        s.erase(s.size() - 1, 1);

}

void reverseWords(string &s) {
    removeSpace(s);
        int start, end;

        reverse(s.begin(), s.end());

        for (start = 0, end = 0; end < s.size(); end++){
            if (s[end] == ' '){
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

    reverse(s.begin() + start, s.begin() + end);

}

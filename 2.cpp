#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

 string longestCommonPrefix(vector<string>& strs) {

        int min = 0x7fffffff;
        int max = 0x80000000;
        int i, j, k;
        int flag = 0;

        char result[1000000];
        string s = "";

        cout<<strs.size()<<endl;

        if(strs.size() == 0)
        return s;

        for (i=0; i < strs.size(); i++)
        {
               if(strs[i].length() < min)
               {
                   min = strs[i].length();
                   flag = i;
               }

        }

        cout<<result<<endl;
        if (min == 0)
            return s;

        if(strs.size() == 1)
            return strs[0];

        for (k=0;k<min;k++)
        {
            for (j=0;j<strs.size()-1;j++)
            {
                if(strs[j][k] != strs[j+1][k])
                {
                    result[k]='\0';
                    return result;
                }
            }
            result[k] = strs[0][k];
        }
        result[min]='\0';

        return result;


    }

int main()
{
    vector<string> strs;
    string s;

    strs.push_back("");
//    strs.push_back("aabaaaaa");
//    strs.push_back("aabcaaaaaaaaaaa");
//    strs.push_back("aabaaaaaaaaaaaa");
//    strs.push_back("aabcaaaaa");

//    s = longestCommonPrefix(strs);
//    cout<<s<<endl;

    cout<<2^3<<endl;

    return 0;
}

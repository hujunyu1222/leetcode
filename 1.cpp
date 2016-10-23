#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
//#include <unordered_set>
using namespace std;

//reverse integer
bool isNum(char s)
{
    if(0 <= s - '0' && s - '0' <= 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int reverse(int x) {
        int max = 0x7fffffff;
        int min = 0x80000000;

        int s = x;
        //if (s > max)
        //    return 0;
        long long result = 0;
        int temp = 0;
        while(s!=0)
        {
            result = result *10;
            if (result > max || result < min)
                return 0;
            //cout<<result<<endl;
            result+= s%10 ;
            cout<<result<<endl;
           // if (temp > result)
           //     return 0;
            s=s/10;

        }
        return result;

    }

 int myAtoi(string str) {
        int max = 0x7fffffff;
        int min = 0x80000000;

        int length = str.length();
        int i,start = 0;
        int temp = 0;
        bool flag = false;

        long long s = 0;

        while(str[start++]==' ');
        start--;

        while(str[start]=='+' || str[start]=='-')
        {
            if (str[start]=='+')
            {
                    temp++;
                    flag= true;
            }
            if (str[start] == '-')
            {
                temp--;
                flag= true;
            }
            start++;
        }
        if(temp == 0 && flag)
            return 0;
        while(str[start++]== '0');
            start--;


        for (i = start; i<length; i++)
        {
            if(!isNum(str[i]))
                break;
            cout<<str[i]<<endl;
            if(temp >=0)
            {
                s = s * 10 + str[i] - '0';
            }
            else
            {
                s = s * 10 + (-1)*(str[i] - '0');
            }
             if(s > max )
            {
                return max;
            }

            if(s < min)
            {
                return min;
            }
        }

        return (int)s;



    }

  bool isPalindrome(int x) {
      if (x < 0)
        return false;

        long long s = 0;
        int temp = x;

        while(x!=0)
        {
            s = s * 10 + x % 10;
            cout<<s<<endl;
            x = x / 10;
        }

        return s == temp;

    }
int main()
{
    int s;
    bool f;
    char a;

    cout<<isPalindrome(-2147447412);

    return 0;
}


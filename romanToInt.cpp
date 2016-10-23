#include <iostream>
#include <string>
using namespace std;

int single(char c){
    switch(c)
    {
        case 'I': return 1; break;
        case 'V': return 5; break;
        case 'X': return 10; break;
        case 'L': return 50; break;
        case 'C': return 100; break;
        case 'D': return 500; break;
        case 'M': return 1000; break;
        default: return -1; break;
    }

}

int romanToInt(string s){
    int i = s.length() - 1;
    int result = 0;
    int temp = 0;
    int count=0;

    result = single(s[i--]);

    while (i>=0)
    {
        temp = single(s[i]);

        if (temp >= single(s[i+1]))
        {
           result += temp;
        }
        else
        {
            result -= temp;
        }

        i--;
    }

    return result;

}

int main(){
    int a;
    string s;

    s="DCXXI";
    a = romanToInt(s);

    cout<<a<<endl;

    return 0;
}

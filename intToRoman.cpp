#include <iostream>
#include <string>
using namespace std;


string roman[][10]={{"", "I","II","III","IV","V","VI","VII","VIII","IX"},
    {"", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
    {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
    {"", "M","MM","MMM"}};

string intToRoman(int num) {
    string s[4];
    string result;
    int a[4]={0};
    int i = 0;

    while (num!=0)
    {
        a[3-i]=num%10;
        s[3-i]=roman[i][a[3-i]];
        num = num/10;
        i++;
    }
    result = s[0]+s[1]+s[2]+s[3];

    return result;

}
int main(){
    string s;
    int a = 0;

    a= 621;
    s = intToRoman(a);

    cout<<s<<endl;
    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    unordered_map <int, int> m;
    string ret = "";
    long int n = numerator;
    long int d = denominator;
    long int r = 0;
    int i;

    if (n > 0 ^ d > 0) {
        ret += "-";
    }
    r = n % d;
    ret += to_string(n / d);
    if (r != 0){
        ret += ".";
    }

    for (r = n % d ;r !=0 ; r %= d){
        if (m.find(r) != m.end()){
            ret.insert(m[r],1,'(');
            ret += ')';
            break;
        }

        m[r] = ret.size();

        r = r * 10;
    }

    return ret;




}

int main()
{
    string s;
    s = fractionToDecimal(1,3);
    cout << s << endl;
    return 0;
}

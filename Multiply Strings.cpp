#include <iostream>
#include <string>

using namespace std;

string multiply(string num1, string num2) {
     int len1, len2;
     len1 = num1.size();
     len2 = num2.size();

     int carry = 0;
     int i, j;
     int val;

     string res(len1+len2, '0');


     for (i = len2 - 1; i >= 0; i--){
        carry = 0;
        for (j = len1 - 1; j >= 0; j--){
            val = (num1[j] - '0') * (num2[i] - '0');
            val += res[i + j + 1] - '0';
            val += carry;

            res[i + j + 1] = val % 10 + '0';
            carry = val / 10;
        }
        res[i] = carry + '0';
     }

     i = 0;
     while(res[i] == '0')i++;

      return i == len1 + len2 ? "0" : res.substr(i, len1 + len2 - i);

}

int main(){
    string a = "9";
    string b = "99";

    cout << multiply(a, b) << endl;

    return 0;
}

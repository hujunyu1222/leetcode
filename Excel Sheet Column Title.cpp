#include <iostream>
#include <string>
#include <vector>

using namespace std;


string convertToTitle(int n) {
        string ans;
        while (n-- != 0) {
            ans = char(int('A') + n % 26) + ans;
            n /= 26;
        }
        return ans;
}

int main(){
    int n;
    cin >> n;
    cout << convertToTitle(n) << endl;

    return 0;
}

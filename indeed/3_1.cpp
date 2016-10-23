#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>

using namespace std;

int vis[26] = {0};

bool canChange(string &a, string &b){
    int cnt = 0;
    int i = 0;
    int n = a.size();
    for (i = 0; i < n; i++){
        if (a[i] != b[i]){
            if (cnt == 0){
                vis[a[i] - 'a'] = 1;
                vis[b[i] - 'a'] = 1;
                cnt++;
            }
            else if( !(vis[a[i] - 'a'] == 1 && vis[b[i] - 'a'] == 1) ){
                cnt++;
            }
        }

        if (cnt > 1) return false;

    }

    return true;
}

/*
bool canChange(string &a, string &b){
    unordered_map<char, char> m;
    int cnt = 0;
    int i = 0;
    int n = a.size();
    for (i = 0; i < n; i++){
        if (a[i] != b[i]){
            if (cnt == 0){
                m[a[i]] = b[i];
                m[b[i]] = a[i];
                cnt++;
            }
            else if(m[a[i]] != b[i]){
                cnt++;
            }
        }

        if (cnt > 1) return false;

    }

    return true;
}
*/

int main(){
    string a;
    string b;

    cin >> a >> b;

    if (canChange(a, b)) cout << "Possible\n";
    else cout << "Impossible\n";

    return 0;
}



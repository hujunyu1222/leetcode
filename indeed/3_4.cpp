#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;
string s;
int N;
const int MAXN = 300010;
int arr[MAXN];

void solve()
{
    long long res = 0;
    int minv = arr[0];
    int num = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')') num--;
        else num++;
        if(num <= -1)
        {
            num++;
            res += minv;
        }
        minv = min(minv, arr[i + 1]);
    }
    minv = arr[s.size()];
    num = 0;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(s[i] == ')') num++;
        else num--;
        if(num <= -1)
        {
            num++;
            res += minv;
        }
        minv = min(minv, arr[i]);
    }
    cout<<res<<endl;
}

int main()
{
    while(cin>>N>>s)
    {
        memset(arr, 0, sizeof(arr));
        for( int i = 0 ; i < N + 1; i++ ) cin>>arr[i];
        solve();
    }

    return 0;
}



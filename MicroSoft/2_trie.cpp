#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define SIZE(x) (int)x.size()
#define MP(x,y) make_pair(x,y)
#define ALL(t) (t).begin(),(t).end()
#define clr(x,y) memset(x,y,sizeof(x))
#define FOR(i,n,m) for (int i = n; i <= m; i++)
#define ROF(i,n,m) for (int i = n; i >= m; i--)

#define RI(x) scanf ("%d", &(x))
#define RII(x,y) RI(x),RI(y)
#define RIII(x,y,z) RI(x),RI(y),RI(z)

typedef long long ll;
const int mx = 32e5 + 5;

string a[100005];
int chd[mx][2], val[mx], cnt = 1;

void insert (string s, int id){
	int now = 0;
	FOR (i, 0, SIZE (s)-1){
		if (!chd[now][s[i] - '0']){
			chd[now][s[i] - '0'] = cnt ++;
		}
		now = chd[now][s[i] - '0'];
	}
	//记录最早的id，防止被后面的id覆盖
	if (!val[now]){
		val[now] = id;
	}
}

bool query (string s){
	int now = 0, ans = 150000;
	if (val[now]){
		ans = val[now];
	}
	FOR (i, 0, SIZE (s)-1){
		if (!chd[now][s[i] - '0']){
			break;
		}
		now = chd[now][s[i] - '0'];
		if (val[now] && val[now] < ans){
			ans = val[now];
		}
	}
	if (ans  == 150000){
		return 1;
	}
	return a[ans] == "allow";
}

int main (){
	int n, m;
	cin >> n >> m;
	FOR (i, 1, n){
		string s;
		cin >> a[i] >> s;
		stringstream ss(s + '.');
		vector<int> vec;
		int t;
		char c;
		while (ss >> t >> c){
			vec.PB (t);
		}
		ll x = 0;
		FOR (j, 0, 3){
			x = (x << 8) + vec[j];
		}
		int ttt = 32;
		if (SIZE (vec) > 4){
			x >>= (32-vec[4]);
			ttt = vec[4];
		}
		string sx;
		while (ttt--){
			sx += (char)((x&1) + '0');
			x >>= 1;
		}
		reverse (ALL (sx));
		insert (sx, i);
	}
	FOR (i, 1, m){
		string s;
		cin >> s;
		stringstream ss(s + '.');
		vector<int> vec;
		int t;
		char c;
		while (ss >> t >> c){
			vec.PB (t);
		}
		ll x = 0;
		FOR (j, 0, 3){
			x = (x << 8) + vec[j];
		}
		string sx;
		int ttt = 32;
		while (ttt--){
			sx += (char)((x&1) + '0');
			x >>= 1;
		}
		reverse (ALL (sx));
		cout << (query (sx) ? "YES" : "NO") << endl;
	}
}


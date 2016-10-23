#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int solve(int Weight[], int nLen, int nCapacity) {
	int dp[nCapacity + 1];
	memset(dp, 0, sizeof(dp));

	dp[0] = 1;

	for(int i = 0; i < nLen; i++) {
		for(int j = nCapacity; j >= Weight[i]; j--) {
				dp[j] += dp[j-Weight[i]];
		}
	}

	return dp[nCapacity];
}

const int mx = 1005;

int n, w[mx], s;


int main() {

    freopen("sum.txt", "r", stdin);

    cin >> n >> s;

    for (int i = 0; i < n; i++) cin >> w[i];

    cout << solve(w, n, s) << endl;

	system("pause");
    return 0;
}



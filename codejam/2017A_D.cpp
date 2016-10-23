#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int f[20][2020];
int a[30];
int c[30];
int t, m, n, K, L;
int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("2017A_D_out.txt", "w", stdout);

	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d%d", &m, &n);
		memset(f, 0, sizeof f);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &K, &L);
			L -= 1;
			memset(c, 0, sizeof c);
			for (int j = 0; j < K; j++) {
				scanf("%d", &a[j]);
			}
			for (int j = 1; j < K; j++) {
				scanf("%d", &c[j]);
				if (j <= L) {
					c[j] = 0;
				}
				c[j] += c[j - 1];
			}
			for (int j = L; j < K; j++) {
				for (int k = c[j]; k <= m; k++) {
					f[i][k] = max(f[i][k], f[i - 1][k - c[j]] + a[j]);
				}
			}
		}
		if (n != 8) {
			cerr << "ERROR" << endl;
		}
		printf("Case #%d: %d\n", tt, f[n][m]);
	}
	return 0;
}

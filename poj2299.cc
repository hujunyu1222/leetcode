/********************************************************************
  >  Author: hujunyu
  >  File Name: poj2299.cc
  >  Mail: hujunyu1222@gmail.com
  >  Created Time: Sun 09 Apr 2017 09:11:09 AM CST
  >  Start of something new | Do cool things that matters
 *******************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define bits(a)     __builtin_popcount(a)

#define PB          push_back
#define SIZE(x)     (int)x.size()
#define MP(x,y)     make_pair(x,y)
#define All(t)      (t).begin(),(t).end()
#define CLR(x,y)    memset(x,y,sizeof(x))
#define FOR(i,n,m)  for (int i = n; i <= m; i++)
#define ROF(i,n,m)  for (int i = n; i >= m; i--)

#define RI(x)       scanf ("%d", &(x))
#define RII(x,y)    RI(x),RI(y)
#define RIII(x,y,z) RI(x),RI(y),RI(z)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

/***********************END OF DEFINE******************************/

//Binary Indexed Tree
//http://poj.org/problem?id=2299

const int maxSize = 500005;
long long ori[maxSize],cop[maxSize];
int N;
int ord[maxSize], sum[maxSize];


int lowbit(int k){
	return k & (-k);
}

void modify(int t, int v){
	while(t <= N){
		sum[t] += v;
		t += lowbit(t);
	}

}

int Sum(int t){
	int res = 0;
	while(t > 0){
		res += sum[t];
		t -= lowbit(t);
	}

	return res;
}

int binary_sear(long long v,long long a[],int l,int r){
	int mid;
	while(l < r){
		mid = (l + r) >> 1;
		if (v == a[mid]) return mid;
		else if (v > a[mid]) l = mid + 1;
		else r = mid - 1;
	}

	return l;

}


int main(){
	freopen("poj2299.txt","r",stdin);

	int res;
	while(cin >> N){
		if (N == 0) return 0;
		memset(sum, 0, sizeof(sum));
		res = 0;
		for (int i = 1; i <= N; ++i){
				cin >> ori[i];
				cop[i] = ori[i];
		}

		sort(&cop[1], &cop[N]);

		for (int i = 1; i <= N; ++i){
				ord[i] = binary_sear(ori[i], cop, 1, N);
				modify(ord[i], 1);//统计数量
				res += i - Sum(ord[i]);//当前情况下换到合适位置需要的两两交换次数
		}
		cout << res << endl;
	
	}



	return 0;
}

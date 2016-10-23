#include <iostream>
#include <bits/stdc++.h>

using namespace std;


string num[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

string transfer(long long m, long long n)
{
	string res;
	bool flag = m > 0 ? false : true;

	m = abs(m);

	if(m == 0)
		return "0";
	while(m)
	{
		long long t = m % n;
		m /= n;
		res = num[t] + res;
	}

	if (flag) res = "-" + res;

	return res;
}

int main()
{
	long long n, m;
	while(cin>>m>>n)
	{
		cout<<transfer(m, n)<<endl;
	}

	return 0;
}

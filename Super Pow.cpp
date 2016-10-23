#include <iostream>
#include <string>
#include <vector>

using namespace std;

string divide(string s){
        //´óÊý³ý2
        string res = "";
        int rest = 0;
        int tmp = 0;
        if (s[0] == '1'){
            if (s.size() == 1){
                res = "0";
                return res;
            }
            rest = 1;
        }
        else{
            res += (s[0] - '0') / 2 + '0';
            rest = (s[0] - '0') % 2;
        }

        for (int i = 1; i < s.size(); i++){
            tmp = rest * 10 + (s[i] - '0');
            res += tmp / 2 + '0';
            rest = tmp % 2;
        }

        return res;
}

int superPow(int a, vector<int>& b) {
        string index = "";
        int i;

        for (auto x:b){
            index += '0' + x;
        }
        cout << index << endl;

        long long sum = 1;
        long long tmp = a;
        while(index.compare("0") != 0){
            //cout << index << endl;
            if ((index[index.size()-1] - '0') & 1){
                sum = (sum * tmp) % 1337;
            }
            tmp = (tmp * tmp) % 1337;
            //cout << tmp << endl;

            index = divide(index);
        }

        return sum;

}

int superPow2(int a, vector<int>& b)
{
    if (b.size() == 0) return 1;

	const int D = 1337;
	int A = a % D;
	vector<int> v(10, 0);
	v[0] = 1;
	for (int i = 1; i < 10; i++)
	{
		v[i] = (v[i - 1] * A) % 1337;
	}

	int L = v[b[0]];

	for (int i = 1; i < b.size(); i++)
	{
		int M = 1;

		int j = 10;
		while(j != 0){
            if(j & 1){
                M = M * L % D;
            }
            L = L * L % D;
            j = j >> 1;
		}
		/*
		for (int i = 0; i < 10; i++)
		{
			M = M*L % D;
		}
		*/

		M = M*v[b[i]] % D;
		L = M;
	}

	return L;
}

int main(){
    string s = "200";
    vector<int> b = {1,0,2,5,3};
    cout << superPow2(2,b) << endl;
    cout << divide(s);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthSmallest(vector<vector<int>>& ma, int k)
	{
		int r = ma.size();
		int le = -1e9, ri = 1e9;
		int mid = 0;
		int i, j;
		while (le < ri)
		{
			mid = (le + ri) >> 1;
			int num = 0;
			for (i = 0; i < r; i++)
			{
				int pos = upper_bound(ma[i].begin(), ma[i].end(), mid) - ma[i].begin();
				num += pos;
			}

            if (num < k)
			{
				le = mid + 1;
			}
			else
			{
				ri = mid;
			}
		}
		return le;
}

int main(){
    vector<vector<int> > matrix{{1,  5,  9}, {10, 11, 13}, {12, 12, 15}};
    //cout << kthSmallest(matrix, 8);

    vector<int> m{1,5,9,10,11,12,13,13,15};
    int pos = lower_bound(m.begin(), m.end(), 13) - m.begin();

    cout << pos << endl;

    return 0;
}

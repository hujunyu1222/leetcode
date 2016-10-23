#include <iostream>
#include <vector>
using namespace std;

vector<int> getPartition(const vector<vector<int> >& land, int n, int m) {
        int index;
        vector<int> toB(n,0);
        vector<int> res(2);
        int minError;
        int tmp;
        int i, j;
        int sum = 0;

        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                toB[j] += land[i][j];

            }
        }

        for (j = 0; j < n; j++){
            sum += m - toB[j];
        }
        cout << sum << endl;
        minError = sum;
        index = 0;
        tmp = sum;

        for (j = 0; j < n; j++){
            tmp = tmp + 2*toB[j] - m;
            if (tmp < minError){
                minError = tmp;
                index = j+1;
            }
        }

        res[0] = index;
        res[1] = index + 1;

        return res;

}


int main(){
    int a[4] = {1,0,1,1};
    vector<int> v1(a,a+4);
    vector<int> v2(4,1);
    vector<int> v3(4,0);

    vector<int> res(2);

    vector<vector<int> > land;
    land.push_back(v1);
    land.push_back(v2);
    land.push_back(v3);

    res = getPartition(land, 4, 3);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}

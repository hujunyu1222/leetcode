#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, m;
    freopen("1.txt", "r", stdin);

    while(cin >> n >> m){

    unordered_map<string, long long> numMap;
    vector<long long> nums;
    vector<long long> price;

    price = vector<long long>(n, 0);

    int i, j;
    long long minP, maxP;
    string cargo;


    for (i = 0; i < n; i++){
        cin >> price[i];
    }

    for (i = 0; i < m; i++){
        cin >> cargo;
        if (numMap.find(cargo) == numMap.end()){
            numMap[cargo] = 1;
        }
        else{
            numMap[cargo]++;
        }
    }

    for (auto x:numMap){
        nums.push_back(x.second);
    }

    sort(nums.begin(), nums.end());
    sort(price.begin(), price.end());


    minP = maxP = 0;

    m = nums.size();

    for (i = 0; i < m; i++){
        //cout << price[i] << " " << price[n - i - 1] << endl;
        minP = minP + nums[m - i - 1] * price[i];
        maxP = maxP + nums[m - i - 1] * price[n - i - 1];
        //cout << minP << endl;
        //cout << maxP << endl;
    }

    cout << minP << " " << maxP << endl;

    numMap.clear();
    nums.resize(0);
    price.resize(0);

    }



    return 0;
}

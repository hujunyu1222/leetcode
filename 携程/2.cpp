#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int profit = INT_MIN;
        int i = 0;
        int n = prices.size();

        if (n == 0 || n == 1){
            return 0;
        }

        for (i = 0; i < n; i++){
            if (prices[i] < min){
                min = prices[i];
            }

            profit = max(prices[i] - min, profit);
        }

        return profit;


}

int main(){
    //freopen("2.txt", "r", stdin);

    string s;
    vector<int> prices;

    getline(cin, s);

    stringstream ss(s + ',');

    int p;
    char ch;
    while(ss >> p >> ch ){
        prices.push_back(p);
    }

    cout <<  maxProfit(prices) << endl;


    return 0;
}

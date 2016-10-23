#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*核心思想：
1. 创建辅助数组 sells 和 buys
2. 设当天与前天股票价格差：
    delta = prices[i] - prices[i - 1]
核心动归思想：
    //第i天卖出的最大累积收益 = max(第i-1天买入~第i天卖出的最大累积收益, 第i-1天卖出后反悔~改为第i天卖出的最大累积收益)
    sells[i] = max (buys[i - 1] + prices[i], sells[i-1] + delta);
    //第i天买入的最大累积收益 = max(第i-2天卖出~第i天买入的最大累积收益, 第i-1天买入后反悔~改为第i天买入的最大累积收益)
    //注：因为存在cooldown，所以是i - 2 天卖出
    buys[i] = max (sells[i - 2] - prices[i], buys[i-1] - delta);

*/
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int *sells = new int[n];
    int *buys = new int[n];
    int i, j;
    int Max = -1;
    int delta = 0;

    sells[0] = 0;
    buys[0] = -prices[0];
    buys[1] = buys[0] - (prices[1] - prices[0]);

    for (i = 1; i < n; i++){
        delta = prices[i] - prices[i - 1];
        sells[i] = max (buys[i-1] + prices[i], sells[i-1] + delta);
        if (i > 1){
            buys[i] = max (sells[i-2] - prices[i], buys[i-1] - delta);
        }
    }

    for (i = 0 ; i < n; i++){
        if (Max < sells[i]){
            Max = sells[i];
        }
    }
    return Max;
}

int main(){
    vector<int> stock = {1,2,3,0,2};
    cout << maxProfit(stock) <<endl;
    return 0;
}


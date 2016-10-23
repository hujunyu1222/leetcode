#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*����˼�룺
1. ������������ sells �� buys
2. �赱����ǰ���Ʊ�۸�
    delta = prices[i] - prices[i - 1]
���Ķ���˼�룺
    //��i������������ۻ����� = max(��i-1������~��i������������ۻ�����, ��i-1�������󷴻�~��Ϊ��i������������ۻ�����)
    sells[i] = max (buys[i - 1] + prices[i], sells[i-1] + delta);
    //��i�����������ۻ����� = max(��i-2������~��i�����������ۻ�����, ��i-1������󷴻�~��Ϊ��i�����������ۻ�����)
    //ע����Ϊ����cooldown��������i - 2 ������
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


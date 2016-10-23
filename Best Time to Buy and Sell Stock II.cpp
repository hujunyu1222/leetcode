#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int res = 0;
    int index, tmp;
    index = tmp = 0;
    for (int i = 1; i < prices.size(); i++){
        if (prices[i] > prices[index] && (prices[i] - prices[index] > tmp)){
            tmp = prices[i] - prices[index];
        }
        else{
            index = i;
            res += tmp;
            tmp = 0;
        }
    }

    return tmp == 0 ? res : res+tmp;
}


int main(){

    return 0;
}

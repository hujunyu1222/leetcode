#include <iostream>
using namespace std;

//用于计算每个无符号数u的bit中含有多少个1
unsigned popcount (unsigned u)
{
    u = (u & 0x55555555) + ((u >> 1) & 0x55555555);
    u = (u & 0x33333333) + ((u >> 2) & 0x33333333);
    u = (u & 0x0F0F0F0F) + ((u >> 4) & 0x0F0F0F0F);
    u = (u & 0x00FF00FF) + ((u >> 8) & 0x00FF00FF);
    u = (u & 0x0000FFFF) + ((u >> 16) & 0x0000FFFF);
    return u;
}
//解法1
//对于每个i（0<= i <= num），调用popcount，将结果存入vector中
vector<int> countBits1(int num){
    vector<int> result;
        int i;
        for (i = 0; i <= num; i++ ){
            result.push_back(popcount(i));
        }

        return result;
}

//解法2：
//很巧妙，时间复杂度只有O(n)
vector<int> countBits2(int num) {
    vector<int> result(num+1, 0);
    int index = 0;
    int i;
    for (i = 1; i <= num; i++){
        //最高位相同，则result[i]等于result[i-index] + 1,因为result[i]跟result[i-index]
        //只差最高位的1，其他bit位都相同
        if (i & i-1){
            result[i] = result[i - index] + 1;
        }
        //最高位进位
        else{
            result[i] = 1;
            index = i;
        }
    }

    return result;
}

int main(){
    unsigned a = 7;
    vector<int> num;

    return 0;
}

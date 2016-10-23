#include <iostream>
using namespace std;

//���ڼ���ÿ���޷�����u��bit�к��ж��ٸ�1
unsigned popcount (unsigned u)
{
    u = (u & 0x55555555) + ((u >> 1) & 0x55555555);
    u = (u & 0x33333333) + ((u >> 2) & 0x33333333);
    u = (u & 0x0F0F0F0F) + ((u >> 4) & 0x0F0F0F0F);
    u = (u & 0x00FF00FF) + ((u >> 8) & 0x00FF00FF);
    u = (u & 0x0000FFFF) + ((u >> 16) & 0x0000FFFF);
    return u;
}
//�ⷨ1
//����ÿ��i��0<= i <= num��������popcount�����������vector��
vector<int> countBits1(int num){
    vector<int> result;
        int i;
        for (i = 0; i <= num; i++ ){
            result.push_back(popcount(i));
        }

        return result;
}

//�ⷨ2��
//�����ʱ�临�Ӷ�ֻ��O(n)
vector<int> countBits2(int num) {
    vector<int> result(num+1, 0);
    int index = 0;
    int i;
    for (i = 1; i <= num; i++){
        //���λ��ͬ����result[i]����result[i-index] + 1,��Ϊresult[i]��result[i-index]
        //ֻ�����λ��1������bitλ����ͬ
        if (i & i-1){
            result[i] = result[i - index] + 1;
        }
        //���λ��λ
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

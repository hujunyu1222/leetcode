#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����Ͱ�ţ���Ŵ�0��ʼ��ʹ��long��Ϊ�˷�ֹ������
int getBucketId(long num, long len, long minNum, long maxNum){
    return (int) (num - minNum) * len / (maxNum - minNum);
}

//����Ͱ�ţ�����û������
int maximumGap(vector<int>& nums) {
    int minNum = 0x7FFFFFFF;
    int maxNum = 0xFFFFFFFF;

    int i, j;
    int n = nums.size();
    if (n <= 1) return 0;

    for (auto x:nums){
        minNum = min(x, minNum);
        maxNum = max(x, maxNum);
    }

    vector<int> mins(n+1);
    vector<int> maxs(n+1);
    vector<bool> vis(n+1, false);
    //Ͱ��
    int bid = 0;

    for (i = 0; i < n; i++){
        bid = getBucketId(nums[i], n, minNum, maxNum);
        mins[bid] = vis[bid] ? min(mins[bid], nums[i]) : nums[i];
        maxs[bid] = vis[bid] ? max(maxs[bid], nums[i]) : nums[i];
        vis[bid] = true;
    }

    int res = 0;
    int lastMax = 0;
    i = 0;
    //�ҵ���һ���ǿյ�Ͱ
    while(true){
        if (vis[i]){
            lastMax = maxs[i];
            break;
        }
        i++;
    }

    //�Ƶ���һ��Ͱ
    i++;

    for ( ; i < n+1; i++){
        if (vis[i]){
            res = max(res, mins[i] - lastMax);
            lastMax = maxs[i];
        }
    }

    return res;
}

int main(){
    int a[] = {1,9,3,10};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));

    cout << maximumGap(nums);

    return 0;
}

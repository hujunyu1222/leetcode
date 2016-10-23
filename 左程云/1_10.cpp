#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int getNumOfSubarr(vector<int> &arr, int num){
    //两个双端对了维护子数组的最大和最小值
    //队列中存放数组下标

    deque<int> qmin;
    deque<int> qmax;

    int res = 0;
    int l, r;
    l = r = 0;

    while (l < arr.size()){

        while (r < arr.size()){
            while(!qmin.empty() && arr[qmin.back()] >= arr[r]){ // ">= 而不是 >"很重要，用于处理子数组只含一个元素的情况
                qmin.pop_back();
            }
            qmin.push_back(r);

            while(!qmax.empty() && arr[qmax.back()] <= arr[r]){ // "<="跟上面相同
                qmax.pop_back();
            }
            qmax.push_back(r);

            if (arr[qmax.front()] - arr[qmin.front()] > num){
                break;
            }
            r++;
        }
        if (qmin.front() == l){
            qmin.pop_front();
        }
        if (qmax.front() == l){
            qmax.pop_front();
        }
        //cout << "r: " << r  <<" " << arr[r]<< " l: " << l <<" " << arr[l]<< endl;
        res += r - l;
        l++;
    }

    return res;

}

int main(){
    vector<int> arr{2,3,5,14,16,9,21,6,9};
    int num = 10;

    cout << getNumOfSubarr(arr, num);
    return 0;
}

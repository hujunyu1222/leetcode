#include <iostream>
#include <vector>

using namespace std;



int minJump(int arr[], int pos, int n){
    if (pos == n - 1){
        return 0;
    }

    int minStep = 0x7FFFFFFF;
    int i;
    for (i = 1; i <= arr[pos] && pos + i < n; i++){
        minStep = min(minJump(arr, pos+i, n), minStep);
    }

    return minStep + 1;

}

int minJump2(int arr[], int n){
    int maxIndex, curIndex;
    int cnt = 0;

    int i;
    maxIndex = -1;
    curIndex = 0;
    for (i = 0; i < n; i++){
        if (curIndex < i){
            curIndex = maxIndex;
            cnt++;
        }
        maxIndex = max(arr[i]+i, maxIndex);
        if (maxIndex >= n) break;
    }

    return cnt;

}

int main(){
    int arr[] = {3,2,2,1,1,4};
    cout << minJump(arr, 0, 6) << endl;
    cout << minJump2(arr, 6) << endl;
    return 0;
}

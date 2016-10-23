#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mx = 1e6 + 7;

int arr[mx] = {0};
int n;

int search(int num){
    int l , r, mid;

    l = 0;
    r = n - 1;

    while(l <= r){
        mid = (l + r) >> 1;
        if (arr[mid] == num){
            while(arr[--mid] == num);
            return mid + 1;
        }
        else if (arr[mid] > num){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    //cout << mid << endl;

    if (arr[mid] == num){
        return mid;
    }
    else if (arr[mid] < num){
        return -1-(mid+1);
    }
    else{
        return -1-mid;
    }



}

int main(){
    int num;
    cin >> num >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << search(num) << endl;


    return 0;
}

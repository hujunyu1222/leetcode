#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A){
    int n = A.size();
    if (n == 0) return -1;

    vector<long long> pre_sum(A.size(), 0);
    long long sum = 0;
    int i;
    for (i = 0; i < n; i++){
        sum += A[i];
        pre_sum[i] = sum;
    }


    sum = 0;
    for (i = n - 2; i > 0; i--){
        sum += A[i+1];
        if (pre_sum[i - 1] == sum){
            return i;
        }
    }

    if (pre_sum[n - 1] - pre_sum[0] == 0) return 0;
    if (pre_sum[n - 2] == 0) return n - 1;

    return -1;

}

int main(){
    vector<int> A{-1, 3, -4, 5, 1, -6, 2, 1};

    cout << solution(A);

    return 0;
}

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 35;
long long mod = 1e9 + 7;

struct Matrix{

 int m[N][N];
 //初始化为单位矩阵
 Matrix(){
    memset(m, 0, sizeof(m));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j) m[i][j] = 1;
        }
    }
 }

};

//方阵的乘法
Matrix mat_mul(Matrix a, Matrix b, int n){
    Matrix ans;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans.m[i][j] = 0;
            for (int k = 0; k < n; k++){
                ans.m[i][j] += a.m[i][k] * b.m[k][j] % mod;
            }
        }
    }

    return ans;
}

Matrix mat_pls(Matrix &a, Matrix &b, int n){
    Matrix ans;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) ans.m[i][j]--;
            ans.m[i][j] = a.m[i][j] + b.m[i][j];
        }
    }

    return ans;
}

Matrix fast_mod(Matrix A, long long k, int n){
    Matrix ans;
    while(k){
        if (k & 1) ans = mat_mul(ans, A, n);
        A = mat_mul(A, A, n);
        k = k >> 1;
    }

    return ans;

}

int main(){
    Matrix a, b;
    Matrix res;
    a.m[0][0] = 1;
    a.m[0][1] = 1;
    a.m[1][0] = 1;
    a.m[1][1] = 0;

    b.m[0][0] = 1;
    b.m[0][1] = 1;
    b.m[1][0] = 0;
    b.m[1][1] = 0;

    int n;
    cin >> n;

    if (n == 1 || n == 2) cout << "1\n";
    else{
        res = mat_mul(b, fast_mod(a, n - 2, 2), 2);
        cout << res.m[0][0] << endl;
    }

    return 0;


}


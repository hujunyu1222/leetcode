#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

//先给1~m的生成函数， 做一个等概率生成 1~n的函数


void f1(){
    int a[10] = {1,2,12,4,85,15,32,41,102,100};
    int maxN = a[0];
    int minN = a[9];
    int start, end;
    start = end = -1;

    for (int i = 1; i < 10; i++){
        if (maxN > a[i]){
            end = i;
        }
        else{
           maxN = max(maxN, a[i]);
        }

    }

    for (int j = 9; j >= 0; j--){
        if (minN < a[j]){
            start = j;
        }
        else{
            minN = min(minN, a[j]);
        }
    }

    cout <<"start: "<< start << " end: " << end << endl;



}

//最大乘积子串
void f2(){
    float arr[7] = {-2.5, 4, 0, 3, 0.5, 8, -1};
    float minN, maxN;
    float maxToa = 0;
    int i;

    minN = maxN = 0;

    for (i = 0; i < 7; i++){
        if (arr[i] < 0){
            maxN = max(minN*arr[i], arr[i]);
            minN = min(minN, arr[i]);

        }else if (arr[i] > 0) {
            maxN = max(arr[i], maxN*arr[i]);
            minN = min(minN, minN* arr[i]);

        }
        else{
            minN = 0.0;
            maxN = 0.0;
        }
        maxToa = max(maxToa, maxN);
    }
    cout << maxToa << endl;

}

void PrintCircle(int x1, int y1, int x2, int y2, vector<vector<int>> &m){
    if (x1 == x2 && y1 == y2) {
        cout << m[x1][y1];
        return;
    }
    //else if (x1 > x2) return;

    int i, j;

    for (j = y1; j < y2; j++){
        cout << m[x1][j] << " ";
    }
    for (i = x1; i < x2; i++){
        cout << m[i][y2] << " ";
    }
    for (j = y2; j > y1; j--){
        cout << m[x2][j] << " ";
    }
    for (i = x2; i > x1; i--){
        cout << m[i][y1] << " ";
    }

}
//顺时针打印矩阵
void f3(){
    int n;
    cin >> n;

    vector<vector<int> > matrix(n+1,vector<int>(n+1,0));
    int i, j;
    int x1, y1, x2, y2;
    int cnt = 1;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            matrix[i][j] = cnt++;
        }
    }
    x1 = y1 = 1;
    x2 = y2 = n;

    while(x1 <= x2){
        PrintCircle(x1,y1,x2,y2,matrix);
        x1++, y1++;
        x2--, y2--;
    }

}


void push(vector<string> &v, int n, string s){
    if (n > 0){
        push(v, n - 1, "down");
        v.push_back(s);
        push(v, n - 1, "up");
    }
    return;
}

//折纸问题
void f4(){
    int n;
    //对折次数
    cin >> n;
    vector<string> v;


}

int f5() {
    ll S, r, ret = 0;
    while (cin >> S) {
        ret = 0;
        r = ceil(sqrt(S));
        for (ll i = 1; i < r; i++) {
            ll j = sqrt(S - i * i);
            if (i * i + j * j == S /*|| i * i + (j + 1) * (j + 1) == S || i * i + (j - 1) * (j - 1) == S*/)
                ret ++;
        }
        ret = (ret + 1) * 4;
        if (r * r != S) ret -= 4;
        cout << ret << endl;
    }
    return 0;
}

int main(){
    //f2();
    //f3();
    f5();
    return 0;
}

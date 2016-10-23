#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std;

struct point
{
    int x, y;
};

bool mult(point sp, point ep, point op)
{
    return (sp.x - op.x) * (ep.y - op.y) >= (ep.x - op.x) * (sp.y - op.y);
}

bool operator < (const point &l, const point &r)
{
    return l.y < r.y || (l.y == r.y && l.x < r.x);

}

int graham(vector<point> &pnt, int n, vector<point> &res)
{
    int i, len;
    int k = 0, top = 1;

    sort(pnt.begin(), pnt.end());

    if (n == 0) return 0;
    res[0] = pnt[0];
    if (n == 1) return 1;
    res[1] = pnt[1];
    if (n == 2) return 2;
    res[2] = pnt[2];

    for (i = 2; i < n; i++)
    {
        while (top && mult(pnt[i], res[top], res[top-1]))
            top--;
        res[++top] = pnt[i];
    }
    len = top;
    res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; i--)
    {
        while (top!=len && mult(pnt[i], res[top], res[top-1])) top--;
        res[++top] = pnt[i];
    }
    return top; // 返回凸包中点的个数
}




int main(void)
{
    int nPtCnt;
    string s;
    char ch;
    vector<point> pnt;
    vector<point> res;
    int cnt = 0;

    freopen("3.txt", "r", stdin);
    getline(cin, s);

    stringstream ss;

    s = s + ';';
    ss << s;

    ss >> nPtCnt >> ch;
    int x, y;

    for (int i = 0; i < nPtCnt; i++){
        ss >> x >> ch >> y >> ch;
        point tmp = {x, y};
        pnt.push_back(tmp);
    }

    int n = pnt.size();

    res = vector<point>(n,{0x7FFFFFFF,0x7FFFFFFF});

    cnt = graham(pnt, n, res);

    int minX = 0x7FFFFFFF, index;

    for (int i = 0; i < cnt; i++){
        if (res[i].x < minX){
            minX = res[i].x;
            index = i;
        }

    }


    for (int i = 0; i < cnt; i++){
        cout << res[i].x << "," << res[i].y << ";\n";

    }

    int printCnt = 0;
    for (int i = index; i >= 0; i--){
        cout << res[i].x << "," << res[i].y;
        printCnt++;
        if (printCnt != cnt) cout << ";";
    }

    for (int i = cnt - 1; i != index; i--){
        cout << res[i].x << "," << res[i].y;
        printCnt++;
        if (printCnt != cnt) cout << ";";
    }


    return 0;
}

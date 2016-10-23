#include <iostream>
#include <unordered_map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

//对于每个点，连接其与其他的点。
int maxPoints(vector<Point>& points) {
    int n = points.size();
    int i, j;
    int samePoints, sameX;
    int result = 0;
    //斜率
    double k = 0.0;
    unordered_map <double, int> m;
    i = j = 0;


    for (i = 0; i < n; i++){
        samePoints = 1;
        sameX = 0;
        for (j = i + 1; j<n; j++){
            if (points[j].x == points[i].x && points[j].y == points[i].y){
                samePoints++;
            }
            else if (points[j].x == points[i].x){
                //单独判断斜率k为0的情况
                sameX++;
            }
            else{
                k = (points[j].y - points[i].y)*1.0 / (points[j].x - points[i].x)*1.0;
                if (m.find(k) != m.end()){
                    m[k]++;
                }
                else{
                    m[k]= 1;
                }
            }
        }
        result = max(result, samePoints + sameX);
        for(auto x=m.begin(); x!=m.end(); x++)
                result=max(result, x->second + samePoints);
            my.clear();

    }

    return result;



}

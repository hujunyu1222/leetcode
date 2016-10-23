#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval n1, Interval n2){
    if (n1.start != n2.start){
        if (n1.start < n2.start)
        {
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if (n1.end < n2.end){
            return true;
        }
        else{
            return false;
        }
    }

}


vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    Interval tmp;
    int n = intervals.size();

    if (n == 0) return res;

    sort(intervals.begin(), intervals.end(), compare);

    int i, j;
    tmp = intervals[0];

    for (i = 1; i < n; i++){

        if ( intervals[i].start <= tmp.end ){
            tmp.end = max(intervals[i].end, tmp.end);
        }
        else{
            res.push_back(tmp);
            tmp.start = intervals[i].start;
            tmp.end = intervals[i].end;
        }
    }
        //一定记得这一步
        res.push_back(tmp);


    return res;


}

void PrintVec(vector<Interval> &v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i].start << ":" << v[i].end << endl;
    }
}

int main(){
    vector<Interval> v1;
    vector<Interval> res;
    Interval n1(1,3);
    Interval n2(2,6);
    Interval n3(8,10);
    Interval n4(12,15);
    v1.push_back(n1);
    v1.push_back(n2);
    v1.push_back(n3);
    v1.push_back(n4);

    sort(v1.begin(), v1.end(), compare);
    res = merge(v1);

    PrintVec(res);

    return 0;
}

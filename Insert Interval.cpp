#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};

//O(n)
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    bool hasInsert = false;

    for (auto x:intervals){
        if (hasInsert){
            res.push_back(x);
        }
        else {
            if (newInterval.end < x.start){
                res.push_back(newInterval);
                res.push_back(x);
                hasInsert = true;
            }
            else if (newInterval.start > x.end){
                res.push_back(x);
            }
            else{
                newInterval.start = min(x.start, newInterval.start);
                newInterval.end = max(x.end, newInterval.end);
            }

        }
    }
    if (!hasInsert)res.push_back(newInterval);

    return res;

}

//二分查找区间
//查找并合并区间的时间复杂度为O(logN)，由于所有区间要添加，所以总时间是O(N)
int binary_search(vector<Interval>& intervals, int target) {
    if (intervals.empty()) return -1;
    int low = 0, high = intervals.size() - 1;
    while (low < high) {
        int mid = (low + high) >> 1;
        if (target > intervals[mid].start) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return intervals[low].start <= target ? low : low - 1;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ret;
    int i1 = binary_search(intervals, newInterval.start),
        i2 = binary_search(intervals, newInterval.end);
    int c = ((i1 == -1 || newInterval.start > intervals[i1].end) ? 0 : 1) +
        ((i2 == -1 || newInterval.end > intervals[i2].end) ? 0 : 2);
    for (int i = 0; i <= i1; i++) {
        ret.push_back(intervals[i]);
    }
    switch (c) {
        case 0:
            ret.push_back(newInterval);
            break;
        case 1:
            ret.back().end = newInterval.end;
            break;
        case 2:
            ret.emplace(ret.end(), newInterval.start, intervals[i2].end);
            break;
        case 3:
            ret.back().end = intervals[i2].end;
            break;
    }
    for (int i = i2 + 1; i < intervals.size(); i++) {
        ret.push_back(intervals[i]);
    }
    return ret;
}


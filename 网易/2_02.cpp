#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll pos = 1e9 + 7;

int main() {
    ll x;
    unordered_set<ll> st;
    queue<pair<ll, ll>> que;

    cin >> x;
    st.insert(x);
    que.push(make_pair(x, 0));
    while (!que.empty()) {
        pair<ll, ll> top = que.front();
        que.pop();
        if (top.second > 100000)
            break;
        if (top.first % pos == 0) {
            cout << top.second << endl;
            return 0;
        }
        ll x = (top.first * 4 + 3) % pos;
        if (st.find(x) == st.end()) {
            st.insert(x);
            que.push(make_pair(x, top.second + 1));
        }
        x = (top.first * 8 + 7) % pos;
        if (st.find(x) == st.end()) {
            st.insert(x);
            que.push(make_pair(x, top.second + 1));
        }
    }
    cout << -1 << endl;
    return 0;
}

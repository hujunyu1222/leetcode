#include <iostream>
#include <vector>


using namespace std;


int main(){

    //freopen("3.txt", "r", stdin);

    long long N, tmp;
    long long res = 1;
    long long modN = 1e9 + 7;

    cin >> N;

    vector<long long> vis(N, 0);
    vector<long long> high(N, 0);
    vector<long long> reverHigh(N,0);

    cin >> tmp;
    vis[0] = -1;
    high[0] = tmp;


    //maxH = tmp;

    for (long long i = 1; i < N; i++){
        cin >> tmp;
        if (tmp > high[i - 1]){
            vis[i] = -1;
            high[i] = tmp;
        }
        else{
            vis[i] = tmp;
            high[i] = high[i - 1];
        }

    }

    for (long long i = 0; i < N; i++){
        cin >> tmp;
        reverHigh[i] = tmp;
    }

    if (N == 1 && reverHigh[N - 1] != high[N - 1]){
        cout << "0" << endl;
        return 0;
    }




    if (reverHigh[N - 1] > high[N - 1]){
        cout << "0" << endl;
        return 0;
    }
    else{
        if (vis[N - 1] != -1){
            vis[N - 1] = -1;
        }

    }

    for (long long j = N - 2; j >= 0; j--){


        if (reverHigh[j] > reverHigh[j+1]){
            if (reverHigh[j] > high[j]){
                cout << "0" << endl;
                return 0;
            }
            vis[j] = -1;
        }
        else{
            if (vis[j] != -1){
                vis[j] = min(reverHigh[j], vis[j]);
            }
        }

    }
    /*
    for (auto x : vis){
        cout << x << endl;
    }
    */

    for (long long i = 1; i < N; i++){
        if (vis[i] != -1){
            res = (res * vis[i]) % modN;
        }
    }

    cout << res << endl;


    return 0;
}


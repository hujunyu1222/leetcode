#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;



void Drop(vector<vector<char>> &mp){
    queue<char> col;
    int i,j;
    int n = mp.size();
    for (j = 0; j < n; j++){
        for (i = n - 1; i >= 0; i--){
            if (mp[i][j] != '.'){
                col.push(mp[i][j]);
                mp[i][j] = '.';
            }
        }
        i = n - 1;
        while(!col.empty()){
            mp[i--][j] = col.front();
            col.pop();
        }
    }

}

bool DFS(int i, int j, char c, int num, int k, int N, int ori, vector<vector<char>> &mp){
    if (j < 0 || i >= N || j >= N) return false;
    if (mp[i][j] == c){
        num++;
        if (num == k) return true;
        //mp[i][j] = '.';
        if (ori > 1){
            if (DFS(i, j+1, c, num, k, N, ori, mp)) return true;
            else return false;
        }
        else{
            if (DFS(i+1, j+ori, c, num, k, N, ori, mp)) return true;
            else return false;
        }

    }
    else{
        return false;
    }
}

void Print(vector<vector<char>> &mp){
    cout << "=================="<<endl;
    for (int i = 0; i < mp.size(); i++){
        for (int j = 0; j < mp[0].size(); j++){
            cout << mp[i][j];
        }
        cout << endl;
    }
    cout << "=================="<<endl;

}

int main(){
    int T,N,K;
    int caseNum = 1;
    ifstream infile;
    //ofstream oufile;
    vector<vector<char> > mp;

    freopen("A-large-practice.in", "r", stdin);
    freopen("2010_1A_large_out.txt", "w", stdout);
    //outfile.open("2010_1A_out.txt");
    cin >> T;

    while (T--) {
        string s;
        string res = "";
        int line;
        int i, j, k;

        cin >> N >> K;
        mp.resize(0);
        mp = vector<vector<char> >(N,vector<char>(N,'.'));
        j = N - 1;
        //cout << "start!" << endl;
        for(line = 1; line <= N; line++){
            //getline(cin, s);
            cin >> s;
            //cout << s << endl;
            i = 0;

            for (int k = 0; k < N; k++,i++){
                mp[i][j] = s[k];
            }
            j--;
        }

        //Print(mp);
        Drop(mp);
        //Print(mp);
        bool rf, bf;
        rf = bf = false;

        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                if (mp[i][j] == 'R' && !rf){
                    if(DFS(i, j, 'R', 0, K, N, 0, mp) ||
                       DFS(i, j, 'R', 0, K, N, -1, mp) ||
                       DFS(i, j, 'R', 0, K, N, 1, mp) ||
                       DFS(i, j, 'R', 0, K, N, 2, mp)){
                       rf = true;
                    }
                }
                else if (mp[i][j] == 'B' && !bf){
                    if(DFS(i, j, 'B', 0, K, N, 0, mp) ||
                       DFS(i, j, 'B', 0, K, N, -1, mp) ||
                       DFS(i, j, 'B', 0, K, N, 1, mp) ||
                       DFS(i, j, 'B', 0, K, N, 2, mp)){
                       bf = true;
                    }
                }
            }
        }
        printf("Case #%d: ", caseNum++);
        if (rf && bf) cout << "Both" << endl;
        else if (rf) cout << "Red" << endl;
        else if (bf) cout << "Blue" << endl;
        else cout << "Neither" << endl;

    }

    return 0;
}

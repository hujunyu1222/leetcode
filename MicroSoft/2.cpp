
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

#define EQUALS(a,b) (((a-b)<=1E-6)&&((a-b)>-1E-6))
#define MIN(a,b) (a>b?b:a)

#define ALLOW   1
#define DENY    0

#define DEBUG(X) cout<<#X<<"="<<X<<endl;

//first mask bits
unsigned toInt(unsigned com[4]) {
    return (com[0]<<24) + (com[1]<<16) + (com[2]<<8) + com[3];
}

bool matchWith(long long comInt, unsigned addInt, unsigned mask) {
    return comInt>>(32-mask) == addInt>>(32-mask);
}

// 32 24 16 8 0
bool judge(unsigned come, unsigned rule[][3], const unsigned NN) {
    for(unsigned i=0; i<NN; ++i) {
        if(matchWith(come, rule[i][0], rule[i][1])) {
            cout <<"matched with "<<rule[i][0]<<endl;
            return rule[i][2];
        }
    }
    return true;
}

void printRules(unsigned rule[][3], unsigned NN) {
    cout <<"---------------"<<endl;
    for(unsigned i=0; i<NN; ++i) {
        for(unsigned j=0; j<3; ++j) {
            cout <<rule[i][j]<<'\t';
        }
        cout <<endl;
    }
    cout <<"---------------"<<endl;
}

// /*
int main() {
    unsigned N, M;
    cin >>N>>M;
    unsigned const NN = N;

    unsigned rule[NN][3];

    unsigned add[4], mask;
    unsigned come[4];
    char cc;

    for(unsigned i=0; i<NN; ++i) {
        string cmd;
        cin >>cmd;
        scanf("%d.%d.%d.%d", add, add+1, add+2, add+3);
        cc=getchar();
        if(cc=='/') {
            cin>>mask;
        } else {
            mask = 32;
        }
        rule[i][0] = toInt(add);
        rule[i][1] = mask;
        if(cmd=="allow") {
            rule[i][2] = ALLOW;
        }
        else if(cmd=="deny") {
            rule[i][2] = DENY;
        }
    }

    printRules(rule, NN);

    while(M--) {
        scanf("%d.%d.%d.%d", add, add+1, add+2, add+3);
        unsigned come = toInt(add);
        DEBUG(come);
        if(judge(come, rule, NN)) {
            cout <<"YES"<<endl;
        } else {
            cout <<"NO"<<endl;
        }
    }
    return 0;
}
// */

/*
int main() {
    cout <<matchWith(3683530084, 0, 0)<<endl;
}
// */

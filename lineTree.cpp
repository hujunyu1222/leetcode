/*
线段树：
    建立
    更新
    查询
*/
/*test data
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5

*/
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const int MAXNODE = 524288; // 1<<19
const int MAXST = 200001;

struct STU {
    int grade;
    int left, right;
}st[MAXNODE];

int nodeIndex[MAXST];

void BuildTree (int index, int left, int right){
    st[index].grade = 0;
    st[index].left = left;
    st[index].right = right;

    if (left == right){
        nodeIndex[left] = index;
        return;
    }

    //二分建立
    //使用floor（）取整函数
    BuildTree((index<<1), left, (left + right) / 2.0);
    BuildTree((index<<1)+1, (left + right) / 2.0+1, right);

}

void UpdateTree(int index){
    if (index == 1){
        return;
    }
    int f = index / 2;
    int a = st[index].grade;
    int b = st[f].grade;

    st[f].grade = a > b ? a : b;

    UpdateTree(f);
}

int Max = -1;
void Query(int index, int left, int right){
    if (left == st[index].left && right == st[index].right){
        Max = (st[index].grade > Max ? st[index].grade : Max);
        return;
    }
    //对于左节点
    index = index << 1;
    if (left <= st[index].right){
        if(right <= st[index].right){
            Query(index, left, right);
        }
        else{
            Query(index, left, st[index].right);
        }
    }
    //对于右节点
    index = index + 1;
    if (right >= st[index].left){
        if (left < st[index].left){
            Query(index, st[index].left, right);
        }
        else{
            Query(index, left, right);
        }
    }

}

int main()
{
//  freopen("in.txt","r",stdin);
    int n_s,n_q,igrade;
    while(scanf("%d %d",&n_s,&n_q) != EOF){
        BuildTree(1, 1, n_s);
        for (int i= 1 ; i <= n_s; i++){
            scanf("%d",&igrade);
            st[nodeIndex[i]].grade = igrade; // 底层的无条件更新成绩
            UpdateTree(nodeIndex[i]);
        }
        while(n_q--){
            char o[3];int a,b;
            scanf("%s %d %d",o,&a,&b);
            if ( o[0] == 'Q'){
                Max = 0;
                Query(1, a, b);
                printf("%d\n",Max);
            }else{
                st[nodeIndex[a]].grade = b; // 底层的无条件更新成绩
                UpdateTree(nodeIndex[a]);
            }
        }
    }
    return 0;
}

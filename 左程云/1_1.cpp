#include <iostream>
#include <stack>

using namespace std;

//´øgetMinµÄÕ»
template<class T>
class minStack{
private:
    stack<T> stackData;
    stack<T> stackMin;

public:
    void push(T a){
        if (stackData.empty()){
            stackData.push(a);
            stackMin.push(a);
        }
        else if (a <= stackMin.top()){
            stackData.push(a);
            stackMin.push(a);
        }
        else{
            stackData.push(a);
            stackMin.push(stackMin.top());
        }
    }

    void pop(){
        if (stackData.empty()){
            cout << "stack is empty!\n";
            return;
        }
        else {
            stackData.pop();
            stackMin.pop();
        }
    }

    T getMin(){
        if (stackMin.empty()){
            cout << "stack is empty!\n";
            return 0;
        }
        else{
            return stackMin.top();
        }
    }

};

int main(){
    minStack<int> ms;
    int a[6] = {3,4,5,1,2,1};
    for(int i = 0; i < 6; i++){
        ms.push(a[i]);
    }

    cout << ms.getMin() << endl;
    ms.pop();ms.pop();ms.pop();
    cout << ms.getMin() << endl;

    return 0;

}

#include <iostream>
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include <windows.h>

using namespace std;

class Singleton{
private:
    static Singleton* m_pInstance;
    Singleton(){}

public:
    static Singleton* getInstance(){
        if (m_pInstance == NULL){
            m_pInstance = new Singleton();
        }
        
        return m_pInstance;
    }

    void show(){
        cout << "Singleton Pattern" << endl; 
    }
};

//一定要初始化
Singleton* Singleton::m_pInstance = NULL;






int main(){
   

    system("pause");
    return 0;
}
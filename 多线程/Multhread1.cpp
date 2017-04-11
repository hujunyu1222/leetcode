#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
#include <sstream>

using namespace std;


int tickets = 100;
HANDLE hMutex;


DWORD WINAPI Fun1Proc(LPVOID lpParameter)
{
    char *name = (char*)lpParameter;

    cout << "Thread 1 for " << name << endl;

    while (true)
    {
        WaitForSingleObject(hMutex, INFINITE);
        //if (tickets > 0)
        //{
            Sleep(10);
            //cout << "Thread 1 sell ticket : "<<tickets--<<endl;
        //}
        //else
        //    break;
        ReleaseMutex(hMutex);
    }
    return 0;
}

DWORD WINAPI Fun2Proc(LPVOID lpParameter)
{
    char *name = (char*)lpParameter;

    cout << "Thread 2 for " << name << endl;

    while (true)
    {
            WaitForSingleObject(hMutex, INFINITE);
            if (tickets > 0)
            {
                Sleep(10);
                 cout << "Thread 2 sell ticket : "<<tickets--<<endl;
                 }
            else
                 break;
            ReleaseMutex(hMutex);
    }
    return 0;
}




int main(){


    hMutex = CreateMutex(NULL, FALSE, NULL);

    cout << "hMutex is " << (int)hMutex << endl;

    int startNum = 0;
    string strNum;
    stringstream ss;
    cout << "Input file start number：" << endl;
    cin >> startNum;
    ss << startNum;
    ss >> strNum;
    strNum += ".dat";
    char name1[100];
    strcpy(name1,strNum.c_str());

    cout << name1 << endl;

    HANDLE hThread_1 = CreateThread(NULL, 0, Fun1Proc, (LPVOID)name1, 0, NULL);
    //HANDLE hThread_2 = CreateThread(NULL, 0, Fun2Proc, name2, 0, NULL);
    char c;
    while( (c = getchar())){
        switch(c){
            case 'n':
                TerminateThread(hThread_1, 0);
                ++startNum;
                ss.clear();
                ss << startNum;
                ss >> strNum;
                strNum += ".dat";
                strcpy(name1,strNum.c_str());
                cout << name1 << endl;
                hThread_1 = CreateThread(NULL, 0, Fun1Proc, (LPVOID)name1, 0, NULL);
                break;
            case 'e':
                TerminateThread(hThread_1, 0);
                return 0;
            default:
                break;
        }
        
        //TerminateThread(hThread_1, 0);
    }
    CloseHandle(hThread_1);
    //CloseHandle(hThread_2);

    system("pause");
    return 0;
}



#include <bits/stdc++.h>
#include "MyH.h"
//#include <D:\\Projects\\SiAOD\\pr2\\MyLib.h>
#define PATH "D:\\Projects\\SiAOD\\SiAOD2\\pr2\\"+name+".txt"

using namespace std;

int main() {
    while (true) {
        cout << "\nSelect task (1-2): ";
        string fileName, newFileName;
        int select1; cin >> select1;
        switch (select1) {
            case 1 : {
                cout<<"\nEnter file name: ";
                string name;
                cin.ignore();
                getline(cin, name);
                cout << "\nEnter size of file: ";
                int size;
                cin >> size;
                fillFile(name, size);
                fibbonaci(name);
                break;
            }
            case 2 : {

                break;
            }
            default: {
                cout << "\nWrong input\n";
                break;
            }
        }
    }
}
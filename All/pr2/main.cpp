#include <bits/stdc++.h>
#include "MyH.h"
//#include <D:\\Projects\\SiAOD\\pr2\\MyLib.h>
#define PATH "D:\\Projects\\SiAOD\\All\\pr2\\"+name+".txt"

using namespace std;

int main() {
    srand(time(NULL));
    while (true) {
        cout << "\nSelect task (1-6): ";
        string fileName, newFileName;
        int select1; cin >> select1;
        switch (select1) {
            case 1 : {
                cout<<"\nEnter file name: ";
                string name;
                cin.ignore();
                getline(cin, name);
                cout << "\nEnter size of file:";
                int size;
                cin >> size;
                fillFile1(name, size);
                fibbonaci(name);
                break;
            }
            case 2 : {
                cout << "\nEnter text file name: ";
                string txtName;
                cin.ignore();
                getline(cin, txtName);
                cout << "\nEnter size of file: ";
                int size;
                cin >> size;
                cout << "\nEnter binary file name: ";
                string binName;
                cin.ignore();
                getline(cin, binName);
                cout << "\nEnter second text file name: ";
                string txtName2;
                getline(cin, txtName2);
                fillFile(txtName, size);
                printF(txtName);
                cout << "\n~~~~~~~~~~~~~~~~~~~~~\n";
                textToBin(txtName, binName);
                binToText(txtName2, binName);
                printF(txtName2);
                break;
            }
            case 3 : {
                cout << "\nEnter text file name: ";
                string txtName;
                cin.ignore();
                getline(cin, txtName);
                cout << "\nEnter size of file: ";
                int size;
                cin >> size;
                fillFile(txtName, size);
                printF(txtName);
                textToBin(txtName, "bin3");
                cout << "\nEnter index: ";
                int ind; cin >> ind;
                cout << "\n~~~~~~~~~~~~~~~~~~~~~\n";
                getRecord("bin3", ind);
                break;
            }
            case 4 : {
                cout << "\nEnter text file name: ";
                string txtName;
                cin.ignore();
                getline(cin, txtName);
                cout << "\nEnter size of file: ";
                int size;
                cin >> size;
                fillFile(txtName, size);
                printF(txtName);
                textToBin(txtName, "bin3");
                cout << "\nEnter index: ";
                int ind; cin >> ind;
                cout << "\n~~~~~~~~~~~~~~~~~~~~~\n";
                deleteRecord("bin3", ind);
                binToText(txtName, "bin3");
                printF(txtName);
                break;
            }
            case 5 : {
                cout << "\nEnter text file name: ";
                string txtName;
                cin.ignore();
                getline(cin, txtName);
                cout << "\nEnter size of file: ";
                int size;
                cin >> size;
                fillFile(txtName, size);
                printF(txtName);
                textToBin(txtName, "bin3");
                cout << "\nEnter index: ";
                int ind; cin >> ind;
                cout << "\n~~~~~~~~~~~~~~~~~~~~~\n";
                replaceForm("bin3", ind);
                binToText(txtName, "bin3");
                printF(txtName);
                break;
            }
            case 6 : {
                cout << "\nEnter text file name: ";
                string txtName;
                cin.ignore();
                getline(cin, txtName);
                cout << "\nEnter size of file: ";
                int size;
                cin >> size;
                fillFile(txtName, size);
                printF(txtName);
                textToBin(txtName, "bin3");
                cout << "\nEnter type (0-1) ";
                int ind; cin >> ind;
                cout << "\n~~~~~~~~~~~~~~~~~~~~~\n";
                filterByForm("bin3", ind);
                break;
            }
            default: {
                cout << "\nWrong input\n";
                break;
            }
        }
    }
}
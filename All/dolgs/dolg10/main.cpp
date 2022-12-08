#include <bits/stdc++.h>
#include "MyH.h"

using namespace std;

int main() {
    while (1) {
        cout << "\nSelect task (1-2)\n";
        int select1; cin >> select1;
        switch (select1) {
            case 1 : {
                string str, substr;
                cout << "Enter text:\n";
                getline(cin, str);
                cout << "Enter patient:\n";
                cin >> substr;
                auto s = chrono::high_resolution_clock::now();
                cout << "Number of times:\n" << KMP_search(str, substr);
                auto e = chrono::high_resolution_clock::now();
                chrono::duration<float> duration = e - s;
                cout << "\nTime: " << duration.count() << "\n"
                     << "Comparisons: " << cmp << "\n";
                break;
            }
            case 2 : {
                string str; cin.ignore();
                getline(std::cin, str);
                color_check(str);
                break;
            }
        }
    }
}
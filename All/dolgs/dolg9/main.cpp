#include <bits/stdc++.h>
#include <chrono>
#include "MyH.h"

using namespace std;

int main() {

    srand(time(NULL));

    while (1) {
        cout << "\nSelect search algorythm : ";
        int select2; cin >> select2;
        switch (select2) {
            case 1 : {
                long long int size;
                cout << "\nEnter table size : ";
                cin >> size;
                long long int key = 0;
                thing *table = new thing[size];

                cout << "\nSelect case: 1 - rand, 2 - best, 3 - worst\n";
                int select1;
                cin >> select1;
                switch (select1) {
                    case 1 : {
                        fillR(table, size);
                        key = (rand() % 10 + 1) * pow(10, rand() % 16 + 1);
                        break;
                    }
                    case 2 : {
                        fillR(table, size);
                        key = table[0].Code;
                        break;
                    }
                    case 3 : {
                        fillR(table, size);
                        key = table[size - 1].Code;
                        break;
                    }
                }
                auto s = std::chrono::high_resolution_clock::now();
                int num = find(table, size, key);
                auto e = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = e - s;
                cout << "\nTime = " << elapsed.count() << "\n";
                cout << "\nComps = " << cmp << endl;
                delete[] table;
                break;
            }
            case 2 : {
                long long int size;
                cout << "\nEnter table size : ";
                cin >> size;
                long long int key = 0;
                thing *table = new thing[size];

                cout << "\nSelect case: 1 - rand, 2 - best, 3 - worst\n";
                int select1;
                cin >> select1;
                switch (select1) {
                    case 1 : {
                        fillR(table, size);
                        key = (rand() % 10 + 1) * pow(10, rand() % 16 + 1);
                        break;
                    }
                    case 2 : {
                        fillR(table, size);
                        key = table[0].Code;
                        break;
                    }
                    case 3 : {
                        fillR(table, size);
                        key = table[size - 1].Code;
                        break;
                    }
                }
                auto s = std::chrono::high_resolution_clock::now();
                int num = findBarrier(table, size, key);
                auto e = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = e - s;
                cout << "\nTime = " << elapsed.count() << "\n";
                cout << "\nComps = " << cmp << endl;
                delete[] table;
                break;
            }
            case 3 : {
                long long int size;
                cout << "\nEnter table size : ";
                cin >> size;
                long long int key = 0;
                thing *table = new thing[size];

                cout << "\nSelect case: 1 - rand, 2 - best, 3 - worst\n";
                int select1;
                cin >> select1;
                switch (select1) {
                    case 1 : {
                        fillS(table, size);
                        key = (rand() % size) ;
                        break;
                    }
                    case 2 : {
                        fillS(table, size);
                        key = table[0].Code;
                        break;
                    }
                    case 3 : {
                        fillS(table, size);
                        key = table[size/2 + 1].Code;
                        break;
                    }
                }
                auto s = std::chrono::high_resolution_clock::now();
                int num = findBinary(table, size, key);
                auto e = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = e - s;
                cout << "\nTime = " << elapsed.count() << "\n";
                cout << "\nComps = " << cmp << endl;
                delete[] table;
                break;
            }
        }
    }
}
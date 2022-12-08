#include "iostream"
#include <bits/stdc++.h>
#include "MyH.h"

using namespace std;

int main() {

    srand(time(NULL));

    int select1;

    student loh;

    while (1) {
        cout << "\nEnter task num (1-3)\n";
        cin >> select1;
        switch (select1) {
            case 1 : {

                groupS g1;
                cout << "\nEnter amount of students\n";
                int num; cin >> num;
                for(int i = 0; i < num; i++) {
                    fillR(loh);
                    //loh.print();
                    g1.add(loh);
                }
                g1.print();
                g1.selectGoods().print();

                cout << "\nEnter value\n";
                double sr; cin >> sr;

                g1.removeByAvg(sr).print();

                break;
            }
            case 2 : {

                groupD g1;
                cout << "\nEnter amount of students\n";
                int num; cin >> num;
                for(int i = 0; i < num; i++) {
                    fillR(loh);
                    //loh.print();
                    g1.add(loh);
                }
                g1.print();
                g1.selectGoods().print();

                cout << "\nEnter value\n";
                double sr; cin >> sr;

                g1.removeByAvg(sr).print();

                break;

            }
            case 3 : {

                groupV g1;
                cout << "\nEnter amount of students\n";
                int num; cin >> num;
                for(int i = 0; i < num; i++) {
                    fillR(loh);
                    //loh.print();
                    g1.add(loh);
                }
                g1.print();
                g1.selectGoods().print();

                cout << "\nEnter value\n";
                double sr; cin >> sr;

                g1.removeByAvg(sr).print();

                break;

            }
        }
    }
}
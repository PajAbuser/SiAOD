#include "HashTable.h"
using namespace std;

int main() {
    srand(time(NULL));

    HashTable hTable;

    hTable.test();

    /*
    int size;
    cout << "\nEnter size: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        Bank bank;
        bank.code = abs(rand()) % 10000;
        bank.type = rand() % 2;
        for (int j = 0; j < 20; j++) {
            bank.name[j] = rand() % 26 + 65;
        }
        for (int j = 0; j < 30; j++) {
            bank.address[j] = rand() % 26 + 65;
        }
    }
    hTable.print();
    cout << "Ammount of rehashes: " << hTable.ammountOfRehashes << endl;
    cout << "Ammount of collisions: " << hTable.ammountOfCollisions << endl;
    while (1) {
        int code;
        cin >> code;
        cout << "\nResult: ";
        int ind = hTable.find(code);
        cout << ind << endl;
        if(ind != -1) hTable.table[ind].print();
        else cout << "Not found" << endl;
        cout << endl;
    }
    */
}
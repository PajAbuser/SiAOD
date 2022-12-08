#ifndef DOLG9_MYH_H
#define DOLG9_MYH_H

#include <bits/stdc++.h>
#define PHI 0.618

using namespace std;

int cmp;

struct thing {
    
    long long int Code = 0;
    string name;
    string unit;
    int price;

};

void print(thing *table, int size){
    for(int i = 0; i < size; i++){
        cout << setw(20) << table[i].Code << " "
             << setw(5) << table[i].name << " "
             << setw(4) << table[i].unit << " "
             << setw(6) << table[i].price << endl;
    }
}

void fillR(thing *table, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 16; j++){
            table[i].Code = (rand() % 10 + 1) * pow(10, j);
        }
        table[i].name = "product" + to_string(i + 1);
        table[i].unit = "unit" + to_string(i + 1);
        table[i].price = rand() % 1000;
    }

}

int find(thing *table, int size, long long int key){
    cmp = 1;
    for(int i = 0; i < size; i++){
        cmp++;
        if (table[i].Code == key)
            return i;
        cmp++;
    }
    return -1;
}

void fillS(thing *table, int size){
    for(int i = 0; i < size; i++){
        table[i].Code = i;
        table[i].name = "product" + to_string(i + 1);
        table[i].unit = "unit" + to_string(i + 1);
        table[i].price = rand() % 1000;
    }
}

int findBarrier(thing* table, int size, long long int key){
    cmp = 0;
    thing last = table[size - 1];
    table[size - 1].Code = key;
    int i = 0;
    for(i; table[i].Code != key; i++)
        cmp++;
    table[size - 1] = last;
    cmp+=2;
    if ((i != size - 1) || (last.Code == key)) return i;
    else return -1;
}

int findBinary(thing* table, int size, long long int key){
    cmp = 0;
    double pos = 0; double prev = size * (1-PHI);
    while(table[(int)pos].Code != key){
        if(table[(int)pos].Code > key){
            pos *= PHI;
            prev = pos*(1-PHI);
        }
        else {
            pos += prev*(1-PHI);
        }
        cmp+=2;
    }
    return (int)pos;
}

#endif //DOLG9_MYH_H
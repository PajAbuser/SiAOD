#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Item{
    int key = 0;
    int offset = 1;
    bool deleted = false;
    bool empty = false;
    Item(int key){
        this->key = key;
    }
};

struct Table{
    int l = 0;
    int r = 0;
    double load = 0.0;
    Item* T;

    Table(Item* oldT, int l, int r){
        this->l = l;
        this->r = r;
        T = new Item[l];
        for(int i = 0; i < l;i++){
            T[i] = oldT[i];
        }
        this->load = (float)r / (float)l;
    }

};

int hesh(int n, int l){
    return n % l;
}

bool insertInTable(Item& item, Table& table){
    if(table.T[item.key].empty) {
        table.T[item.key] = item;
        return true;
    }
    else return false;
}
void solveCollision(Item& item, Table& table){
    if(table.T[item.key].empty) {
        item.key+=item.offset;
        item.key%=table.l;
        solveCollision(item, table);
    }
    else insertInTable(item,table);
}

void createItems(int id, int key, Item* items){
    items[id] = Item(key);
}

int main() {

}
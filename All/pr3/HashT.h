#ifndef PR3_HASHT_H
#define PR3_HASHT_H

#include <bits/stdc++.h>

struct Item{
    Bank bank;
    int key = bank.code;
    long int index = 0;
    int offset = 1;
    bool deleted = false;
    bool empty = false;
    Item() {}
    Item(int key): key(key) {}
};
struct Table{
    int length = 0;
    int nRec = 0;
    double load = 0.0;
    const double criticalLoad = 0.75;
    Item* T = nullptr;
    Table(){}
    int hash(int i, int L){
        char* key = reinterpret_cast<char *>(i);
        int h = 0, a = 127;
        for (; *key != 0; key++) h = (a*h + *key) % L;
        return h;
    }
    void rehash(){
        Item* T1 = new Item[length];
        for(int i = 0; i < length; i++){
            T1[i] = T[i];
        }
        delete[] T;
        T = new Item[length * 2];
        for(int i = 0; i < length; i++){
            T[i] = T1[i];
        }
        delete[] T1;
        length *= 2;
    }
    void add(Item item){
        if(load > criticalLoad) rehash();
        int i = 0, ind = this->hash(item.key,this->length);
        while(!T[ind].empty){
            i++;
        }
        T[ind] = item;
        nRec++;
        load = ((double) nRec) / length;
    }
    void remove(int key){
        int i = 0, ind = this->hash(key,this->length);
        while(!T[ind].empty){
            if(T[ind].key == key){
                T[ind].deleted = true;
                nRec--;
                load = ((double) nRec) / length;
                return;
            }
            i++;
        }
    }
    Item find(int key){
        int i = 0, ind = this->hash(key,this->length);
        while(!T[ind].empty){
            if(T[ind].key == key){
                return T[ind];
            }
            i++;
        }
        return Item();
    }
    void print(){
        for(int i = 0; i < length; i++){
            ::print(T[i].bank);
        }
    }
    
};


void createItems(int id, int key, Item* items){
    items[id] = Item(key);
}

#endif //PR3_HASHT_H
#ifndef PR3_HASHT_H
#define PR3_HASHT_H

#include <bits/stdc++.h>

struct Item{
    Bank bank;
    int key = bank.code;
    long int index = 0;
    bool empty = true;
    Item(){}
    explicit Item(int key): key(key) {}
};
struct Table{
    int length = 0;
    int nRec = 0;
    double load = 0.0;
    const double criticalLoad = 0.75;
    Item* T = new Item[length];
    Table()= default;
    int hash(int i) const{
        int pos, a = 127;
        pos = (a + i) % length;
        return pos;
    }
    int hash2(int i) const{
        int pos, a = 127;
        pos = (a + i) % length;
        return 1 + pos % length;
    }
    void rehash(){
        int* mas = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int i = 0; i < 10; i++){
            cout << mas[i] << " ";
        }
        int oldLength = length;
        length = 2 * length + 1;
        Item* oldT = T;
        T = new Item[length];
        for(int i = 0 ; i < oldLength ; i++){
            if(!oldT[i].empty){
                add(oldT[i]);
            }
        }
        delete[] oldT;
    }
    void add(Item item){

        if(length != 0) {if(load > criticalLoad) rehash();}
        else {
            length++;
            T[length - 1].empty = true;
        }
        int ind = this->hash(item.key);
        while(!T[ind].empty){
            ind+=this->hash2(item.key);
        }
        T[ind] = item;
        nRec++;
        load = ((double) nRec) / length;
    }
    void remove(int key){
        int i = 0, ind = this->hash(key);
        while(!T[ind].empty){
            if(T[ind].key == key){
                T[ind].empty = true;
                nRec--;
                load = ((double) nRec) / length;
                return;
            }
            i++;
        }
    }
    Item find(int key) const{
        int i = 0, ind = this->hash(key);
        while(!T[ind].empty){
            if(T[ind].key == key){
                return T[ind];
            }
            i++;
        }
        return {};
    }
    void print() const{
        int cnt = 0;
        for (int i = 0; i < length; i++) {
            Item *item = &T[i];
            cout << i << "_" << ++cnt << "\t|" << item->key << "\t" << '\n';
        }
    }


};

void createItems(int id, int key, Item* items){
    items[id] = Item(key);
}

#endif //PR3_HASHT_H
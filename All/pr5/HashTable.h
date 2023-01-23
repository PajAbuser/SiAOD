#include "BinarySearchTree.h"
#include "BinaryFiles.h"
#define PATH "E:\\Projects\\SiAOD\\All\\pr5\\"+name+".txt"

int nextPrime(int i){
    int j;
    for(j = 2; j <= i; j++){
        if(i % j == 0) break;
    }
    if(j == i) return i;
    else return nextPrime(i + 1);
}

struct HashTable{
    struct Record{
        BinarySearchTree::Node* node;
        bool empty = true;
        Record(){};
        void print() {
                cout << "~~~";
                ::print(node->val);
                cout << "\nEmpty: " << empty << endl;
                cout << "~~~" << endl;
        }
    };
    int length = 1;
    int recs = 0;
    double const critical = 0.75;
    int ammountOfRehashes = 0;
    int ammountOfCollisions = 0;
    Record* table = new Record[length];

    HashTable(){};
    int hash(int i) const{
        int ind, a = 127;
        ind = abs((a + i) % length);
        return ind;
    }
    int hash2(int i) const{
        int ind, a = 255;
        ind = abs((a + 3*i) % length);
        return 1 + ind;
    }
    double loadFactor() const{
        return (double (recs))/(double (length));
    }
    void add(Record r){
        if(loadFactor() + 1.f/length > critical){
            rehash();
        }
        int ind = hash(r.node->val.code);
        int prevInd = ind;
        while(!table[ind].empty){
            ammountOfCollisions++;
            ind += hash2(hash(r.node->val.code));
            ind %= length;
            if(ind == prevInd) rehash();
        }
        table[ind] = r;
        recs++;
    }
    void rehash(){
        ammountOfRehashes++;
        int oldLength = length;
        length = nextPrime(length * 2);
        Record* oldTable = table;
        table = new Record[length];
        for(int i = 0; i < length; i++){
            table[i].empty = true;
        }
        for(int i = 0; i < oldLength; i++){
            if(!oldTable[i].empty){
                add(oldTable[i]);
                recs--;
            }
        }
        delete[] oldTable;
        oldTable = nullptr;
    }
    void print(){
        for(int i = 0; i < length; i++){
            cout << "~" << i << "~";
            if(!table[i].empty){
                ::print(table[i].node->val);
            }
            cout << "\n~~~" << endl;
        }
    }
    int find(int code){
        int ind = hash(code);
        int prevInd = ind;
        while(!table[ind].empty){
            if(table[ind].node->val.code == code) return ind;
            ind += hash2(hash(code));
            ind %= length;
            if(ind == prevInd) return -1;
        }
        return -1;
    }
    void remove(int code){
        int ind = find(code);
        if(ind != -1){
            table[ind].empty = true;
            recs--;
        }
    }
};
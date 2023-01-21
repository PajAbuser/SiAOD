#include "BinaryFiles.h"

int nextPrime(int i){
    int j;
    for(j = 2; j <= i; j++){
        if(i % j == 0) break;
    }
    if(j == i) return i;
    else return nextPrime(i + 1);
}
struct Record{
    Bank bank;
    bool empty = true;
    Record(){};
    void print(){
        cout << "~~~";
        ::print(bank);
        cout << "\nEmpty: " << empty << endl;
        cout << "~~~" << endl;
    }
};
struct HashTable{
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
        int ind = hash(r.bank.code);
        int prevInd = ind;
        while(!table[ind].empty){
            ammountOfCollisions++;
            ind += hash2(hash(r.bank.code));
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
                ::print(table[i].bank);
            }
            cout << "\n~~~" << endl;
        }
    }
    int find(int code){
        int ind = hash(code);
        int prevInd = ind;
        while(!table[ind].empty){
            if(table[ind].bank.code == code) return ind;
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
    
    void test(){
        cout << "*******************************************\n";
        cout << "Test on big amount of data\n";
        int size = 1000000;
        fillFile("txt", size);
        cout << "Filling bin file...\n";
        textToBin("txt", "bin");
        cout << "Filling hash table...\n";
        ifstream file;
        Bank bank;
        Record record;
        string name = "bin";
        if(!file.is_open()){
            file.open(PATH, ios::binary | ios::app);
        }
        file.seekg(0, ios::beg);
        while(file.read((char*)&bank, sizeof(bank))){
            record.bank = bank;
            record.empty = false;
            add(record);
            file.get();
        }
        file.close();
        while(1) {
            cout << "Searching...\n";
            auto begin = chrono::high_resolution_clock::now();
            table[find(getRecord("bin", 0).code)].print();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<float> duration = end - begin;
            cout << "Time to find first record: " << duration.count() << "ms\n";
            begin = chrono::high_resolution_clock::now();
            table[find(getRecord("bin", size / 2).code)].print();
            end = chrono::high_resolution_clock::now();
            duration = end - begin;
            cout << "Time to find middle record: " << duration.count() << "ms\n";
            begin = chrono::high_resolution_clock::now();
            table[find(getRecord("bin", size - 1).code)].print();
            end = chrono::high_resolution_clock::now();
            duration = end - begin;
            cout << "Time to find last record: " << duration.count() << "ms\n";
            int i;
            cin >> i;
        }
    }
};
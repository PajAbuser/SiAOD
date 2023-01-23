#include "BinarySearchTree.h"
#include "BinaryFiles.h"
#include "HashTable.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    srand(time(NULL));


    BinarySearchTree *binarySearchTree = new BinarySearchTree();

    while (true) {
        cout << "\n1 - BinarySearchTree\n2 - HashTable\n";
        int choice1 = 0;
        cin >> choice1;
        switch(choice1) {
            case 1: {
                bool exit = false;
                cout << "\nEnter ammount of records: ";
                int size; cin >> size;
                BinarySearchTree::Node* nodes = new BinarySearchTree::Node[size];
                while(!exit){
                    cout << "\n1 - Display BinarySearchTree\n2 - Find/Remove record\n";
                    int choice2 = 0;
                    cin >> choice2;
                    switch (choice2) {
                        case 1: {
                            *&binarySearchTree = new BinarySearchTree();
                            fillFile("txt", size);
                            textToBin("txt", "bin");
                            string name = "bin";
                            ifstream file(PATH, ios::binary);
                            Bank bank{0, "", "", false};
                            int i = 0;
                            file.seekg(0, ios::beg);
                            while (file.read((char *) &bank, sizeof(Bank))) {
                                file.get();
                                nodes[i].val = bank;
                                binarySearchTree->add(&nodes[i]);
                                i++;
                            }
                            cout << endl;
                            binarySearchTree->print();
                            break;
                        }
                        case 2: {
                            for (int i = size - 1; i != -1; i--) {
                                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                cout << "Searching for " << nodes[i].val.code;
                                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                cout << "Path: " << binarySearchTree->find(&nodes[i]);
                                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                cout << "Removing " << nodes[i].val.code;
                                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
                                binarySearchTree->remove(&nodes[i]);
                                binarySearchTree->print();
                            }
                            break;
                        }
                        case 0: {
                            exit = true;
                        }
                    }
                }
                break;
            }
            case 2: {
                HashTable hashTable;
                int size = 1000000;
                BinarySearchTree::Node* nodes = new BinarySearchTree::Node[size];
                fillFile("txt", size);
                textToBin("txt", "bin");
                string name = "bin";
                ifstream file(PATH, ios::binary);
                Bank bank{0, "", "", false};
                int i = 0;
                file.seekg(0, ios::beg);
                while (file.read((char *) &bank, sizeof(Bank))) {
                    file.get();
                    nodes[i].val = bank;
                    HashTable::Record r;
                    r.node = &nodes[i];
                    r.empty = false;
                    hashTable.add(r);
                    i++;
                }
                cout << "Searching...\n";
                auto begin = chrono::high_resolution_clock::now();
                hashTable.table[hashTable.find(getRecord("bin", 0).code)].print();
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<float> duration = end - begin;
                cout << "Time to find first record: " << duration.count() << "ms\n";
                begin = chrono::high_resolution_clock::now();
                hashTable.table[hashTable.find(getRecord("bin", size/2).code)].print();
                end = chrono::high_resolution_clock::now();
                duration = end - begin;
                cout << "Time to find middle record: " << duration.count() << "ms\n";
                begin = chrono::high_resolution_clock::now();
                hashTable.table[hashTable.find(getRecord("bin", size - 1).code)].print();
                end = chrono::high_resolution_clock::now();
                duration = end - begin;
                cout << "Time to find last record: " << duration.count() << "ms\n";
                break;
            }
        }
    }
}
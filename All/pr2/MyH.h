#ifndef PR2_MYH_H
#define PR2_MYH_H

#include <iostream>
#include <bits/stdc++.h>
#define PATH "D:\\Projects\\SiAOD\\All\\pr2\\"+name+".txt"
#define BankSize sizeof(int) + 65*sizeof(char)
#pragma once

using namespace std;

struct Bank {
    char name[20];
    int code;
    char address[30];
    char type[1];
};

string printMas(char* arr, int size){
    string str = "";
    for(int i = 0; i < size; i++){
        str += arr[i];
    }
    return str;
}
void print(Bank bank){
    cout <<
    "\nCode = " << bank.code <<
    "\nName = " << printMas(bank.name, 20) <<
    "\nAddress = " << printMas(bank.address, 30) <<
    "\nType = " << printMas(bank.type,1);
}
void randFill(ofstream& file){
    for(int i = 0; i < rand() % 20; i++){
        file << rand() % 1000 << endl;
    }
}
void printF(ifstream& file) {
    string line; cout << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
}
void fillFile(string name, int size){
    ofstream file(PATH, ios::app);
    for(int i = 0; i < size; i++){
        file << 1;
    }
    file.close();
}
void fibbonaci(string name) {
    ifstream file;
    if(!file.is_open()){
        file.open(PATH, ios::app);
    }
    if(file.good()) {
        string line;
        int prev1 = 1, prev2 = 0, curr = 1;
        while(!file.eof()) {
            int curr = prev1 + prev2;
            for (int i = 1; i < curr; i++) {
                file.get(line,1,' ');
                cout << line;
                cout << endl;
            }
            curr  = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
    }
    file.close();
}
void textToBin(string bFileN, string tFileN) {
    ifstream tFile(tFileN, ios::binary);
    fstream bFile(bFileN, ios::binary);
    if(tFile.good() && bFile.good()) {
        Bank bank;
        while (tFile >> bank.code) {
            tFile.get();
            tFile.getline(bank.name, 20, '\n');
            tFile.get();
            tFile.getline(bank.address, 30, '\n');
            tFile.get();
            tFile.getline(bank.type, 1, '\n');
            tFile.get();
            bFile.write((char *) &bank, sizeof(Bank));
        }
        tFile.close();
        bFile.close();
    }
}
void binToText(string bFileN, string tFileN) {
    ifstream inBinFile(bFileN, ios::binary);
    ofstream outTextFile(tFileN, ios::binary);
    if (inBinFile.good() && outTextFile.good()) {
        Bank bank;
        while (inBinFile.read((char *) &bank, sizeof(Bank))) {
            outTextFile << bank.code << '\n'
                        << bank.name << '\n'
                        << bank.address << '\n'
                        << bank.type << '\n';
        }
    }
}
int printBinFile(string bFileN) {
    fstream inBinFile(bFileN, ios::binary | ios::in);
    if (!inBinFile.good())
        return -1;
    Bank bank;

    while (inBinFile.read((char *) &bank, sizeof(Bank)))
        print(bank);

    inBinFile.close();
    return 0;
}
int getRecordByPosition(string bFileN, int recordPosition, Bank &bank) {
    fstream inBinFile(bFileN, ios::binary | ios::in);
    if (!inBinFile.good())
        return -1;

    int offset = (recordPosition - 1) * sizeof(Bank);
    inBinFile.seekg(offset, ios::beg);
    if (inBinFile.bad())
        return -1;

    inBinFile.read((char *) &bank, sizeof(Bank));
    inBinFile.close();
    return 0;
}
int deleteRecordByID(string bFileN, int key) {
    fstream inOutBinFile(bFileN, ios::binary | ios::in | ios::out);

    inOutBinFile.seekg(-1 * sizeof(Bank), ios::end);
    int sizeToCut = inOutBinFile.tellg();
    inOutBinFile.seekg(ios::beg);

    if (!inOutBinFile.good())
        return -1;
    Bank bank;
    int cnt = 0;

    while (inOutBinFile.read((char *) &bank, sizeof(Bank)) && bank.code != key)
        cnt++;

    while (inOutBinFile.read((char *) &bank, sizeof(Bank))) {
        inOutBinFile.seekg(-2 * sizeof(Bank), ios::cur);
        inOutBinFile.write((char *) &bank, sizeof(Bank));
        inOutBinFile.seekg(sizeof(Bank), ios::cur);
    }

    //filesystem::resize_file(bFileN, sizeToCut);
    inOutBinFile.close();
    return 0;
}
void replaceTypeById(string bFileN, int code) {
    ifstream bFileIn(bFileN, ios::binary);
    if (bFileIn.good()) {
        Bank bank; char state[1] = {}; int id; int c = 0;
        while(bFileIn.read((char *) &bank, sizeof(Bank))) {
            if (bank.code == code) {
                id = c;
                if (bank.type[0] == 1) state[0] = 0;
                else state[0] = 1;
            }
            c++;
        }
        bFileIn.close();
        ofstream bFileOut(bFileN, ios::binary);
    }
}
#endif //PR2_MYH_H
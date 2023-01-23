#ifndef PR3_BINARYFILES_H
#define PR3_BINARYFILES_H

#include <bits/stdc++.h>
#define PATH "E:\\Projects\\SiAOD\\All\\pr5\\"+name+".txt"
#pragma once

using namespace std;

struct Bank {
    int code;
    char name[20];
    char address[30];
    bool type;
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
    "\nType = " << bank.type;
}
void printF(string name) {
    ifstream file(PATH, ios::app);
    string line = "";
    cout << endl;
    file.seekg(0, ios::beg);
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
void fillFile1(string name, int size){
    ofstream file(PATH, ios::trunc);
    for(int i = 0; i < size; i++){
        file << 1;
    }
    file.close();
}
void fillFile(string name, int size){
    ofstream file(PATH, ios::trunc);
    for(int i = 0; i < size; i++){
        if(i != 0) file << '\n';
        int val = rand() % 10000;
        file  << val << '\n' <<
        "Name" + to_string(val) << '\n' <<
        "Address" + to_string(val) << '\n' <<
        val % 2;
    }
    file.close();
}
void fibbonaci(string name) {
    ifstream file;
    if(!file.is_open()){
        file.open(PATH,ios::app);
    }
    if(file.good()) {
        string line;
        int prev1 = 1, prev2 = 0, temp, count = 1;
        while(!file.eof()) {
            int curr = prev1 + prev2;
            cout << count << " " << curr << " ";
            for (int i = 0; i < curr; i++) {
                if(file.eof()) break;
                line = file.get();
                cout << line;
            }
            cout << endl;
            temp = curr;
            prev2 = prev1;
            prev1 = temp;
            count++;
        }
    }
    file.close();
}
void textToBin(string txtName, string binName){
    ifstream txtFile;
    ofstream binFile;
    Bank bank;
    if(!txtFile.is_open()){
        string name = txtName;
        txtFile.open(PATH,ios::app);
    }
    if(!binFile.is_open()){
        string name = binName;
        binFile.open(PATH,ios::binary);
    }
    if(txtFile.good() && binFile.good()){
        string line;
        while(txtFile >> bank.code){
            txtFile.get();
            getline(txtFile, line);
            for(int i = 0; i < line.length(); i++){
                bank.name[i] = line[i];
            }
            for(int i = line.length(); i < 20; i++){
                bank.name[i] = ' ';
            }
            getline(txtFile, line);
            for(int i = 0; i < line.length(); i++){
                bank.address[i] = line[i];
            }
            for(int i = line.length(); i < 30; i++){
                bank.address[i] = ' ';
            }
            txtFile >> bank.type;
            binFile.write((char*)&bank, sizeof(bank));
            binFile << '\n';
        }
    }
    txtFile.close();
    binFile.close();
}
void binToText(string txtName, string binName){
    ifstream binFile;
    ofstream txtFile;
    Bank bank;
    if(!txtFile.is_open()){
        string name = txtName;
        txtFile.open(PATH);
    }
    if(!binFile.is_open()){
        string name = binName;
        binFile.open(PATH, ios::binary | ios::app);
    }
    binFile.seekg(0, ios::beg);
    bool first = true;
    while(binFile.read((char*)&bank, sizeof(bank))){
        if(!first) txtFile << '\n';
        first = false;
        txtFile << bank.code << '\n';
        for(int i = 0; i < 20; i++){
            txtFile << bank.name[i];
        }
        txtFile << '\n';
        for(int i = 0; i < 30; i++){
            txtFile << bank.address[i];
        }
        txtFile << '\n' << bank.type;
        binFile.get();
    }
    txtFile.close();
    binFile.close();
}
Bank getRecord(string name, int index){
    ifstream file;
    Bank bank;
    if(!file.is_open()){
        file.open(PATH, ios::binary | ios::app);
    }
    int count = 0;
    file.seekg(0, ios::beg);
    while(file.read((char*)&bank, sizeof(bank))){
        if(count == index){
            return bank;
        }
        count++;
        file.get();
    }
    file.close();
}
void deleteRecord(string name, int index){
    ifstream file;
    ofstream tempFile;
    Bank bank;
    if(!file.is_open()){
        file.open(PATH, ios::binary | ios::app);
    }
    if(!tempFile.is_open()){
        tempFile.open(PATH + "temp.txt", ios::binary | ios::trunc);
    }
    int count = 0;
    while(file.read((char*)&bank, sizeof(bank))){
        if(count != index){
            tempFile.write((char*)&bank, sizeof(bank));
            tempFile << '\n';
        }
        count++;
        file.get();
    }
    file.close();
    tempFile.close();
    remove((PATH).c_str());
    rename((PATH + "temp.txt").c_str(), (PATH).c_str());
}
void replaceForm(string name, int index) {
    ifstream file;
    ofstream tempFile;
    Bank bank;
    if (!file.is_open()) {
        file.open(PATH, ios::binary | ios::app);
    }
    if (!tempFile.is_open()) {
        tempFile.open(PATH + "temp.txt", ios::binary | ios::trunc);
    }
    int count = 0;
    while (file.read((char *) &bank, sizeof(bank))) {
        if (count == index) {
            if (bank.type == 1) bank.type = 0;
            else bank.type = 1;
        }
        tempFile.write((char *) &bank, sizeof(bank));
        tempFile << '\n';
        count++;
        file.get();
    }
    file.close();
    tempFile.close();
    remove((PATH).c_str());
    rename((PATH + "temp.txt").c_str(), (PATH).c_str());
}
void filterByForm(string name, bool form){
    ifstream file;
    Bank bank;
    if(!file.is_open()){
        file.open(PATH, ios::binary | ios::app);
    }
    while(file.read((char*)&bank, sizeof(bank))){
        if(bank.type == form){
            print(bank);
        }
        file.get();
    }
    file.close();
}

#endif //PR3_BINARYFILES_H
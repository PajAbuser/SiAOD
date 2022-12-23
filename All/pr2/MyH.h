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
        int prev1 = 1, prev2 = 1, curr = 1, temp, count = 1;
        while(!file.eof()) {
            int curr = prev1 + prev2;
            cout << count << " ";
            for (int i = 0; i < curr; i++) {
                if(file.eof()) break;
                line = file.get();
                cout << line;
            }
            cout << endl;
            temp = curr;
            curr = prev1 + prev2;
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
    if(!txtFile.is_open()){
        string name = txtName;
        txtFile.open(PATH, ios::app);
    }
    if(!binFile.is_open()){
        string name = binName;
        binFile.open(PATH, ios::app);
    }
    if(txtFile.good() && binFile.good()){
        string line;
        while(!txtFile.eof()){
            getline(txtFile, line);
            binFile << line;
        }
    }
    txtFile.close();
    binFile.close();
}

#endif //PR2_MYH_H
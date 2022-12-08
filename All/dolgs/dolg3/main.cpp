#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printNullString(char* ns, int size){
    for(int i = 0; i < size; i++){
        cout << ns[i];
    }
}

int nullTermString(char* s){
    int len;
    cout << "\nEnter line length\n";
    cin >> len;
    cin.ignore();
    cin.getline(s,len+1,'\n');
    return len;
}

int enterString(string &s){

    cout << "\nEnter string\n";
    cin.ignore();
    getline(cin,s);
    cout << s;
    return s.length();

}

void printMat(char** mas, int rows) {

    for (int i = 0; i < rows; i++) {

        cout << "\"";

        int j = 0;
        while(mas[i][j] != '\0'){

            cout << mas[i][j];
            j++;

        }

        cout  << "\"" <<  endl;

    }
}

void printMat(string* mas, int rows) {

    for (int i = 0; i < rows; i++) {

        cout << "\"";

        cout << mas[i];

        cout  << "\"" <<  endl;

    }
}

void printMas(char* s, int size){

    int i = 0;
    while(s[i] != '\0'){
        cout << s[i];
        i++;
    }

}

int findChar(char* mas, int size, char* s){
    
    for(int i = 0;i<size;i++){

        if(strstr(mas,s) == nullptr) return i;

    }
    return -1;
    
}

void fillMas(char* mas, int size, char s){

    int i = 0;
    while(i < size){

        mas[i] = s;
        i++;

    }
    mas[i] = '\0';

}

void findLongest(char** words,int wc,int size){

    char* symbs = new char[size];

    int max = -1, prevmax, ind = 0;
    for(int i = 0; i < wc; i++) {
        int j = 0, lc = 0;

        fillMas(symbs,size,'0');

        while (words[i][j] != '\0') {

            if(findChar(symbs, size, &words[i][j])!= -1){

                symbs[j] = words[i][j];
                lc++;

            }
            else {
                max = prevmax;
                break;
            }

            /*printMas(symbs,size);
            cout  << endl;*/

            if(lc > max) {
                prevmax = max;
                max = lc;
                ind = i;
            }

            j++;
        }

    }
    cout << "\nLongest word = " << words[ind];
}

void findLongest(string* words,int wc,int size){

    char* symbs = new char[size];

    int max = -1, prevmax, ind = 0;
    for(int i = 0; i < wc; i++) {
        int j = 0, lc = 0;

        fillMas(symbs,size,'0');

        while (words[i][j] != '\0') {

            if(findChar(symbs, size, &words[i][j])!= -1){

                symbs[j] = words[i][j];
                lc++;

            }
            else {
                max = prevmax;
                break;
            }

            /*printMas(symbs,size);
            cout  << endl;*/

            if(lc > max) {
                prevmax = max;
                max = lc;
                ind = i;
            }

            j++;
        }

    }
    cout << "\nLongest word = " << words[ind];
}

void task1(){

    char s[256];
    int size = nullTermString(s);
    printNullString(s,size);
    cout << endl;

    char* word = new char[size];
    char** words = new char*[size];
    for (int n = 0; n < size; n++) {
        //words[n] = (char*) malloc(sizeof(char*)*size);
        words[n] =  new char[size];
    }

    int wc = 0;

    for(int i = 0; i < size; i++){

        int j = 0;

        while(s[i] != ' ' and s[i] != '\0'){
            word[j] = s[i];
            j++; i++;
        }

        word[j] = '\0';

        //eqMatMas(words, wc, word);
        strcpy(words[wc],word);

        wc++;
        
    }

    printMat(words,wc);

    findLongest(words,wc,size);

}

void task2(){

    string s;
    int size = enterString(s);

    string* words = new string[size];

    int wc = 0;

    string word = "";

    int i = 0;

    cout << endl;

    while(i < size) {
        while (s[i] != ' ' & i < size) {
            word += s[i];
            i++;
        }
        words[wc] = word;
        word = "";
        //cout << words[wc] << endl;
        i++; wc++;
    }

    printMat(words, wc);

    findLongest(words,wc,size);

}

int main() {
    while (true) {
        int select1;
        cout << "\nEnter string type: "
                "1 - null string, "
                "2 - std::string\n";
        cin >> select1;
        switch (select1) {
            case 1: {
                task1();
                break;
            }
            case 2: {
                task2();
                break;
            }
            default:{
                break;
            }
        }
    }
}
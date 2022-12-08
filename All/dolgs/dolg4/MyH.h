#ifndef DOLG4_MYH_H
#define DOLG4_MYH_H
#include "iostream"
#include <bits/stdc++.h>

#include <utility>

using namespace std;


const int stringSize = 5;
string disciplines[5] = {
        "Subject 0",
        "Subject 1",
        "Subject 2",
        "Subject 3",
        "Subject 4"
};

struct student {

    int number;
    string fio;
    char group_number[10];
    int grades[5];

    void print(){
        cout << "num = " << setw(5) << to_string(number);
        cout << " fio = " << setw(5) << fio;
        cout << " grades = ";
        for(int i = 0; i < 5; i++){
            cout << to_string(grades[i]) << ", ";
        }
        cout << " gnum = " << setw(5) << group_number << endl;
    }

};

struct groupS {
    int n = 0;
    static const int N = 100;
    student studs[N];

    void print(){
        cout << "groupS {\n";
        for(int i = 0; i < this->n; i++){
            cout  << "id = " << setw(3) << i << " ";
            studs[i].print();
        }
        cout << "}\n";
    }

    void add(student &s){
        n++;
        studs[n-1] = s;
    }

    void add(groupS g){
        for(int i = 0; i < g.n; i++) {
            n++;
            studs[n - 1] = g.studs[i];
        }
    }

    void remove(student s){
        for(int i = 0; i < n; i++){
            if(studs[i].number == s.number){
                for(int j = i; j < n - 1; j++){
                    studs[j] = studs[j+1];
                }
                n--;
            }
        }
    }

    double calcMed(student s){
        double avg = 0;
        for(int j = 0; j < 5; j++){
            avg += ((double) s.grades[j])/5;
        }
        return avg;
    }

    groupS selectGoods(){
        groupS g1,g2;
        for(int i = 0; i < n; i++){
            student s = this->studs[i];
            double avg = calcMed(s);
            if(avg > 4) {
                g1.add(s);
            }
        }
        student latest;
        while(g1.n > 0) {
            //g1.print();
            //cout << g1.n << endl;
            double max = -1;
            for (int i = 0; i < g1.n; i++) {
                student s = g1.studs[i];
                double avg = calcMed(s);
                if (avg >= max) {
                    max = avg;
                    latest = g1.studs[i];
                    //cout << avg << endl;
                }
            }
            g2.add(latest);
            g1.remove(latest);
        }
        return g2;
    }

    groupS removeByAvg(double ravg){

        groupS temp = *this;
        for(int i = 0; i < temp.n;){
            student s = temp.studs[i];
            if(calcMed(s) < ravg) temp.remove(s);
            else i++;
        }
        return temp;
    }

};

bool operator== (const student& s1, const student& s2){
    if(s1.number == s2.number) return true;
    return false;
}

struct groupD {
    int n = 0;
    int const N = 100;
    student* studs = new student[N];

    void remove(int pos){
        student* temp = new student[n-1];
        int d = 0;
        for(int i = 0; i < n; i++){
            if(i == pos) { i++; d = 1; }
            temp[i-d] = studs[i];
        }
        delete[] studs;
        this->studs = new student[n-1];
        this->n--;
        for(int i = 0; i < n; i++){
            studs[i] = temp[i];
        }
        delete[] temp;
    }

    void remove(student s){
        for(int i = 0; i < n; i++){
            if(studs[i].number == s.number){
                for(int j = i; j < n - 1; j++){
                    studs[j] = studs[j+1];
                }
                n--;
            }
        }
    }

    void expand(){
        student* temp = new student[n+1];
        for(int i = 0; i < n; i++){
            temp[i] = this->studs[i];
        }
        this->n++;
        delete[] this->studs;
        this->studs = temp;
        delete[] temp;
    }

    void print(){
        cout << "group {\n";
        for(int i = 0; i < this->n; i++){
            cout  << "id = " << setw(3) << i << " ";
            studs[i].print();
        }
        cout << "}\n";
    }

    void add(student s){
        //expand();
        n++;
        studs[n-1] = s;
    }

    void add(groupD g){
        for(int i = 0; i < g.n; i++) {
            n++;
            studs[n - 1] = g.studs[i];
        }
    }

    double calcMed(student s){
        double avg = 0;
        for(int j = 0; j < 5; j++){
            avg += ((double) s.grades[j])/5;
        }
        return avg;
    }

    groupD selectGoods(){
        groupD g1,g2;
        for(int i = 0; i < n; i++){
            student s = this->studs[i];
            double avg = calcMed(s);
            if(avg > 4) {
                g1.add(s);
            }
        }
        student latest;
        while(g1.n > 0) {
            //g1.print();
            //cout << g1.n << endl;
            double max = -1;
            for (int i = 0; i < g1.n; i++) {
                student s = g1.studs[i];
                double avg = calcMed(s);
                if (avg >= max) {
                    max = avg;
                    latest = g1.studs[i];
                    //cout << avg << endl;
                }
            }
            g2.add(latest);
            g1.remove(latest);
        }
        return g2;
    }

    groupD removeByAvg(double ravg){

        groupD temp = *this;
        for(int i = 0; i < temp.n;){
            student s = temp.studs[i];
            if(calcMed(s) < ravg) temp.remove(s);
            else i++;
        }
        return temp;
    }

};

struct groupV {

    int n = 0;
    vector<student> studs;

    void print(){
        cout << "groupS {\n";
        for(int i = 0; i < this->n; i++){
            cout  << "id = " << setw(3) << i << " ";
            studs[i].print();
        }
        cout << "}\n";
    }

    void add(student &s){
        n++;
        studs.push_back(s);
    }

    void add(groupV g){
        for(int i = 0; i < g.n; i++) {
            n++;
            studs[n - 1] = g.studs[i];
        }
    }

    void remove(student s){
        for(int i = 0; i < n; i++){
            if(studs[i].number == s.number){
                for(int j = i; j < n - 1; j++){
                    studs[j] = studs[j+1];
                }
                n--;
            }
        }
    }

    double calcMed(student s){
        double avg = 0;
        for(int j = 0; j < 5; j++){
            avg += ((double) s.grades[j])/5;
        }
        return avg;
    }

    groupV selectGoods(){
        groupV g1,g2;
        for(int i = 0; i < n; i++){
            student s = this->studs[i];
            double avg = calcMed(s);
            if(avg > 4) {
                g1.add(s);
            }
        }
        student latest;
        while(g1.n > 0) {
            //g1.print();
            //cout << g1.n << endl;
            double max = -1;
            for (int i = 0; i < g1.n; i++) {
                student s = g1.studs[i];
                double avg = calcMed(s);
                if (avg >= max) {
                    max = avg;
                    latest = g1.studs[i];
                    //cout << avg << endl;
                }
            }
            g2.add(latest);
            g1.remove(latest);
        }
        return g2;
    }

    groupV removeByAvg(double ravg){

        groupV temp = *this;
        for(int i = 0; i < temp.n;){
            student s = temp.studs[i];
            if(calcMed(s) < ravg) temp.remove(s);
            else i++;
        }
        return temp;
    }

};

void fill(student &s){

    int num; string fio;
    cout << "\nEnter students num, fio, grades (5), group number (10)\n";
    cin >> num;
    cin.ignore();
    getline(cin,fio);
    s.number = num;
    s.fio = fio;
    int g;
    for(int i = 0; i < 5; i++){
        cin >> g;
        s.grades[i] = g;
    }
    cin.ignore();
    string gnum; getline(cin,gnum);
    int size = gnum.length();
    for(int i = 0; i < size; i++){
        s.group_number[i] = gnum[i];
    }

}

void fillR(student &s){

    s.number = rand()%10000;
    s.fio = to_string(rand());
    for(int i = 0; i < 5; i++){
        s.grades[i] = rand() % 5 + 1;
    }
    string gnum = to_string(rand());
    int size = gnum.length();
    for(int i = 0; i < size; i++){
        s.group_number[i] = gnum[i];
    }

}

#endif //DOLG4_MYH_H

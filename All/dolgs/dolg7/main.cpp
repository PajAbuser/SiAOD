#include <bits/stdc++.h>

using namespace std;

struct Stack {

    int first = -1  ;
    int* mas;
    int size = 0;

    Stack(string s){
        size = s.length();
        mas = new int[size];
    }
    int pop(){
        return this->mas[first--];
    }
    void push(int val){
        this->mas[++first] = val;
    }
    void perform(char op){
        int op1, op2;
        if(first < 1) cout << "\nWrong input\n";
        op2 = pop();
        op1 = pop();
        switch(op){
            case '+' : {
                push(op1+op2);
                break;
            }
            case '-' : {
                push((op1-op2));
                break;
            }
            case '*' : {
                push(op1*op2);
                break;
            }
            case '/' : {
                push(op1/op2);
                break;
            }
            default : { cout << "\nWrong operand\n"; break; }
        }
    }
    int calculate(string str){
        string dels = " ,;";
        string opers = "+-*/";
        do {
            for(int i = 0; i < size; i++){
                char s = str[i];
                if(find(dels.begin(), dels.end(), s) == dels.end()) {
                    if(find(opers.begin(), opers.end(), s) == opers.end()) push(s - '0');
                    else perform(s);
                }
            }
        } while(first != 0);
        return this->mas[first];
    }
};
int main() {
    while (1) {
        string str;
        cout << "\nEnter expression\n";
        getline(cin, str);
        Stack stack1(str);
        cout << "\nResult: " << stack1.calculate(str);
    }
}
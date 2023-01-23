#ifndef PR4_EQUATIONTree_H
#define PR4_EQUATIONTree_H

#include <bits/stdc++.h>

using namespace std;

struct EquationTree{
    struct Node{
        string val;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(string val) : val(val) {}
    };
    Node* root = nullptr;

    EquationTree(Node* root): root(root) {}

    int priority(char op){
        if(op == '+' || op == '-'){
            return 1;
        } else if(op == '*' || op == '/'){
            return 2;
        } else {
            return 0;
        }
    }
    string toPostfix(string equation){
        string postfix = "";
        stack<char> operators;
        for(int i = 0; i < equation.length(); i++){
            if(equation[i] == '('){
                operators.push(equation[i]);
            } else if(equation[i] == ')'){
                while(!operators.empty() && operators.top() != '('){
                    postfix += operators.top();
                    operators.pop();
                }
                operators.pop();
            } else if(equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/'){
                while(!operators.empty() && operators.top() != '(' && priority(equation[i]) <= priority(operators.top())){
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(equation[i]);
            } else {
                postfix += equation[i];
            }
        }
        while(!operators.empty()){
            postfix += operators.top();
            operators.pop();
        }
        return postfix;
    }
    void evaluate(string equation){
        string postfix = toPostfix(equation);
        stack<Node*> operands;
        for(int i = 0; i < postfix.length(); i++){
            if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
                Node* node = new Node(string(1, postfix[i]));
                node->right = operands.top();
                operands.pop();
                node->left = operands.top();
                operands.pop();
                operands.push(node);
            } else {
                operands.push(new Node(string(1, postfix[i])));
            }
        }
        root = operands.top();
    }
    void print(Node* node, int level){
        if(node != nullptr)
        {
            print(node->right,level + 1);
            for(int i = 0; i < level; i++) cout << "        |";
            cout << "->[ ";
            cout << node->val << " ] " << endl;
            print(node->left,level + 1);
        }
    }
    void print(){
        print(root, 0);
    }
};

#endif

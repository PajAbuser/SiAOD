#ifndef PR4_TREE_H
#define PR4_TREE_H

#include <bits/stdc++.h>

using namespace std;

struct Node{
    char val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    Node(char val): val(val), left(nullptr), right(nullptr), parent(nullptr) {}
    Node* child(char val){
        Node child =  Node(val);
        child.parent = this;
        return &child;
    }
};
struct Tree{
    Node* root;
    int minLevel = 0;
    int maxLevel = 0;
    Tree(): root(nullptr) {}
    Node* find(Node* node, Node* target){
        if(node != target){
            if(node->left  != nullptr) find(node->left , target);
            if(node->right != nullptr) find(node->right, target);
        }
        return node;
    }
    Node* findEmpty(Node* node){
        if(node->left == nullptr || node->right == nullptr){
            return node;
        } else {
            if(node->left  != nullptr) findEmpty(node->left );
            if(node->right != nullptr) findEmpty(node->right);
        }
    }
    void add(Node* node){
        maxLevel++;
        if(root == nullptr){
            root = node;
            return;
        }
        if(root->left == nullptr){
            root->left = node;
            return;
        } else if(root->right == nullptr){
            root->right = node;
            return;
        }
        Node* n = findEmpty(root);
        if(n->left == nullptr){
            n->left = node;
            return;
        } else if(node->right == nullptr){
            n->right = node;
            return;
        }
    }
    void print(Node* node, int level){
        if(node != nullptr){
            cout
            << setw((maxLevel-level)*3 / pow(2,level))
            << node->val
            << setw((maxLevel-level)*3 / pow(2,level)) << endl;

            if(node != nullptr) {
                print(node->left , level + 1);
                print(node->right, level + 1);
            }
        }

    }
    void print(){
        Node* node = root;
        if(node != nullptr){
            cout << setw(maxLevel*3) << node->val << setw(maxLevel) << endl;
            if(node->left  != nullptr) print(node->left, 1 );
            if(node->right != nullptr) print(node->right, 1);
        }
    }
};

#endif
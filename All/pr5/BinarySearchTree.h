#ifndef PR4_BINARYSEARCHTREE_H
#define PR4_BINARYSEARCHTREE_H

#include <bits/stdc++.h>
#include "BinaryFiles.h"

using namespace std;

struct BinarySearchTree{
    struct Node{
        Bank val;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(Bank val): val(val) {}
        Node() {}
    };

    Node* root = nullptr;

    void add(Node* node){
        if(root == nullptr){
            root = node;
            return;
        }
        Node* current = root;
        while(true){
            if(node->val.code < current->val.code){
                if(current->left == nullptr){
                    current->left = node;
                    return;
                }
                current = current->left;
            } else {
                if(current->right == nullptr){
                    current->right = node;
                    return;
                }
                current = current->right;
            }
        }
    }
    void print(Node* node, int level){
        if(node)
        {
            print(node->right,level + 1);
            for(int i = 0; i < level; i++) cout << "                 |";
            if(node == root) cout << "root is:";
            cout << "->[ ";
            cout << node->val.code << " ] " << endl;
            print(node->left,level + 1);
        }
    }
    void print(){
        print(root, 0);
    }
    void remove(Node* node) {
        if (root == nullptr) {
            cout << "Tree is already empty";
            return;
        }
        Node* parent = nullptr;
        Node* current = root;
        while (current != nullptr && current->val.code != node->val.code) {
            parent = current;
            if (node->val.code < current->val.code) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (current == nullptr) {
            return;
        }
        if (current->left == nullptr && current->right == nullptr) {
            if (current == root) {
                root = nullptr;
            } else if (parent->left == current) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        } else if (current->left == nullptr) {
            if (current == root) {
                root = current->right;
            } else if (parent->left == current) {
                parent->left = current->right;
            } else {
                parent->right = current->right;
            }
        } else if (current->right == nullptr) {
            if (current == root) {
                root = current->left;
            } else if (parent->left == current) {
                parent->left = current->left;
            } else {
                parent->right = current->left;
            }
        } else {
            Node *successor = current->right;
            Node *successorParent = current;
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
            if (current == root) {
                root = successor;
            } else if (parent->left == current) {
                parent->left = successor;
            } else {
                parent->right = successor;
            }
            successor->left = current->left;
            if (successor != current->right) {
                successorParent->left = successor->right;
                successor->right = current->right;
            }
        }
    }
    void inOrder(Node* node, vector<Node*>& nodes){
        if(node){
            inOrder(node->left, nodes);
            nodes.push_back(node);
            inOrder(node->right, nodes);
        }
    }
    void addAVL(Node* node){
        if(root == nullptr){
            root = node;
            return;
        }
        Node* current = root;
        while(true){
            if(node->val.code < current->val.code){
                if(current->left == nullptr){
                    current->left = node;
                    return;
                }
                current = current->left;
            } else {
                if(current->right == nullptr){
                    current->right = node;
                    return;
                }
                current = current->right;
            }
        }
    }
    void rightTurn(Node* node){
        Node* left = node->left;
        node->left = left->right;
        left->right = node;
        node = left;
    }
    void leftTurn(Node* node){
        Node* right = node->right;
        node->right = right->left;
        right->left = node;
        node = right;
    }
    void rightLeftTurn(Node* node){
        rightTurn(node->right);
        leftTurn(node);
    }
    void leftRightTurn(Node* node){
        leftTurn(node->left);
        rightTurn(node);
    }
    void ballanceLikeAVL(){
        vector<Node*> nodes;
        inOrder(root, nodes);
        for (int i = 0; i < nodes.size(); ++i) {
            if(nodes[i]->left != nullptr && nodes[i]->right != nullptr){
                if(nodes[i]->left->val.code > nodes[i]->right->val.code){
                    leftRightTurn(nodes[i]);
                } else {
                    rightLeftTurn(nodes[i]);
                }
            } else if(nodes[i]->left != nullptr){
                if(nodes[i]->left->val.code > nodes[i]->val.code){
                    leftRightTurn(nodes[i]);
                }
            } else if(nodes[i]->right != nullptr){
                if(nodes[i]->right->val.code < nodes[i]->val.code){
                    rightLeftTurn(nodes[i]);
                }
            }
        }
    }
    string find(Node* val){
        string path = "root";
        Node* current = root;
        while (current != nullptr && current->val.code != val->val.code) {
            if (val->val.code > current->val.code && current->right != nullptr) {
                current = current->right;
                path += " -> [^]";
            } else if(current->left != nullptr){
                current = current->left;
                path += " -> [v]";
            }
            else return "Not found";
        }
        return path;
    }
};


#endif
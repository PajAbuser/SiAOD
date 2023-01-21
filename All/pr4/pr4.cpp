#include "iostream"
#include "Tree.h"

using namespace std;

int main() {
    Tree T = Tree();
    for(int i = 0; i < 10; i++){
        T.add(new Node(i));
    }
    T.print();
    cout << endl;
}
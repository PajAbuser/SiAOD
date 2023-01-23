#include "iostream"
#include "EquationTree.h"
#include "../pr5/BinarySearchTree.h"

using namespace std;

int main() {
    srand(time(NULL));

    int size = 8;
    BinarySearchTree *binarySearchTree = new BinarySearchTree();
    BinarySearchTree::Node *nodes = new BinarySearchTree::Node[size];

    while (true) {

        cout << "\n1 - EquationTree\n2 - BinarySearchTree\n3 - Alphabetical order\n4 - Longest word\n5 - Find/Remove\n6 - Exit\n";

        int choice = 0;
        cin >> choice;
        switch (choice) {
            case 1: {
                string equation = "2+3*4-1";
                cout << "\nEquation is " << equation << endl;
                EquationTree equationTree = EquationTree(nullptr);
                equationTree.evaluate(equation);
                equationTree.print();
                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 2: {
                *&binarySearchTree = new BinarySearchTree();
                for (int i = 0; i < size; i++) {
                    string word = "";
                    for (int i = 0; i < rand() % 10 + 1; i++) {
                        word += (char) (rand() % 26 + 65);
                    }
                    nodes[i] = BinarySearchTree::Node(word);
                    binarySearchTree->add(&nodes[i], binarySearchTree->root);
                }
                binarySearchTree->print();
                break;
            }
            case 3: {
                binarySearchTree->printInAlphabetical();
                break;
            }
            case 4: {
                binarySearchTree->findLongest();
                break;
            }
            case 5: {
                for(int i = size-1; i != -1; i--){
                    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Searching for " << nodes[i].val;
                    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Path: " << binarySearchTree->find(nodes[i].val);
                    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Removing " << nodes[i].val;
                    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
                    binarySearchTree->remove(&nodes[i]);
                    binarySearchTree->print();
                }
                break;
            }
            case 6: {
                return 0;
            }
        }
    }
}
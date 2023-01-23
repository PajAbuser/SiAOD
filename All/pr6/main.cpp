#include "Graph.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    srand(time(NULL));
    while(true) {
        Graph graph;
        int size;
        cout << "\nEnter graph size:";
        cin >> size;
        graph.generate(size);
        graph.print();
        graph.PrimMST();
    }
}
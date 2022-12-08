#include <iostream>
#include <bits/stdc++.h>
#include "OneWayLists.h"
#include "MyH.h"

using namespace std;

void rewriteList(List &list, int n){

    List tmp = List();
    for(int i = 0; i < n; i++){
        tmp.addNode(list.ptrFirst->val);
        list.ptrFirst = list.ptrFirst->ptrNext;
    }
    tmp.ptrLast->ptrNext = nullptr;
    list.ptrLast = tmp.ptrLast;

}

List insertInDownsortedList(List &l2o, Node* node){

    List l2 = l2o;
    int min = 100000;
    while(l2.ptrFirst->ptrNext != nullptr){
        if(l2.ptrFirst->val < min) min = l2.ptrFirst->val;
        l2.ptrFirst = l2.ptrFirst->ptrNext;
    }
    if(node->val < min) {
        l2o.addNode(node->val);
        return l2o;
    }
    int n = 0;
    l2 = l2o;
    while(1){
        //cout << node->val << " " << l2.ptrFirst->ptrNext->val << " " << ( l2.ptrFirst->ptrNext == nullptr) << endl;
        if(l2.ptrFirst->val <= node->val) break;

        l2.ptrFirst = l2.ptrFirst->ptrNext;
        n++;
    }
    //cout << endl << node->val << " " << n << endl;
/*    if(l2.ptrFirst->ptrNext == nullptr) {
        l2o.addNode(node->val);
        return l2o;
    }*/
    l2o.insertNode(node,n);
    return l2o;
}

int main() {

    while(1) {
        cout << "\nTask?(1-3)\n";
        int select1;
        cin >> select1;
        switch (select1) {
            case 1 : {

                List l1;
                cout << "\nEnter list size\n";
                int list_size; cin >> list_size;
                for(int i = 0; i < list_size; i++){
                l1.addNode(i);
                }
                cout << endl;
                l1.print();
                cout << "\nEnter node position (it will be equal to n % list_size)\n";
                int n; cin >> n;
                //l1.removeNode(n);
                rewriteList2(l1, n - 1);
                cout << endl;
                l1.print();

                break;
            }
            case 2 : {
                List l2;
                cout << "\nEnter list size\n";
                int list_size; cin >> list_size;
                for(int i = 0; i < list_size; i++){
                    l2.addNode(list_size - i);
                }
                cout << endl << "Enter node value\n";
                int n; cin >> n;
                Node* node = new Node(n);
                l2.print();
                //l2.insertNode(node,n);
                insertInDownsortedList(l2, node);
                l2.print();
                break;
            }
            case 3 : {
                List l2;
                cout << "\nEnter list size\n";
                int list_size; cin >> list_size;
                for(int i = 0; i < list_size; i++){
                    l2.addNode(list_size - i);
                }
                cout << endl << "Enter val of node\n";
                int n; cin >> n;
                Node* node = new Node(n);
                l2.print();
                //l2.insertNode(node,n);
                insertInDownsortedList(l2, node);
                l2.print();
                l2.uniquify();
                l2.print();
                break;
            }
            case 4 : {
                /*List L;
                for(int i = 0; i < 10; i++){
                    L.addNode(i);
                }*/
                /*int p1, p2;
                cout <<"\nEnter p1,p2\n";
                cin >> p1 >> p2;*/
                //L.print();
                //def(L,p1,p2);
                int n; cin >> n;
                rec(n);
               // Res.print();
            }

        }

    }

}

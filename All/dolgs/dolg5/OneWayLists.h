#ifndef DOLG6_ONEWAYLISTS_H
#define DOLG6_ONEWAYLISTS_H

using namespace std;

struct Node{

    int val;
    Node* ptrNext;
    Node(int _val) : val(_val), ptrNext(nullptr) {}

};

struct List {

    Node* ptrFirst;
    Node* ptrLast;

    List() : ptrFirst(nullptr), ptrLast(nullptr) {}

    bool is_empty() {
        return ptrFirst == nullptr;
    }

    void addNode(int val) {
        Node* p = new Node(val);
        if (is_empty()) {
            ptrFirst = p;
            ptrLast = p;
            return;
        }
        ptrLast->ptrNext = p;
        ptrLast = p;
    }

    void print() {
        if (is_empty()) return;
        Node* p = ptrFirst;
        while (p) {
            cout << p->val << " ";
            p = p->ptrNext;
        }
        cout << endl;
    }

    void removeNode(int n){

        List temp = *this;

        Node* node = this->ptrFirst;

        for(int i = 0; i < n; i++){
            node = node->ptrNext;
        }

        while(temp.ptrFirst->ptrNext != nullptr){

            if(temp.ptrFirst->ptrNext != node) {
                temp.ptrFirst = temp.ptrFirst->ptrNext;
            }
            else {
                Node* tmp = temp.ptrFirst->ptrNext;
                temp.ptrFirst->ptrNext = temp.ptrFirst->ptrNext->ptrNext;
                delete tmp;
            }
        }
    }

    void removeNode(Node* n){

        List temp = *this;
        while(temp.ptrFirst->ptrNext != nullptr){

            if(temp.ptrFirst->ptrNext != n) {
                temp.ptrFirst = temp.ptrFirst->ptrNext;
            }
            else {
                Node* tmp = temp.ptrFirst->ptrNext;
                temp.ptrFirst->ptrNext = temp.ptrFirst->ptrNext->ptrNext;
                delete tmp;
            }
        }
    }
    void cut(Node* n){

        List temp = *this;
        while(temp.ptrFirst->ptrNext != nullptr){

            if(temp.ptrFirst->ptrNext != n) {
                temp.ptrFirst = temp.ptrFirst->ptrNext;
            }
            else {
                temp.ptrFirst->ptrNext = nullptr;
            }
            this->ptrLast = temp.ptrFirst;
        }
    }

    void insertNode(Node* n, int pos) {

        List temp = *this;
        //this->print();
        List temp2;

        Node *tmp, *tmp2;

        for (int i = 0; i < pos; i++) {

            temp2.addNode(temp.ptrFirst->val);
            temp.ptrFirst = temp.ptrFirst->ptrNext;

        }

        temp2.addNode(n->val);

        while (temp.ptrFirst != nullptr) {

            temp2.addNode(temp.ptrFirst->val);
            temp.ptrFirst = temp.ptrFirst->ptrNext;

        }

        //temp2.print();

        *this = temp2;

    }

    void uniquify(){

        //List ol = *this;
        List l = *this;
        List temp;
        while(l.ptrFirst->ptrNext != nullptr){

            //this->print();
            while(l.ptrFirst->val == l.ptrFirst->ptrNext->val){
                l.ptrFirst->ptrNext = l.ptrFirst->ptrNext->ptrNext;
            }
            //this->print();
            temp.addNode(l.ptrFirst->val);
            l.ptrFirst = l.ptrFirst->ptrNext;

        }

        temp.addNode(l.ptrFirst->val);
        //temp.print();
        cout << endl;
        *this = temp;
        //this->print();
    }

};

void rewriteList2(List &list, int n){
    for(int i = 0; i < n; i++){

        list.addNode(list.ptrFirst->val);

        Node* temp = list.ptrFirst;
        list.ptrFirst = list.ptrFirst->ptrNext;
        delete temp;

        //cout << "\nSwapped + deleted\n";
    }
}

void rewriteList1(List &list, int n, int &k, int size, List &otemp){

    List temp = otemp;
    //temp.print(); cout << endl;
    if(k < n){
        int i = 0;
        while(temp.ptrFirst->ptrNext != nullptr){
            cout << "\n" << k << " " << temp.ptrFirst->val << "\n";
            temp.ptrFirst = temp.ptrFirst->ptrNext;
            i++;
        }
        list.addNode(temp.ptrFirst->val);
        otemp.removeNode(temp.ptrFirst);
        k++;
        rewriteList1(list,n,k,size, otemp);

    }

}

void def(List &L, int p1, int p2){

    List temp = L; List R;
    int n = 0;
    while(n < p1){
        temp.ptrFirst = temp.ptrFirst->ptrNext;
        n++;
    }
    for(int i = p1; i <= p2; i++){
        R.addNode(temp.ptrFirst->val);
        temp.ptrFirst = temp.ptrFirst->ptrNext;
    }
    Node* tmp = temp.ptrFirst;
    temp = L;
    for(int i = 0; i < p1; i++) {
        R.addNode(temp.ptrFirst->val);
        temp.ptrFirst = temp.ptrFirst->ptrNext;
    }
    while(tmp != nullptr){
        R.addNode(tmp->val);
        tmp = tmp->ptrNext;
    }
    L = R;
}

List Res;

void rec(int n){
    int x;
    if(n != 0) {
        cin >> x;
        rec(n-1);
    }
    cout << x << " ";
}


#endif //DOLG6_ONEWAYLISTS_H

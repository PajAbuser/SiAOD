#include "MyH.h"
#include "../dolg5/OneWayLists.h"

using namespace std;

int main() {

    while(1) {
        cout << "\n1 - Calculate f(x) = e^x in certain x with e > 0\n2 - List task\n";
        int select1;
        cin >> select1;
        switch (select1) {
            case 1 : {
                cout << "\nEnter x and epsilon(precision)\n";
                double x, e;
                cin >> x >> e;
                cout << "\nf = " << func1(x, e) << endl;
                break;
            }
            case 2 : {

                List l;
                cout << "\nEnter size\n";
                int n, size; cin >> size;
                for(int i = 0; i < size; i++){
                    l.addNode(i);
                }
                cout << "\nEnter 'n'\n";
                cin >> n;
                l.print(); cout << endl;
                rewriteList2(l,n);
                //l.print(); cout << endl;
                int k = 0, i = 0;
                List temp = l;
                while(i < size - n - 1){
                    temp.ptrFirst = temp.ptrFirst->ptrNext;
                    i++;
                }
                temp.ptrFirst = temp.ptrFirst->ptrNext;
                Node* tmp = temp.ptrFirst;
                //temp.print();
                l.cut(tmp);
                rewriteList1(l,n,k,size,temp);
                l.print();

                break;
            }
            case 3 : {

                while(1) {
                    cout << "\nEnter max num\n";
                    int n = 0; cin >> n;
                    if(n == 0) break;
                    for (int i = 0; i <= n; i++) {
                        std::cout << i << ": = " << factorial(i) << std::endl;
                    }
                }
            }
            case 4 : {

                int a, b; cout << "\nEnter a,b\n";
                cin >> a >> b;
                cout << pr(a, b);

            }
        }
    }
}

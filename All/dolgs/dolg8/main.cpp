#include <bits/stdc++.h>

using namespace std;

long long cmp, ass;

void bubbleSort(int* &mas, int size){
    cmp = 0; ass = 0;
    int temp;  bool sorted;
    do {
        sorted = true; ass++;
        for (int i = 0; i < size - 1; i++) {
            if (mas[i] > mas[i + 1]) {
                cmp++;
                sorted = false; ass++;
                temp = mas[i]; ass++;
                mas[i] = mas[i + 1]; ass++;
                mas[i + 1] = temp; ass++;
            }
        }
    cmp++;
    } while(!sorted);
}

void merge(int* mas,int p,int q,int r) {
    int n1=q-p+1; ass++;
    int n2=r-q; ass++;
    int * L; int * R;
    L=new int[n1+1];
    R=new int[n2+1];
    for(int i=1;i<=n1; i++) {
        cmp++;
        L[i-1]=mas[p+i-1]; ass++;
    }
    for(int j=1;j<=n2; j++) {
        cmp++;
        R[j-1]=mas[q+j]; ass++;
    }
    for(int i=0,j=0,k=p; k<=r; k++) {
        cmp++;
        if(i<n1 && j<n2) {
            cmp++;
            if(L[i]<=R[j]) {
                cmp++;
                mas[k]=L[i]; ass++;
                i++;
            } else {
                cmp++;
                mas[k]=R[j]; ass++;
                j++;
            }
        } else if(i<n1) {
            cmp++;
            mas[k]=L[i]; ass++;
            i++;
        } else {
            cmp++;
            mas[k]=R[j]; ass++;
            j++;
        }
    }
    delete [] L; delete [] R;
}
void mergeSort(int* mas,int p,int r) {
    int q;
    if(p<r) {
        q=(p+r)/2; ass++;
        mergeSort(mas,p,q);
        mergeSort(mas,q+1,r);
        merge(mas,p,q,r);
    }
}

void print(int * A,int size) {
    for(int i=0; i<size; i++)
        printf("%d ",A[i]);
    printf("\n");
}

void shellSort(int* &mass, int n) {
    cmp = 0; ass = 0;
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2) {
        cmp++;
        for (i = step; i < n; i++) {
            cmp++;
            tmp = mass[i]; ass++;
            for (j = i; j >= step; j -= step) {
                cmp++;
                cmp++;
                if (tmp < mass[j - step]) {
                    mass[j] = mass[j - step]; ass++;
                }
                else
                    break;
            }
            mass[j] = tmp; ass++;
        }
    }
}

int main() {
    system("chcp 65001");
    //setlocale(LC_ALL, "ru_RU.UTF-8");

    srand(time(NULL));

    cout << "\nEnter size: \n";
    int size;
    //cin >> size;
    for (int i = 100; i < 10000000; i *= 10) {
        size = i;
        int *a = new int[size];
        int *b;
        int *c;
        cout << "\n Size = " << size << ", mas:\n";
        for (int i = 0; i < size; i++) {
            a[i] = rand() % 100;
            //cout << a[i] << " ";
        }
        b = a;
        c = a;
        auto s = std::chrono::high_resolution_clock::now();
        bubbleSort(a, size);
        auto e = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> dur = e - s;
        cout << "\n\nBubble sort duration = " << dur.count() * 1000 << endl;
        cout << "\nComparisons = " << cmp << " , assigns = " << ass << endl;
        cout << cmp + ass << endl;
        s = std::chrono::high_resolution_clock::now();
        shellSort(b, size);
        e = std::chrono::high_resolution_clock::now();
        dur = e - s;
        cout << "\nShell sort duration = " << dur.count() * 1000 << endl;
        cout << "\nComparisons = " << cmp << " , assigns = " << ass << endl;
        cout << cmp + ass << endl;
        s = std::chrono::high_resolution_clock::now();
        cmp = 0; ass = 0;
        mergeSort(a, 0, size);
        e = std::chrono::high_resolution_clock::now();
        dur = e - s;
        cout << "\n\nBubble sort duration = " << dur.count() * 1000 << endl;
        cout << "\nComparisons = " << cmp << " , assigns = " << ass << endl;
        cout << cmp + ass << endl;

    }
}
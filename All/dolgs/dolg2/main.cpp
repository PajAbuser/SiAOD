#include <iostream>
#include <bits/stdc++.h>
#define ROWS 5
#define COLS 5


using namespace std;


void fillRand(int (*mat)[COLS] , int r, int c){

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){

            mat[i][j] = rand() % 18 - 9;

        }
    }

}

void fillRand(int** &mat, int r, int c){

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){

            mat[i][j] = rand() % 18 - 9;

        }
    }

}

void fillRand(vector<vector<int>> &mat){

    int r = mat.size();
    int c = mat[0].size();

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){

            mat[i][j] = rand() % 18 - 9;

        }
    }

}

void fillCin(int** &mat, int r, int c){

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){

            cin >> mat[i][j];

        }
    }

}

void printMat(int** &mat, int r, int c){

    for(int i = 0; i < r; i++){
        cout << "{ ";
        for(int j = 0; j < c - 1; j++){

            cout << setw(4) << mat[i][j] << " , ";

        }
        cout << setw(4) << mat[i][c - 1] << " }" << endl;
    }

}

void printMat(vector<vector<int>> mat){

    int r = mat.size();
    int c = mat[0].size();

    for(int i = 0; i < r; i++){
        cout << "{ ";
        for(int j = 0; j < c - 1; j++){

            cout << setw(4) << mat[i][j] << " , ";

        }
        cout << setw(4) << mat[i][c - 1] << " }" << endl;
    }

}

void printMat(int mat[][COLS], int r, int c){

    for(int i = 0; i < r; i++){
        cout << "{ ";
        for(int j = 0; j < c - 1; j++){

            cout <<  setw(4) << mat[i][j] << " , ";

        }
        cout << setw(4) << mat[i][c - 1] << " }" << endl;
    }

}

void task1(){

    int mat[ROWS][COLS];

    fillRand(mat,ROWS,COLS);

    printMat(mat,ROWS,COLS);

    cout << endl;

    long long int sum1 = 1;

    for(int i = 0; i < ROWS; i++){


        cout << setw(2*ROWS - 3 + i*7) << " ";

        for(int j = i + 1; j < COLS; j++){

            sum1 *= mat[i][j];
            cout << setw(i - 1) << " " << setw(5) << mat[i][j] << " ";

        }

        cout << endl;

    }

    cout << "\nProduct 1 = " << sum1 << endl << endl;

    long long int sum2 = 1;

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS - i - 1; j++){

            sum2 *= mat[i][j];
            cout << setw(6) << mat[i][j] << " ";

        }

        cout << endl;

    }

    cout << "\nProduct 2 = " << sum2 << endl;

    if(sum1 == sum2) cout << "\nEqual\n";
    else cout << "\nNot equal\n";

}

void task2(){

    int a, b; cin >> a >> b;

    int** mat = new int*[a];

    for(int i = 0; i < a; i++){
        mat[i] = new int[b];
    }

    fillRand(mat,a,b);

    printMat(mat,a,b);

    cout << endl;

    long long int sum1 = 1;

    for(int i = 0; i < a; i++){


        cout << setw(2*a - 3 + i*7) << " ";

        for(int j = i + 1; j < b; j++){

            sum1 *= mat[i][j];
            cout << setw(i - 1) << " " << setw(5) << mat[i][j] << " ";

        }

        cout << endl;

    }

    cout << "\nProduct 1 = " << sum1 << endl << endl;

    long long int sum2 = 1;

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b - i - 1; j++){

            sum2 *= mat[i][j];
            cout << setw(6) << mat[i][j] << " ";

        }

        cout << endl;

    }

    cout << "\nProduct 2 = " << sum2 << endl;

    if(sum1 == sum2) cout << "\nEqual\n";
    else cout << "\nNot equal\n";

}

void task3(){

    int a, b; cin >> a >> b;

    vector<vector<int>> mat(a);

    for(int i = 0; i < a; i++){
        mat[i].resize(b);
    }

    fillRand(mat);

    printMat(mat);

    long long int sum1 = 1;

    for(int i = 0; i < a; i++){

    for(int j = i + 1; j < b; j++){

    sum1 *= mat[i][j];
    cout << mat[i][j] << " ";

    }

    cout << endl;

    }

    cout << "\nProduct 1 = " << sum1 << endl;

    long long int sum2 = 1;

    for(int i = 0; i < a; i++){

    for(int j = 0; j < b - i - 1; j++){

    sum2 *= mat[i][j];
    cout << setw(3) << mat[i][j] << " ";

}

cout << endl;

}

cout << "\nProduct 2 = " << sum2 << endl;

if(sum1 == sum2) cout << "\nEqual\n";
else cout << setw(3) << "\nNot equal\n";

}

int main() {

    srand(time(NULL));

    while (1) {
        cout << "\nSelect task (1-3)\n";
        int select1;
        cin >> select1;
        switch (select1) {

            case 1: {
                task1();
                break;
            }
            case 2: {
                task2();
                break;
            }
            case 3: {
                task3();
                break;
            }
            default: {
                break;
            }
        }
    }
}

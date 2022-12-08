#ifndef DOLG3_MYH_H
#define DOLG3_MYH_H
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long int factorial(int x, int &sum){
    if(x > 0) {
        return sum * x * factorial(x - 1, sum);
    }
    if(x == 0) return 1;
    return -1;
}

long long int factorial(int x){
    int sum = 1;
    if(x == 0) return sum;
    return sum * x * factorial(x-1,sum);
}

double func1(double x, int n) {
    if(n > 0) {
        return (pow(x, n) / factorial(n)) + func1(x, n-1);
     }
    if(n == 0) return (pow(x, n) / factorial(n));
    return -1.0;
}

double func1(double x, double e){
    double sum = 0; int n = 1;
    while (fabs(pow(x, n)) / factorial(n) > e) {
        n++;
    }
    //cout << endl << n << endl;
    return sum + func1(x,n);

};

int pr(int a, int b){
    int max1 = max(a, b);
    int min1 = min(a, b);
    if(a == 1 || b == 1) {
        return max1 / min1;
    }
    return max1 / min1 + pr(max1 % min1, min1);

}

#endif //DOLG3_MYH_H

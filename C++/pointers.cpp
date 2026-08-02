#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void update(int *a, int *b) {
    int sum = *a + *b;
    int diff = abs(*b - *a);
    *a = sum;
    *b = diff;
    cout << *a << endl << *b << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a, b;
    cout << "Enter two values for a and  b: " << endl;
    cin >> a >> b;
    int *c = &a;
    int *d = &b;
    update(c, d);
    return 0;
}

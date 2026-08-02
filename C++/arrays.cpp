#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    cout << "Enter the number of Values expected in the first line, then enter the values in the second line: " << endl;
    int n;
    cin >> n;
    
    vector<long> list(n);
    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }

    for (int i = n-1; i >= 0; --i) {
        cout << list[i] << " ";
    }  
    return 0;
}

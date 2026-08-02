#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

int longest_proper_divisor(int n) {
    if (n <= 1) {
        return 0;
    } 
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}

void process_input(int n) {
    try {
        int result = longest_proper_divisor(n);
        
        if (result == 0) {
            throw invalid_argument("largest proper divisor is not defined for n=" + to_string(n));
        }
        cout << "result=" << result << endl;
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl; // cout for hackerrank code editor
    }
    
    cout << "returning control flow to caller" << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    process_input(n);
    return 0;
}

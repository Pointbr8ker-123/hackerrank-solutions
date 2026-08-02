#include <iostream>
using namespace std;

int largestProperDivisor(int n) {
    if (n <= 1) return -1;  // Undefined for n ≤ 1
    for (int i = n/2; i >= 1; i--) {
        if (n % i == 0) return i;
    }
    return 1;  // Prime numbers
}

int main() {
    int n = 15;
    cout << "Largest proper divisor of " << n << ": " 
         << largestProperDivisor(n) << endl;  // Output: 5
    return 0;
}
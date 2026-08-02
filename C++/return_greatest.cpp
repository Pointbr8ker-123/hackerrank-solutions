#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int return_greatest(int a, int b, int c, int d) {
    vector<int> numbers = {a, b, c, d};
    
    int greatest = numbers[0];
    for (int number : numbers) {
        if (number > greatest) {
            greatest = number;
        }
    }
    return greatest;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout << endl;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    cout << return_greatest(a, b, c, d) << endl;
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

vector<int> string_stream(string str) {
    vector<int> result;
    stringstream ss(str);
    int numbers;
    char commas;
    
    while (ss >> numbers) {
        result.push_back(numbers);
        ss >> commas;
    }
    
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string str;
    cin >> str;
    vector<int> numbers = string_stream(str);
    
    for (int num : numbers) {
        cout << num << endl;
    }

    return 0;
}

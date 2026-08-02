#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cout << "Enter a word: ";
    string word;
    cin >> word;

    int l_index = word.size() - 1;
    int sl_index = word.size() - 2;

    if (word[sl_index] == 'r' && word[l_index] == 'd') {
        cout << "The last two letters are r and d" << endl;
    }
}
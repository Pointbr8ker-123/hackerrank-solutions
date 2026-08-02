#include <iostream>
using namespace std;

// Reversing a string
string ReverseString(string word) {
    string reversed_word = "";
    for (int i = word.size(); i >= 0; i--) {
        reversed_word += word[i];
    }
    return reversed_word;
}

int main() {
    cout << "Enter a word you want reversed: ";
    string word; cin >> word;

    string reversed_word = ReverseString(word);
    cout << "Reversed Word: " << reversed_word << endl;
}
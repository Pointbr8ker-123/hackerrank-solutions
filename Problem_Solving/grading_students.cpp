#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;


vector<int> gradingStudents(vector<int> grades) {
    vector<int> results;
    for (int i = 0; i < grades.size(); i++) {
        int grade = grades[i];
        int nextMultiple = ((grade + 4) / 5) * 5;

        if (grade >= 38 && (nextMultiple - grade) < 3) {
            results.push_back(nextMultiple);
        } else {
            results.push_back(grade);
        }
    }
    return results;
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(n);
    for (int i = 0; i < n; ++i) {
        cin >> grades[i];
    }
    cout << endl;
    vector<int> results = gradingStudents(grades);
    for (int grade : results) {
        cout << grade << endl;
    }
    return 0;
}
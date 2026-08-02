#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int find_runner_up(vector<int> scores) {
    set<int, greater<int>> scores_set;
    if (scores_set.size() < 2) return -1;

    for (auto score : scores) scores_set.insert(score);
    
    scores_set.erase(scores_set.begin());

    int second_highest = *scores_set.begin();
    return second_highest;
}

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);

    vector<int> scores;
    int num;
    while (ss >> num) {
        scores.push_back(num);
    }

    int second_highest = find_runner_up(scores);
    cout << second_highest << endl;
}
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<vector<int>> arr(6, vector<int>(6));

    cout << "Enter 36 values to fill up a 6x6 2D array: " << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }

    int max_sum = INT_MIN;

    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            int current_sum = 0;
            current_sum += arr[i][j];
            current_sum += arr[i][j+1];
            current_sum += arr[i][j+2];
            current_sum += arr[i+1][j+1];
            current_sum += arr[i+2][j];
            current_sum += arr[i+2][j+1];
            current_sum += arr[i+2][j+2];

            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }

    cout << "Maximum hourglass sum: " << max_sum << endl;
    return 0;
}
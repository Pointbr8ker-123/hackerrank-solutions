#include <iostream>
#include <vector>
using namespace std;


void miniMaxSum(vector<int> arr) {
    long total_sum = 0;
    int max_val = arr[0];
    int min_val = arr[0];
    for (int val : arr) {
        total_sum += val;
        if (val < min_val) {
            min_val = val; // for lowest value in the array
        } else if (val > max_val) {
            max_val = val; // for highest values in the array
        }
    }
    long min_sum = total_sum - max_val;
    long max_sum = total_sum - min_val;
    cout << min_sum << ' ' << max_sum << endl;
}

int main() {
    vector<int> arr = {1,2,4,5,6,7};
    miniMaxSum(arr);
}
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hackerlandRadioTransmitters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER k
 */
vector<int> merge(vector<int> left_arr, vector<int> right_arr) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < left_arr.size() && j < right_arr.size()) {
        if (left_arr[i] < right_arr[j]) {
            result.push_back(left_arr[i]);
            i++;
        } else {
            result.push_back(right_arr[j]);
            j++;
        }
    }    
    result.insert(result.end(), left_arr.begin() + i, left_arr.end());
    result.insert(result.end(), right_arr.begin() + j, right_arr.end());
    return result;
}

vector<int> mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) return arr;
    
    int mid = arr.size()/2;
    vector<int> left_arr(arr.begin(), arr.begin() + mid);
    vector<int> right_arr(arr.begin() + mid, arr.end());
    
    return merge(mergeSort(left_arr), mergeSort(right_arr));
}

int hackerlandRadioTransmitters(vector<int> x, int k) {
    vector<int> sorted_x = mergeSort(x);
    int count_transmitters = 0;
    int n = sorted_x.size();
    int i = 0;

    while (i < n) {
        int loc = sorted_x[i] + k;
        while (i < n && sorted_x[i] <= loc) i++;
        count_transmitters++;

        int transmitter_loc = sorted_x[i-1];

        loc = transmitter_loc + k;
        while (i < n && sorted_x[i] <= loc) i++;
    }
    return count_transmitters;
}

int main() {
    vector<int> houses = {7, 2, 4, 6, 5, 9, 12, 11};
    int number_of_transmitters = hackerlandRadioTransmitters(houses, 2);

    cout << number_of_transmitters << endl;
}
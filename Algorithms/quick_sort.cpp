#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quickSort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
int partition(vector<int>& arr, int l, int h) {
    int pivot = arr[l], i = l+1, j = h;
    while (i <= j) {
        while(i<=j && arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

vector<int> quickSortHelper(vector<int>& arr, int l, int h) {
    if (l < h) {
        int pivot = partition(arr, l, h);
        quickSortHelper(arr, l, pivot-1);
        quickSortHelper(arr, pivot+1, h);
    }
    return arr;
}

vector<int> quickSort(vector<int>& arr) {
    if (arr.empty()) return arr;
    
    vector<int> new_array = quickSortHelper(arr, 0, arr.size()-1);
    return new_array;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,8,7};
    vector<int> new_array = quickSort(arr);

    cout << "[ ";
    for (int val : new_array) {
        cout << val << " ";
    }
    cout << "]" << endl;

    return 0;
}

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string n_temp;
//     getline(cin, n_temp);

//     int n = stoi(ltrim(rtrim(n_temp)));

//     string arr_temp_temp;
//     getline(cin, arr_temp_temp);

//     vector<string> arr_temp = split(rtrim(arr_temp_temp));

//     vector<int> arr(n);

//     for (int i = 0; i < n; i++) {
//         int arr_item = stoi(arr_temp[i]);

//         arr[i] = arr_item;
//     }

//     vector<int> result = quickSort(arr);

//     for (size_t i = 0; i < result.size(); i++) {
//         fout << result[i];

//         if (i != result.size() - 1) {
//             fout << " ";
//         }
//     }

//     fout << "\n";

//     fout.close();

//     return 0;
// }

// string ltrim(const string &str) {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );

//     return s;
// }

// string rtrim(const string &str) {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end()
//     );

//     return s;
// }

// vector<string> split(const string &str) {
//     vector<string> tokens;

//     string::size_type start = 0;
//     string::size_type end = 0;

//     while ((end = str.find(" ", start)) != string::npos) {
//         tokens.push_back(str.substr(start, end - start));

//         start = end + 1;
//     }

//     tokens.push_back(str.substr(start));

//     return tokens;
// }

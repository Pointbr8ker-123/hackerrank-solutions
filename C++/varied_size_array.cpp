#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, q;
    cin >> n >> q;

    vector<vector<int>> parent_array(n);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        parent_array[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> parent_array[i][j];
        }
    }

    for (int query = 0; query < q; query++) {
        int i, j;
        cin >> i >> j;
        cout << parent_array[i][j] << endl;
    }

    return 0;
}


// 2 2
// 3 1 5 4
// 5 1 2 8 9 3
// 0 1
// 1 3
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */

// Create a universal Tree that can be called from anywhere within the solution
vector<vector<int>> Tree;

void swapTree(int node, int depth, int k) {
    // if the node is -1, then its a null node or deadend, so we return
    if (node == -1) return;

    // if depth % k is equal to 0, then it means the current depth is a multiple of k
    // and therefore, a swap between the children of the node we are currently checking
    // would be swapped
    if (depth % k == 0) {
        swap(Tree[node][0], Tree[node][1]);
    }

    // we recursively go through the left and right subtrees to swap the children nodes 
    // of the nodes where the current depth is a multiple of k at that point. 
    swapTree(Tree[node][0], depth+1, k);
    swapTree(Tree[node][1], depth+1, k);
}

void inOrder(int node, vector<int>& ans) {
    // each inorder traversal stores the current state of the tree after each swapping
    // process
    if (node == -1) return;

    inOrder(Tree[node][0], ans);
    ans.push_back(node);
    inOrder(Tree[node][1], ans);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    // Resize the Tree so that we can refer to the first node (or rather children
    // of the first node) as Tree[1] instead of Tree[0]
    Tree.resize(indexes.size() + 1);

    // fill up the created tree vector with the children of the nodes from the indexes
    // array
    for (int i = 1; i <= indexes.size(); i++) {
        Tree[i] = indexes[i-1];
    }

    // Go through every 'k' in the queries array and run the swap and inorder traversal
    // combo for each k
    vector<vector<int>> res;
    for (int k : queries) {
        swapTree(1,1,k);

        vector<int> cur;
        inOrder(1, cur);
        res.push_back(cur);
    }
    // return the different inorder traversal results after every tree swap that occured 
    // for every k in queries
    return res;
}

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string n_temp;
//     getline(cin, n_temp);

//     int n = stoi(ltrim(rtrim(n_temp)));

//     vector<vector<int>> indexes(n);

//     for (int i = 0; i < n; i++) {
//         indexes[i].resize(2);

//         string indexes_row_temp_temp;
//         getline(cin, indexes_row_temp_temp);

//         vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

//         for (int j = 0; j < 2; j++) {
//             int indexes_row_item = stoi(indexes_row_temp[j]);

//             indexes[i][j] = indexes_row_item;
//         }
//     }

//     string queries_count_temp;
//     getline(cin, queries_count_temp);

//     int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

//     vector<int> queries(queries_count);

//     for (int i = 0; i < queries_count; i++) {
//         string queries_item_temp;
//         getline(cin, queries_item_temp);

//         int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

//         queries[i] = queries_item;
//     }

//     vector<vector<int>> result = swapNodes(indexes, queries);

//     for (size_t i = 0; i < result.size(); i++) {
//         for (size_t j = 0; j < result[i].size(); j++) {
//             fout << result[i][j];

//             if (j != result[i].size() - 1) {
//                 fout << " ";
//             }
//         }

//         if (i != result.size() - 1) {
//             fout << "\n";
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

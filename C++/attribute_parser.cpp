#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

map<string, string> attributes;

void parseHRML(int N) {
    vector<string> tag_stack;
    string line;
    
    while (N--) {
        getline(cin, line);
        line.erase(remove(line.begin(), line.end(), '\"'), line.end());
        line.erase(remove(line.begin(), line.end(), '>'), line.end());
        
        if (line.substr(0, 2) == "</") {
            // Closing tag: pop from stack
            tag_stack.pop_back();
        } else {
            // Opening tag: parse attributes
            stringstream ss(line.substr(1));
            string tag, attr, eq, val;
            ss >> tag;
            
            string parent_path;
            if (!tag_stack.empty()) {
                parent_path = tag_stack.back() + ".";
            }
            tag_stack.push_back(parent_path + tag);
            
            while (ss >> attr >> eq >> val) {
                string full_path = tag_stack.back() + "~" + attr;
                attributes[full_path] = val;
            }
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();  // Ignore newline after N and Q
    
    parseHRML(N);
    
    while (Q--) {
        string query;
        cin >> query;
        
        if (attributes.find(query) != attributes.end()) {
            cout << attributes[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }
    
    return 0;
}
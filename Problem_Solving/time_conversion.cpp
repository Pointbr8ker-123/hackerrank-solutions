#include <iostream>
#include <string>
using namespace std;

string timeConversion(string s) {
    int len = s.size();
    int i = len - 2;
    
    string h = s.substr(0, 2);    
    int hrs = stoi(h);
    
    string time_h;

    if ((s[i] == 'A' || s[i] == 'a') && (hrs < 12)) {
        return s.substr(0, 8);
    } 
    else if ((s[i] == 'A' || s[i] == 'a') && (hrs == 12)) {
        s[0] = '0';
        s[1] = '0';
        return s.substr(0, 8);
    }
    else if ((s[i] == 'P' || s[i] == 'p') && (hrs < 12)) {
        hrs += 12;
        time_h = to_string(hrs);
        return time_h + s.substr(2, 6);
    }
    else if ((s[i] == 'P' || s[i] == 'p') && (hrs == 12)) {
        return s.substr(0, 8);
    }
    else {
        return s.substr(0, 8);
    }
}

int main() {
    string s = "07:05:45PM";
    cout << timeConversion(s) << endl;

}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
public:
    string first_name_;
    string last_name_;
    
    string event_(string event_) {
        return event_;
    }
    string introduce_myself(string first_name, string last_name) {
        return "first_name=" + first_name + ",last_name=" + last_name + " ";
    }
    
    Person (string first_name, string last_name) {
        first_name_ = first_name;
        last_name_ = last_name;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string first_name, last_name, _event;
    cin >> first_name >> last_name >> _event;
    
    Person person = Person(first_name, last_name);
    string event = person.event_(_event);
    string p = person.introduce_myself(first_name, last_name);
    
    cout << p << "" << event << endl;
    return 0;
}

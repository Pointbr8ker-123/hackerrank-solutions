#include <iostream>
#include <vector>
using namespace std;

int birthdayCakeCandles(vector<int> candles) {
    int count = 0;
    int highest_candle = candles[0];
    for (int candle : candles) {
        if (candle > highest_candle) {
            highest_candle = candle;
        }
    }
    for (int val : candles) {
        if (val == highest_candle) {
            count++;
        }
    }
    
    return count;
}

int main() {
    vector<int> candles = {4, 4, 5,5,5,5,5,5,5, 1, 2};
    cout << birthdayCakeCandles(candles) << endl;
}
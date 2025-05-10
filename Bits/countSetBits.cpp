#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += (n & 1); // Check if the last bit is 1
        n >>= 1;          // Right shift to check the next bit
    }
    return count;
}
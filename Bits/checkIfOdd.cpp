#include <iostream>
using namespace std;

// see if the last bit is set if it's odd either it's even 
bool isOdd(int n) {
    return (n & 1); // If LSB is 1, the number is odd
}
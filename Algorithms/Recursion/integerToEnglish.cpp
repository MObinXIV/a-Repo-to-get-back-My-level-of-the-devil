//https://leetcode.com/problems/integer-to-english-words/description/
#include<bits/stdc++.h>
using namespace std;
/**
 * Break the number into parts: Billions → Millions → Thousands → Hundreds → Tens → Ones.
 * Handle each part separately using recursion (reuse same logic for smaller chunks).
 * Use predefined word lists for 1–9, 10–19, and tens (20,30,...).
 * Combine parts with words like “Billion”, “Million”, “Thousand”, “Hundred”.
 * Keep building the phrase until the full number is converted to English words.
 */
class Solution {
public:
    const vector<string> belowTen = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    const vector<string> belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    const vector<string> belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return convertToWords(num);
    }

private:
    string convertToWords(int num) {
        if (num < 10) {
            return belowTen[num];
        }
        if (num < 20) {
            return belowTwenty[num - 10];
        }
        if (num < 100) {
            return belowHundred[num / 10] + (num % 10 ? " " + convertToWords(num % 10) : "");
        }
        if (num < 1000) {
            return convertToWords(num / 100) + " Hundred" + (num % 100 ? " " + convertToWords(num % 100) : "");
        }
        if (num < 1000000) {
            return convertToWords(num / 1000) + " Thousand" + (num % 1000 ? " " + convertToWords(num % 1000) : "");
        }
        if (num < 1000000000) {
            return convertToWords(num / 1000000) + " Million" + (num % 1000000 ? " " + convertToWords(num % 1000000) : "");
        }
        return convertToWords(num / 1000000000) + " Billion" + (num % 1000000000 ? " " + convertToWords(num % 1000000000) : "");
    }
};
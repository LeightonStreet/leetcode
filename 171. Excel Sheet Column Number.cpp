/*
171. Excel Sheet Column Number

Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/


class Solution {
public:

    // idea: create a mapping from every capital character to an integer
    //       A -> 1, B -> 2, etc
    //
    //       character - 'A' + 1
    //
    //       for every digit, we also need to compute its weight
    //       d_n d_n-1 d_n-2 ... d_1 d_0
    //       26^n 26^(n-1)       26  1
    //
    //  scan the string from highest digit to lowest digit
    //
    //  time complexity: O(n)
    //  space complexity: O(1)           
    int titleToNumber(string s) {
        int digit_weight = 26;
        
        int value = 0;
        for(int i = 0; i < s.size(); ++i) {
            value *= digit_weight;
            value += s[i] - 'A' + 1;
        }
        
        return value;
    }
};
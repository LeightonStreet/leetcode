/*
 * 344. Reverse String  
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * Given s = "hello", return "olleh".
 */


class Solution {
public:
    // helper function
    // swap two characters
    void swap_char(char& first, char& second) {
        char temp = first;
        first = second;
        second = temp;
    }
    
    // idea: use two indices to scan the string
    // p: from start to end
    // q: from end to start
    // swap the content of p and q
    // time complexity: O(n)
    // space complexity: O(1)
    string reverseString(string s) {
        int p = 0;
        int q = s.length() - 1;
        
        while((p < q) && (p < s.length()) && (q >= 0)) {
            if(s[p] != s[q])
                swap_char(s[p], s[q]);
            ++p;
            --q;
        }
        
        return s;
    }
};
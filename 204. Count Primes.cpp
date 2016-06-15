class Solution {
public:
    
    // idea: use a hashmap to represent the property of a number (prime or not)
    // brute force: n = m * p, find m and p -> O(N^2)
    // optimization: dynamic programming
    // start from m, find n
    // N/2 + N/3 + N/4 + ... + 1 -> O(NlgN)
    int countPrimes(int n) {
        // we will use hashmap[0] as a dummy element
        // 1 - is prime
        // 0 - not a prime
        int* hashmap = new int[n];
        for (int i = 0; i < n; i++) {
            hashmap[i] = 1;
        }
        
        hashmap[0] = hashmap[1] = 0;
        
        int current_checker = 2;
        int i;
        
        while (current_checker < n) {
            i = 2;
            while (i * current_checker < n) {
                hashmap[i * current_checker] = 0;
                i += 1;
            }
            current_checker += 1;
        }
        
        int result = 0;
        for (int j = 1; j < n; j ++) {
            if (hashmap[j]) {
                result += 1;
            }
        }
        
        return result;
    }
};
class Solution {
public:
    // idea: this is just a hash function to reindex all elements
    // method 1: shift all elements right (one step at a time) for k times
    //           time complexity: O(kn), space complexity: O(1)
    // method 2: store two parts of the array in two lists, and concatecate later
    //           time complexity: O(n), space complexity: O(n)
    // method 3: compute new index
    //           time complexity: O(n), space complexity: O(n)
    // method 3 is implemented here
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        
        if(size == 0) { // empty list, no need to do anything
            return;
        }
        
        if((k % size) == 0) { // no change
            return;
        }
        
        vector<int> results(nums);
        
        int index;
        
        for(index = 0; index < size; index++) {
            results[(index + k) % size] = nums[index];
        }
        
        nums = results;
        
    }
};
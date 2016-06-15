/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
*/


class Solution {
public:

    // idea: we can use a hashmap to record the frequency of an element
    //       use mostFrequentVal, mostFrequentCount to 
    //       keep track of most frequent value and its frequency
    int majorityElement(vector<int>& nums) {
        std::map<int, int>frequencyMap;
        int mostFrequentVal;
        int mostFrequentCount = 0;
        int val;
        
        int index = 0; // iterate through input vector
        while(index < nums.size()) {
            val = nums[index];
            if(frequencyMap.find(val) == frequencyMap.end()) { // insert new element
                frequencyMap[val] = 1;
            }
            else {
                ++frequencyMap[val];
            }
            if(frequencyMap[val] >= mostFrequentCount) { // update most frequent value
                mostFrequentVal = val;
                mostFrequentCount = frequencyMap[val];
            }
            ++index;
        }
        
        return mostFrequentVal;
    }
};
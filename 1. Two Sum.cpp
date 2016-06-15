class Solution {
public:
    // assumptions: target >= 0
    //              all elements are non-negative
    //              there must be a solution
    // idea: use a hashmap [0, target]
    // if (target - element) is not in hashmap, insert it
    // if (target - element) is in in hashmap, bingo
    // we need to keep track of index information, so use a map
    // time complexity: O(nlogn) (findING an element needs O(logn) time)
    // space complexity: O(target)
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> results;
        
        // by assumption, nums will not empty, has at leat two elements
        map<int, int>mymap;
        int paired_value;
        
        int index;
        for (index = 0; index < size; ++index) {
            paired_value = target - nums[index];
            if (mymap.find(paired_value) == mymap.end()) {
                mymap[nums[index]] = index;
            }
            else {
                results.push_back(mymap[paired_value]);
                results.push_back(index);
                return results;
            }
        }
        return results;

    }
};
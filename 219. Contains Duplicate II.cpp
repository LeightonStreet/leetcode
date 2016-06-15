/*
 * Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the (* difference between i and j is at most k.
*/

class Solution {
public:

    // idea: use a hash map to store val, pos
    //       when find same val, calulate diff(pos2, pos1)
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::map<int, int> valMap;
        int posDiff;
        int val;
        
        int index = 0;
        while(index < nums.size()) {
            val = nums[index];
            if(valMap.find(val) == valMap.end()) { // not occured before
                valMap[val] = index;
            }
            else { // occured before
                posDiff = index - valMap[val];
                if(posDiff <= k) { // close enough
                    return true;
                } 
                else { // not close enough
                    valMap[val] = index;
                }
            }
            ++index;
        }
    
        return false;
    }
};
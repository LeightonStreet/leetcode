class Solution {
public:
    // we can use a hashmap to keep track of occurace of numbers
    // we can use unsorted set as a hashmap
    // key methods: insert, find
    // insert(val): insert a value into unsorted set
    // find(val): return iterator. return end iterator if not found
    bool containsDuplicate(vector<int>& nums) {
        vector<int>::iterator array_iterator;
        unordered_set<int>exist_nums; // store numbers that have appeared
        
        for(array_iterator = nums.begin(); array_iterator != nums.end(); ++array_iterator) {
            if(exist_nums.find(*array_iterator) == exist_nums.end()) { // has not appeared before
                exist_nums.insert(*array_iterator);
            }
            else {
                return true; // duplication detected
            }
        }
        
        return false;
    }
};
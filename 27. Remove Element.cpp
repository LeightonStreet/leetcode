class Solution {
public:
    // brute force: whenever we delete an element, we move the remaining part ahead 1 step
    // optimization: use two pointers p1 and p2
    //               before p1: filtered elements
    //               after p2: discared elements
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        
        if(size == 0) {
            return size;
        }
        
        int front = 0;
        int back = size - 1;
        
        int swap_container;
        
        while ((front < size) && (back >= 0) && (front <= back)) {
            if(nums[front] == val) { // we need to remove this element
                // swap front and back
                swap_container = nums[front];
                nums[front] = nums[back];
                nums[back] = swap_container;
                --back;
            }
            else {
                ++front;
            }
        }
        
        return back + 1;
    }
};
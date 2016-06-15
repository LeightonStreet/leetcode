class Solution {
public:
    // idea: increase digit until there is no carry
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits);
        
        if (result.empty()) {
            return result;
        }
        
        bool has_carry = false;
        
        has_carry = result.back() / 9;
        result.back() = (result.back() + 1) % 10;
        
        int index = result.size() - 1 - 1;
        while (has_carry && (index >= 0)) {
            has_carry = result[index] / 9;
            result[index] = (result[index] + 1) % 10;
            //std::cout<<result[index]<<std::endl;
            --index;
        }
        
        if(has_carry && (index < 0)) { // we need to add a new digit
            result.insert(result.begin(), 1);
        }
        return result;
    }
};
    

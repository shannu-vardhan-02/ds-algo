class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int x : nums){
            if(++count[x] == 2)
                return true;
        }
        return false;
    }
};
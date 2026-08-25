class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, bool> visited;
        for(int x : nums){
            if(x % k == 0)
                visited[x] = true;
        }
        int i = k;
        while(1){
            if(!visited[i]) break;
            i += k;
        }
        return i;
    }
};
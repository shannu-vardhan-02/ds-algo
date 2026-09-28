class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int depth = 0, ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                depth++;
                ans = max(ans, depth);
            }
            if(s[i] == ')')
                depth--;
        }
        return ans;
    }
};
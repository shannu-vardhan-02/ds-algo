class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char c : word)
            freq[c - 'a']++;
        sort(freq.rbegin(), freq.rend());
        int ptr = 0;
        int ans = 0;
        while(ptr < 26){
            int mul = (ptr / 8) + 1;
            ans += (freq[ptr] * mul);
            ptr++;
        }
        return ans;
    }
};
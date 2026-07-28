class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count (26, 0);
        for(char c : s){
            count[c - 'a']++;
        }
        string oddOne = "";
        string ans = "";
        for(int i = 0; i < 26; i++){
            char cur = (char)('a' + i);
            if(count[i] % 2 != 0){
                oddOne += cur;
                count[i]--;
            }
            int temp = count[i] / 2;
            while(temp > 0){
                ans += cur;
                temp--;
            }
        }
        string no_rev = ans;
        reverse(ans.begin(), ans.end());
        ans = no_rev + oddOne + ans;
        return ans;
    }
};

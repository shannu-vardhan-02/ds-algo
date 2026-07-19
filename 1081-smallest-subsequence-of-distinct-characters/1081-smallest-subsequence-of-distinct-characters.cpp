class Solution {
public:
    string smallestSubsequence(string s) {
        // here we are implementing stack using string
        string st = ""; 
        vector<int> freq(26, 0);
        vector<bool> inStack(26, 0);

        for(char c : s){
            freq[c - 'a']++;
        }
        // if a smaller char can appear before a larger one that occurs again later, remove the larger char to obtain to lexicographically smaller subsequence
        for(char c : s){
            freq[c - 'a']--;
            if(inStack[c - 'a']) continue;
            while(!st.empty() && c < st.back() && freq[st.back() - 'a'] > 0){
                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(c);
            inStack[c - 'a'] = true;
        }
        
        return st;
    }
};
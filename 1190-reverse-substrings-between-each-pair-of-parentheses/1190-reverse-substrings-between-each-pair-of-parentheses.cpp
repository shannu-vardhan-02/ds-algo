class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> openParantheses;
        vector<int> pair(n);
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                openParantheses.push(i);
            if(s[i] == ')'){
                int j = openParantheses.top();
                pair[i] = j;
                pair[j] = i;
                openParantheses.pop();
            }
        }

        // direction = 1 -> forward and -1 -> backward
        string result = "";
        for(int currIdx = 0, direction = 1; currIdx < n; currIdx += direction){
            if(s[currIdx] == '(' || s[currIdx] == ')'){
                currIdx = pair[currIdx];
                direction = -direction;
            }
            else{
                result += s[currIdx];
            }
        }

        return result;
    }
};
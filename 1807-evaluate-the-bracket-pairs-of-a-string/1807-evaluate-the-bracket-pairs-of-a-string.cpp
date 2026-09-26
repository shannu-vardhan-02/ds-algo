class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;

        for(int i = 0; i < knowledge.size(); i++){
            map[knowledge[i][0]] = knowledge[i][1];
        }

        string ans = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                string str = "";
                i++;
                while(s[i] != ')'){
                    str += s[i++];
                }
                if(!map.contains(str)) ans += '?';
                else ans += map[str];
            }else{
                ans += s[i];
            }
        }

        return ans;
    }
};
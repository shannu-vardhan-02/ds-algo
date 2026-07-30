class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int k = n / 8;
        int r = n % 8;
        return (k + 1)*(4*k + r);
    }
};
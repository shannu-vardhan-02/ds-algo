class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        int INF = 1e9; // Large value to represent unvisited land
        
        // initialize the matrix
        vector<vector<int>> res(m, vector<int>(n, INF));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0; // Water cells must be 0
                }
            }
        }
        
        // Step 2: Forward Pass (Check Top and Left neighbors)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (res[i][j] != 0) { // Only process land cells
                    if (i > 0) res[i][j] = min(res[i][j], 1 + res[i - 1][j]);
                    if (j > 0) res[i][j] = min(res[i][j], 1 + res[i][j - 1]);
                }
            }
        }
        
        // Step 3: Backward Pass (Check Bottom and Right neighbors)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (res[i][j] != 0) { // Only process land cells
                    if (i < m - 1) res[i][j] = min(res[i][j], 1 + res[i + 1][j]);
                    if (j < n - 1) res[i][j] = min(res[i][j], 1 + res[i][j + 1]);
                }
            }
        }
        
        return res;
    }
};
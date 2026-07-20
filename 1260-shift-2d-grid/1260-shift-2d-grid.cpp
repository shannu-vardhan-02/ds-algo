class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
// our final answer is same as rotating 1d array k times in right direction and then filling elements back row-wise.
// do we need to convert 2d => 1d => rotate => refill values ??
// no, instead of doing physical rotation we will do index mapping.

// --------------------------------------------------------------------

        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;

        k %= total;

        // new ans matrix
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // before rotation index - 2d to 1d mapping
                int oldIndex = i * n + j;

                // after rotation index - 1d to 1d rotation mapping
                int newIndex = (oldIndex + k) % total;

                // 1d to 2d index mapping
                int newRow = newIndex / n;
                int newCol = newIndex % n;

                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};


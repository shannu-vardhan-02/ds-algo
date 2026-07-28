class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // find total land cells first
        int totalLand = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1)
                    totalLand++;
            }
        }

        // we store the land cells at boundaries in here
        stack<pair<int, int>> borderOnes;

        // Top and bottom rows
        for (int j = 0; j < n; j++){
            if (grid[0][j] == 1)
                borderOnes.push({0, j});
            if (m > 1 && grid[m - 1][j] == 1)
                borderOnes.push({m - 1, j});
        }

        // Left and right columns
        for (int i = 1; i < m - 1; i++){
            if (grid[i][0] == 1)
                borderOnes.push({i, 0});
            if (n > 1 && grid[i][n - 1] == 1)
                borderOnes.push({i, n - 1});
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // no of land cells that are connected to any boundary land
        int boundaryLand = 0;

        // for every boundary land traverse all the connected lands
        while (!borderOnes.empty()){
            auto [x, y] = borderOnes.top();
            borderOnes.pop();
            if (grid[x][y] != 1) continue;
            stack<pair<int, int>> st;
            st.push({x, y});
            // traverse all the connected land cells to the current 1
            while (!st.empty()){
                auto [cx, cy] = st.top();
                st.pop();
                if (grid[cx][cy] != 1) continue;
                grid[cx][cy] = 2; // mark 2 for visited land cells
                boundaryLand++;
                for (int k = 0; k < 4; k++){
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    grid[nx][ny] == 1)
                        st.push({nx, ny});
                }
            }
        }
        return totalLand - boundaryLand;
    }
};
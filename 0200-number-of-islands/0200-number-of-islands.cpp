class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
// traverse the matrix each cell
// found land cell -> islands++
//               | -> flood fill this land cell and mark all connected land 
//                    cells as water.
// ------------------------------------------------------------------
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        vector<int> dx = {-1, +1, 0, 0};
        vector<int> dy = {0, 0, -1, +1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        auto [cx, cy] = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int nx = cx + dx[k];
                            int ny = cy + dy[k];
                            if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1'){ 
                                q.push({nx, ny});
                                grid[nx][ny] = '0';
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};
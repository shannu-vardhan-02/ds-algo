class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total = 0; // total no of oranges
        queue<vector<int>> rotten; // queue containing only rotten oranges
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2)
                    rotten.push({i,j});
            }
        }
        
        // no fresh oranges or no oranges -> no need to rot
        if(total == rotten.size()) return 0; 

        if(rotten.size() == 0) return -1; // if no rotten oranges -> we cannot rot

        // Arrays to explore the 4 directions: right, left, down, up
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // min time to rot all oranges
        int time = 0;

        // total no of oranges that are rotten
        int rot_cnt = 0;

    
        while(!rotten.empty()){
            int k = rotten.size();
            rot_cnt += k;
            // process only these k rotten oranges
            // traverse and rot oranges in 4 directions for these k already rotten oranges
            while(k--){
                vector<int> curr = rotten.front();
                int x = curr[0];
                int y = curr[1];
                rotten.pop();
                // now rot every orange in 4 directions
                for(int i = 0; i < 4; i++){
                    // (nx, ny) -> new cordinates in one of 4 direction
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    // skip if orange is already rotten or no orange OR cordinates error
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2; // mark the neighbor orange rotten
                    rotten.push({nx, ny}); // add this rotten neighbor to rotten queue
                }
            }
            // time++ only if new oranges are rotten
            if(!rotten.empty()){
                time++;
            }
        }
        // return if all oranges are rotten
        return (rot_cnt == total) ? time : -1;
    }
};
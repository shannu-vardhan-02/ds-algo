class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // mark all the o's that have a way to the boundaries to "V"
        // let V = visited
        // and mark every cell other than B to X and B to O.

        // flood fill the boundary elements with B.
        int m = board.size();
        int n = board[0].size();
        stack<pair<int, int>> edge_o;

        // left and right most O's
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') edge_o.push({i, 0});
            if(board[i][n - 1] == 'O') edge_o.push({i, n - 1});
        }
        // top and bottom most O's
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O') edge_o.push({0, j});
            if(board[m - 1][j] == 'O') edge_o.push({m - 1, j});
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // for every O at the boundary traverse all the connected O's to it using BFS or DFS and mark them as V. I will do DFS
        while(!edge_o.empty()){
            auto [x, y] = edge_o.top();
            edge_o.pop();
            if(board[x][y] == 'V') continue;
            stack<pair<int, int>> s;
            s.push({x, y});
            while(!s.empty()){
                auto [cx, cy] = s.top();
                s.pop();
                if(board[cx][cy] == 'V') continue;
                board[cx][cy] = 'V';
                for(int k = 0; k < 4; k++){
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && board[nx][ny] == 'O')
                        s.push({nx, ny});
                }
            }
        }

        // now mark all the cells other then V's as X
        // and all the V's to O's
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
            }
        }

        return;
    }
};
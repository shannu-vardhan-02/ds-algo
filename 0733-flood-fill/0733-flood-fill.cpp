class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int startpx = image[sr][sc];

        if(startpx == color) return image;

        image[sr][sc] = color;

        // dir = right left top bottom = adjacent pixels
        vector<int> dx = {+1, -1, 0, 0};
        vector<int> dy = {0, 0, +1, -1};

        stack<vector<int>> s;
        s.push({sr, sc});

        // bfs starts here
        while(!s.empty()){
            int x = s.top()[0];
            int y = s.top()[1];
            s.pop();
            // do bfs for adjacent pixels if condition is true
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n || image[nx][ny] != startpx){
                    continue;
                }

                s.push({nx, ny});
                image[nx][ny] = color;
            }
        }
        return image;
    }
};
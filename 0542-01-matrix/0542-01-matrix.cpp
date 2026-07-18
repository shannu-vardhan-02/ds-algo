class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // DP Solution - O(m*n) sc = O(1) res array
        // BFS Solution - O(m*n) SC = O(m*n)

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> res(m, vector<int>(n, 1e4));

        // compare the min dist to zero of left and top cells
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) res[i][j] = 0;
                else{
                    if(i > 0)
                        res[i][j] = min(res[i][j], 1 + res[i - 1][j]);
                    if(j > 0)
                        res[i][j] = min(res[i][j], 1 + res[i][j - 1]);
                }
            }
        }

        //compare the min dist to curr cell, right, down
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(mat[i][j] != 0){
                    if(i < m - 1)
                        res[i][j] = min(res[i][j], 1 + res[i + 1][j]);
                    if(j < n - 1)
                        res[i][j] = min(res[i][j], 1 + res[i][j + 1]);
                }
            }
        }

        return res;
    }
};
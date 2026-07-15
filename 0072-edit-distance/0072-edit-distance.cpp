class Solution {
public:
    int minDistance(string word1, string word2) {
        // KEEP THE EDITOR IN FULL WIDTH - TO READ PROPERLY

        // // For any DP problem ,first cumpulsory thing is we need to think the recursive top down approach to get to the bottom up approach.
        // // After the recursive approach we reduce re-solving the subproblems by saving them into memory --> MEMOIZATION (top-down)
        // // DP - Tabulization (bottom-up)
        // int m = word1.size() + 1;
        // int n = word2.size() + 1;
        // vector<vector<int>> dp(m, vector<int> (n, 0));
        // // base cases - (empty str to any str) - (any str to empty str)
        // for(int i = 0; i < m; i++){
        //     dp[i][0] = i;
        // }
        // for(int j = 0; j < n; j++){
        //     dp[0][j] = j;
        // }
        // // DP Logic - doing an operation leads to a subproblem that is already solved.
        // // ex - (CAT, CUT) - T==T - (CA, CU) --- A!=U => ---- insert (CA -> CAU) -- (CAU, CU) -- U==U -- (CA,C) {This is a subproblem} --- get here costs some. 
        // //                                              |---- delete (CA -> C) ---- (C, CU) {This is a subproblem}
        // //                                              |---- replace (CA -> CU) -- (CU, CU) -- U==u -- (C,C) {This is a subproblem}
        // // So we have to get to the subproblems state to make an operation on the current state. So each operation has respective subproblems. And we take the,
        // // subproblem that needs minimum operation.
        // // DRAW THE DP TABLE TO MAKE THINGS CLEAR 
        // for(int i = 1; i < m; i++){
        //     for(int j = 1; j < n; j++){
        //         if(word1[i - 1] == word2[j - 1]){
        //             dp[i][j] = dp[i - 1][j - 1];
        //         }else{
        //             dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
        //         }
        //     }
        // }
        // return dp[m - 1][n - 1];

        // // we can still reduce the space complexity, because we just need the right three neighbours of the current cell. So, we can keep an array and keep on overwriting it.

        // O(n) - Space Complexity
        int m = word1.size() + 1;
        int n = word2.size() + 1;
        vector<int> dp_arr(n, 0);
        for(int j = 0; j < n; j++){
            dp_arr[j] = j;
        }
        for(int i = 1; i < m; i++){
            int dia = dp_arr[0];
            dp_arr[0] = i;
            for(int j = 1; j < n; j++){
                int temp = dp_arr[j];
                if(word1[i - 1] == word2[j - 1])
                    dp_arr[j] = dia;
                else
                    dp_arr[j] = 1 + min({dp_arr[j - 1], dia, dp_arr[j]});
                dia = temp;
            }
        }
        return dp_arr[n - 1];
        // dp_arr[j-1]: The value we just computed (Left).
        // dp_arr[j]: The value from the previous row (Top).
        // dia: The value from the previous row and previous column (Diagonal).
    }
};
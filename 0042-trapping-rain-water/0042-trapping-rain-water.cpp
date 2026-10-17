class Solution{
public:
    int trap(vector<int> &height){
        int n = height.size();
        int l_wall = 0;
        int r_wall = 0;
        vector<int> maxL(n, 0);
        vector<int> maxR(n, 0);
        for(int i = 0; i < n; i++){
            int r = n - i - 1;
            maxL[i] = l_wall;
            maxR[r] = r_wall;
            l_wall = max(height[i], l_wall);
            r_wall = max(height[r], r_wall);
        }

        int water = 0;
        for(int i = 0; i < n; i++){
            int pot = min(maxL[i], maxR[i]);
            water += max(0, pot - height[i]);
        }
        return water;
    }
};
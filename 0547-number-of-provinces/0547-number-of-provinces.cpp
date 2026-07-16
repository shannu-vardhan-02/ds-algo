class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // no of nodes
        vector<bool> visited(n); // visited nodes
        int provinces = 0; // no of provinces
        // check every node in visited
        for(int i = 0; i < n; i++){ 
            if(!visited[i]){ // first visit means - new province 
                provinces++;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                // bfs - queue
                // traverse all the nodes in the current province
                while(!q.empty()){ // mark all nodes visited
                    int node = q.front();
                    q.pop();
                    // nbr = neighbor
                    for(int nbr = 0; nbr < n; nbr++){
                        // push only if not visited
                        if(isConnected[node][nbr] && !visited[nbr]){
                            q.push(nbr);
                            visited[nbr] = true;
                        }
                    }
                }
            }
        }
        return provinces;
    }
};
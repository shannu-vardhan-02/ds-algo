class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Quick exit if source is already the destination
        if (source == destination) return true;

        // Build adjacency list using vector instead of map for O(1) direct access
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Use a boolean vector for O(1) visited checks
        vector<bool> visited(n, false);
        queue<int> q;

        // Initialize BFS
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Traverse all neighbors of the current node
            for (int neighbor : graph[curr]) {
                if (neighbor == destination) return true; // Found path!

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false; // No path found
    }
};
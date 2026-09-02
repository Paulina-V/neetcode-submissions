class Solution {
public:
    unordered_set<int> visited;
    unordered_map<int, unordered_set<int>> adjList;
    unordered_set<int> currPath;
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        for (auto& p : edges) {
            int n1 = p[0];
            int n2 = p[1];
            adjList[n1].insert(n2);
            adjList[n2].insert(n1);
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited.contains(i)) {
                if (!dfs(i, -1)) return false;
            }
        }
        return visited.size() == n;
    }
    bool dfs(int node, int parent) {
        if (visited.contains(node)) return false; // it's a cycle cuz we've seen it before
        visited.insert(node);
        for (int adjNode : adjList[node]) {
            if (adjNode == parent) continue;
            if (dfs(adjNode, node) == false) return false;
        }
        return true;
    }
};

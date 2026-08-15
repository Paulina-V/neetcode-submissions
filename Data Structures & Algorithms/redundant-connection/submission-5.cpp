class Solution {
public:
    unordered_map<int, unordered_set<int>> adjList;
    unordered_set<int> visited;
    unordered_set<int> cycleNodes;
    int cycleStartNode = -1;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (vector<int>& e : edges) {
            adjList[e[0]].insert(e[1]);
            adjList[e[1]].insert(e[0]);
        }
        dfsToFindCycleNodes(edges[0][0], 0);

        for (int i = edges.size() - 1; i >= 0; i--) {
            int n0 = edges[i][0];
            int n1 = edges[i][1];
            if (cycleNodes.contains(n0) && cycleNodes.contains(n1)) {
                return {n0, n1};
            }
        }
        return {};
    }

    bool dfsToFindCycleNodes(int node, int parent) {
        if (visited.contains(node)) {
            cycleStartNode = node;
            cycleNodes.insert(node);
            return true;
        }
        visited.insert(node);

        for (int nextNode : adjList[node]) {
            if (nextNode == parent) continue;
            if (dfsToFindCycleNodes(nextNode, node)) {
                if (node != cycleStartNode) {
                    cycleNodes.insert(node);
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }
};
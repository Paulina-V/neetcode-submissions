class Solution {
public:
    unordered_map<int, unordered_set<int>> adjList;
    unordered_set<int> visited; // visited in this group
    int groupCount = 0;

    int countComponents(int n, vector<vector<int>>& edges) {
        // build the adjacency list of who's neighbors with whom
        for (vector<int> e : edges) {
            adjList[e[0]].insert(e[1]);
            adjList[e[1]].insert(e[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!visited.contains(i)) {
                groupCount++;
                dfs(i);
            }
        }
        return groupCount;
    }

    void dfs(int node) {
        cout << "node:" << node << " groupCount: " << groupCount << "\n";
        if (visited.contains(node)) return; 
        visited.insert(node);
        for (auto& neighbor: adjList[node]) {
            cout << "called dfs inside";
            dfs(neighbor);
        }
    }
    
};
 
// ----- plan -----

/*

    1. turn the list of edges into an adjacency list
    2. loop through all of the nodes from 0 to n - 1 
        a. check if it's already in the set of visited nodes in the current connected comp
            the goal is to get a list of all the nodes that are in the current connected comp
                i. if not --> add it and dfs from here 
                ii. if yes --> don't go there
            once we have seen all the nodes in this connected comp, groupCt++
                i. if yes --> return groups
                ii. if not --> the little dfs loop should end and we continue with the big loop 
                               called in countComponents to do more dfs

*/

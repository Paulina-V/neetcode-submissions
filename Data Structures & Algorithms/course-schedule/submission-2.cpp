class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> visitSet;
        vector<vector<int>> adjList(numCourses);

        for (auto& p : prerequisites) {
            adjList[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs (i, adjList, visitSet)) return false;
        }

        return true;
    }
    bool dfs(int crs, vector<vector<int>>& adjList, unordered_set<int>& visitSet) {
        if (visitSet.contains(crs)) return false;
        if (adjList[crs].size() == 0) return true;

        visitSet.insert(crs);
        for (int pre : adjList[crs]) {
            if (!dfs (pre, adjList, visitSet)) return false;
        }
        visitSet.erase(crs);
        adjList[crs].clear();

        return true;
    }
 };

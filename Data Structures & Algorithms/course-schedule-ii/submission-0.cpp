class Solution {
public:
    vector<int> ret;
    unordered_set<int> currPath;
    unordered_set<int> visited;
    unordered_map<int, unordered_set<int>> adjList;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto& p : prerequisites) {
            int c = p[0];
            int creq = p[1];
            adjList[c].insert(creq);
        }
       
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return {};
            }
        }
    
        return ret;
    }
    
    bool dfs(int course) {
        if (visited.contains(course)) return true;      // already done, skip
        if (currPath.contains(course)) return false;    // cycle!

        currPath.insert(course);
        for (int req : adjList[course]) {
            if (!dfs(req)) return false;
        }
        currPath.erase(course);       // done with this call, no longer "in progress"

        visited.insert(course);       // mark permanently done
        ret.push_back(course);        // safe to add now — all its deps are already in ret
        return true;
    }
};

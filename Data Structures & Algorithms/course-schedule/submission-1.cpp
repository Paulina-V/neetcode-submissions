class Solution {
public:
    unordered_set<int> path;
    unordered_map<int, unordered_set<int>> allCourses;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            allCourses[course].insert(prereq);
        }
        
        for (auto const& [course, prereqs] : allCourses) {
            if (dfs(course) == false) {
                return false;
            }
        }
        return true;
    }
    
    bool dfs(int course) {
        if (path.contains(course)) { 
            return false; 
        }
        if (allCourses[course].empty()) {
            return true;
        }
        path.insert(course);

        for (int prereq : allCourses[course]) {
            if(dfs(prereq) == false) {
                return false;
            }
        }
        path.erase(course);
        allCourses[course].clear();
        return true;
    }
};


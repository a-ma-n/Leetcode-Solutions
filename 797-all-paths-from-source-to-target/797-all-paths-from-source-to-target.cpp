class Solution {
public:
    // set few clas variables so as to not pass them down in recursive calls
    int target;
    vector<vector<int>> res;
    vector<int> tmp;
    
    void dfs(vector<vector<int>>& graph ,int currNode = 0){
        // updating temp
        tmp.push_back(currNode);
        // and either updating the res with target if thetarget is met
        if(currNode==target) res.push_back(tmp);
        // or calling dfs again recursively
        else for(int node : graph[currNode]){
            dfs(graph,node);
        }
        // backtracking with tmp
        tmp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target= graph.size()-1;
        dfs(graph);
        return res;
    }
};
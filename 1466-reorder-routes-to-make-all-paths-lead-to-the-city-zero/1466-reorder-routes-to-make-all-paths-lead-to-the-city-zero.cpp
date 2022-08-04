class Solution {
public:
    // what we are doing is eventually => traversing from 0 to other adjacent cities and then 
    // if we can reach that city from 0 means that we cannot go back to the same destination as there is only q route to go back, and each node has only 1 edge , so we reverse that edge
    // start from city 0 and push all the adjacent element in que and increment the ans var, then return var
    
    // BFS aproach 
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> visited(n);
        vector<vector<int>> adj(n),back(n);
        queue<int> q;
        q.push(0);
        int ans = 0;
        // storing adj and back connections
        for(auto c: connections){
               adj[c[0]].push_back(c[1]);
               back[c[1]].push_back(c[0]);
        }
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            visited[curr]=1;
            
            // change dir for all arrows facing out
            for(auto a:adj[curr]){
                if(!visited[a]){
                    ans++;
                    q.push(a);
                }
            }
            
            // push other nodes so we visit everything
            for(auto b:back[curr]){
                if(!visited[b]) q.push(b);
            }
        }
        return ans;        
    }
};
class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        int n = num;
        vector<vector<int>> adj(num);
        vector<int> deg(num),order;
        
        for(auto x: pre){
            adj[x[1]].push_back(x[0]);
            deg[x[0]]++;
        }
        queue<int> q;
        for(int i =0;i < n ;i ++)
            if(deg[i]==0) q.push(i);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            order.push_back(f);
            n--;
            for(auto v: adj[f]){
                if(--deg[v] == 0) q.push(v);        
            }
        }
        if(n!=0) return{};
        return order;
    }
};
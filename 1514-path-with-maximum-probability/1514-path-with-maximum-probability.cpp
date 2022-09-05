/*
https://leetcode.com/problems/path-with-maximum-probability/discuss/731706/C%2B%2B-Modified-Djikstra-O(edges-*-log(n))-or-Max-Heap-or-Explanations
*/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int start, int end) {
        
        // graph with nodes and respective probability
        vector<vector<pair<int, double>>> g(n);
        
        // making bidirectional edges with cost
        
        for(int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], pro[i]});
            g[edges[i][1]].push_back({edges[i][0], pro[i]});   
        }
        // visited array
        vector<int> seen(n, 0);
        
        // priority queue to store the value of the (probability,node) 
        // we storet the max probability in the queue  
        priority_queue<pair<double, int>> q;
        
        // probability of self edge is 
        // eg1: <1.0,0> 
        q.push({(double)1.0, start});
        
        // vector to store the max probability
        // ??
        vector<double> mx(n, (double)0.0);
        
        // starting node has prob of 1 to reach itself
        mx[start] = 1.0;
        
        
        while(!q.empty()){
            
            auto top = q.top();
            q.pop();
            
            double proba = top.first;
            int node = top.second;
            
            // if node is not visited 
            if(!seen[node]){
                // mark visited
                seen[node]++;
                
                // exploring its neighbours (greedy property)
                /*
                process the pairs at that index, which are related to the node
                0-[ [<>,<>,<>],
                1-  [<>,<>,<>],
                2-  [<>,<>,<>] ]
                
                
                eg1:
                0-[ [<1,0.5>,<2,0.2>],
                1-  [<0,0.5>,<2,0.2>],
                2-  [<0,0.2>,<1,0.5>] ]
                
                */
                
                
                //  0-[ [<1,0.5>,<2,0.2>],
                for(auto &to: g[node]){
                    
                    // if max prob of reaching that. node is less than the prob we get by multiplying thre curent probability "proba" (i.e. probability it took to come here) with to.seconds probability
                    
                    // mx[1] ~ would give max probability to reach 1
                    // mx[2] ~ gives max prob to reach 2
                    if(mx[to.first]<to.second*proba){
                        // we update the max probability
                        mx[to.first] = to.second*proba;
                        // push the node with max probability that it took tp reach into the queue
                        // pushes <0.5,1>,<0.2,2> to the queue
                        
                        // we are pushing the max prob to reach that node along with the node 
                        q.push({mx[to.first],to.first});
                    }
                }
            }
        }
        // basically we are returning the max prob to reach the end node which was stored in our mx vector
        return mx[end];
    }
};
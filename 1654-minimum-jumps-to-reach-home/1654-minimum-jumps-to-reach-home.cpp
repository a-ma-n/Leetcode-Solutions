// Here We are Using BFS Since every time there can be neighbours 
// at evry step (consider neighbours here as moving forward and backward position (if possible)).
// So here we apply simple bfs traversal. 
// We are keeping track of backward movement by queue second value i.e. -1 
// here since here no consecutive backward movement is allowed.
// Map is used so that if we some point again then simply return because that point is already under process in queue (it just like visited array in out normal dfs/bfs). 

class Solution {
public:
    int minimumJumps(vector<int>& nums, int a, int b, int x) {
        queue<pair<int,int>> q;
        map<int,bool>seen;
        
        for( int i = 0 ; i < nums.size() ;  i++ ){
            seen[nums[i]] = true;
        }
        q.push({0,-1});
        int lvl = -1;
        while(!q.empty()){
            lvl++;
            int sz = q.size();
            while(sz--){
                int node = q.front().first;
                int val = q.front().second;
                q.pop();
                   
                if(node == x){
                        return lvl;
                    }
                   
                if(seen[node]){
                        continue;
                    }
            
                seen[node]=true;
                
                if(val==-1){
                    
                    int k = a+node;
                    if(node<=2000+b){
                        q.push({k,0});
                    }
                }
                else if(val==0){
                    int k1= a + node;
                    int k2= node - b;
                    if(k2>=0){
                        q.push({k2,-1});
                    }
                    if(node<=2000+b){
                        q.push({k1,0});
                    }
                }
            }
        }
        return -1;
    }
};
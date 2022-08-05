// Here We are Using BFS Since every time there can be neighbours 
// at every step (consider neighbours here as moving forward and backward position (if possible)).
// So here we apply simple bfs traversal. 

// We are keeping track of backward movement by queue second value i.e. -1 
// here since here no consecutive backward movement is allowed.

// Map is used so that if we some point again then simply return because that point is already under process in queue (it just like visited array in out normal dfs/bfs). 

class Solution {
public:
    int minimumJumps(vector<int>& nums, int a, int b, int x) {
        queue<pair<int,int>> q;
        map<int,bool>seen;
        
        // mark forbidden values as seen 
        for( int i = 0 ; i < nums.size() ;  i++ ){
            seen[nums[i]] = true;
        }
        
        // first  => current index
        // second => track of backward movement : 0=>we can move backward, -1 means we cannot move backward(we already moved back in previous turn)
        // we dont allow it to go backward?? => NO as it mentions in the comment we cannot go to negative integer indexes
        q.push({0,-1});
        
        int lvl = -1;
        
        while(!q.empty()){
            
            // increment the level
            lvl++;
            int sz = q.size();
            
            // process all the elements that were in the queue (not the elements that are being added now)
            while(sz--){
                int node = q.front().first;
                int val = q.front().second;
                q.pop();
                   
                // we reached the target position
                if(node == x){
                        return lvl;
                    }
                   
                //if this is a forbidden node/ or a visited node
                if(seen[node]){
                        continue;
                    }
            
                // mark current node as visited 
                seen[node]=true;
                
                //we already made a backward step in the previous iteration
                if(val==-1){
                    
                    // move forward by a units
                    int k = a+node;
                    
                    // 2000+b => is taken as it will be the max amount we can go as , if we go to this location and then take b steps back we reach x
                    if(node<=2000+b){
                        q.push({k,0});
                    }
                    
                }
               //we made a forward step in the previous iteration

                else if(val==0){
                    int k1= a + node;
                    int k2= node - b;
                    
                    // condition given in the question to not move to negative indexes
                    if(k2>=0){
                        q.push({k2,-1});
                    }
                    // if we are able to reach an index less than 2000+b we can explore it once, as we might go to xmax+b , if say b=2000 & x=2000 & a =2000 then to reach x we need to come back from x+b backward by moving a once(as we cant move backward twice)
                    if(node<=2000+b){
                        q.push({k1,0});
                    }
                }
            }
        }
        // if we did not reach the target position
        return -1;
    }
};
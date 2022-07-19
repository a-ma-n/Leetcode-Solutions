class Solution {
public:
    // return -1 if it is not reachable
    int jump(vector<int>& nums) {
    
    int n=nums.size();
    
    if(n<=1) return 0;
    
    //if(nums[0]==0) return -1;
    
    // j stores the max steps 
    // 
    int maxr=nums[0], steps=nums[0], j=1;
    
    for(int i=1;i<n;i++){
        
        
        if(i==n-1){
            return j;
        }
        
        // find the max possible jump => ( i + nums[i] ) i, the previous one or this is bigger , store that
        maxr = max(maxr, i+nums[i]);
        steps--;
        
        // if steps == 0 then increment the value of j => we need another step to move toward our goal
        if(steps==0){
            
            j++;
            //if i is greater than max possible jump => not reachable
            if(i>=maxr){
                return -1;
            }
            // steps is the value we can move possibly move
            steps=maxr-i;
        }
    }
    return 0;
}
};
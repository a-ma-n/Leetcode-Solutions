class Solution {
public:
    // x
    // x numbers >=x
    // binary search:
    // [1,2,2]
    // [1,3,3,4]
    
    int specialArray(vector<int>& nums) {
       int low = 0;
       int high = nums.size();
       int mid;
        // nlogn solutio
        // restated problem: find a number mid such that , there are mid number greater than equal to mid in the array
        // thus we do a binary saerch on the array [1->n] 
        
        while(low<=high){
            mid = low +(high-low)/2;
            cout<<low<<" "<<mid<<" "<<high<<endl;
            
            int count = 0;
            for(auto it: nums) if(it>=mid) count++;
            if(count==mid) return mid;
            else if(count<mid) high = mid-1;
            else low = mid+1;
        }
        return -1;
        
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            
            // remove the out of bound indexes
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();
            
            // pop all the elements smaller than the current element, as we are 
            // storing the elements in a decreasing fashion, hence we start from
            // the back of the dequeue.
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            // store the element in the dequeue
            dq.push_back(i);
            // store subarray maximum
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
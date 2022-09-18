class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while(left<right){ // till we reach the middle (or any point between the outer 2 limits)
            if(height[left] < height[right]){
                // while height of left is less than right height, store the max left height and store the trapped rainwater
                height[left]>=left_max?(left_max = height[left])  : ans+=(left_max-height[left]);
                // keep moving left index
                ++left;
            }
            else{
                //
                height[right]>=right_max?(right_max = height[right]) : ans += (right_max-height[right]);
                // move the right index backwards
                --right;
            }
        }
        return ans;
    }
};
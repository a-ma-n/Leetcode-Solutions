class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int a1 = 0, b1 = nums[0], a2 = 0, b2 = 0, temp1, temp2;
        for(int i = 2 ; i <= n ; i++){
            if(i != n) {
                temp1 = b1;
                b1 = max(a1 + nums[i-1], b1);
                a1 = temp1;
            }
            temp2 = b2;
            b2 = max(a2 + nums[i-1], b2);
            a2 = temp2;
        }  
        return max(b1, b2);
    }
};
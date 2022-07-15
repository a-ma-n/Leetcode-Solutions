class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod1 = nums[0],prod2 = nums[0],result = nums[0];   
        for(int i = 1;i<nums.size();i++){
            // we multiply with nums sp -ive x -ive => possibly a big element
            int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
            
            // store min val , preferably negative
            prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
            //we store the max in prod1
            prod1 = temp;
            //find the max of previous result and prod1
            result = max(result,temp);
            cout<<"temp "<<"prod2 "<<"prod1 "<<"result"<<endl;
            cout<<temp<<prod2<<" "<<prod1<<" "<<result<<endl;
        }
        return result;
    }
};
/*

temp prod2 prod1 result
12   -3      12   12
temp prod2 prod1 result
6   -24      6   12


temp prod2 prod1 result
    -36     12  12
temp prod2 prod1 result
    -144    72   72
    
=> if we take prod1 then it interferes with prod2
*/
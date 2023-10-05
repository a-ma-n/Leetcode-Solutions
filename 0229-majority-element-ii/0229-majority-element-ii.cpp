class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,n1=nums[0],n2=nums[0];
        int n_by3 = nums.size()/3;
        vector<int> v;
        
        for(auto it:nums){
            // else ifs prevent c1 and c2 to store the same value
            if(it==n1)
                c1++;
            else if(it==n2)
                c2++;
            else if(c1==0)
            {
                n1=it;
                c1=1;
            }
            else if(c2==0)
            {
                n2=it;
                c2=1;
            }
            else{
                c1--;
                c2--; 
            }
               
        }
        // cout<<"n1:"<<n1<<"\tn2:"<<n2<<endl<<"nby3:"<<n_by3<<endl;
        
        c1=0;
        c2=0;
        for(auto it:nums){
            if(it==n1)
                c1++;
            if(it==n2)
                c2++;
        }
        cout<<"c1:"<<c1<<"\tc2:"<<c2<<endl;
        
        if(c1>n_by3)
            v.push_back(n1);
        if(c2>n_by3 && n1!=n2)
            v.push_back(n2);
        
        return v;
    }
};
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        //vector<int> diff;
        long long avg,i,j,s1=0,s2=0,n1,n2,n=nums.size(),min=0,pos=0,sum=0,val1=0,val2=0,diff=0;
        for(i=0;i<n;i++){
            sum+=nums[i];
        }
        //cout<<sum<<endl;
        //diff.resize(n);
        for(i=0;i<n;i++){
            avg=0;
            s1+=nums[i];
            n1=i+1;
            //n2=n-i-1;
            val1=floor(s1/n1);
            s2=sum-s1;
            n2=n-1-i;
            if(n2!=0)
            {   
                val2=floor(s2/n2);
                diff=abs(val1-val2);
                if(i==0)
                    min=diff;
            }
            else{
                diff=abs(val1);
                cout<<"\ndiff:"<<diff<<endl;
            }
            if(min>diff){
                min = diff;
                pos=i;
            }            
            //cout<<"i: "<<i<<" s1:"<<s1<<" s2:"<<s2<<" n1:"<<n1<<" n2:"<<n2<<" val1:"<<val1<<" val2:"<<val2<<" diff "<<diff[i]<<endl;
        }
        return pos;
    }
};
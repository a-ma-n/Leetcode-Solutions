class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
        
        int left = 0 , right= 0;
        int n = s.size();
        int len=0;
        while(right<n){
            if(mpp[s[right]] != -1) // if it does exist
                left=max(mpp[s[right]]+1,left);
            
            mpp[s[right]] = right;
            
            len = max(len,right - left + 1);
            right++;
        }
        return len;
    }
};
//    vector < int > mpp(256, -1);

//       int left = 0, right = 0;
//       int n = s.size();
//       int len = 0;
//       while (right < n) {
//         if (mpp[s[right]] != -1)
//           left = max(mpp[s[right]] + 1, left);

//         mpp[s[right]] = right;

//         len = max(len, right - left + 1);
//         right++;
//       }
//       return len;
//     }


//         map<int,int> mpp;
        
//         int l=0,r=0,maxLength=0,i,length=0;
        
//         for(;r<s.length();r++){
            
//             if(mpp.find(s[r])==mpp.end()){//element not present
//                 mpp[s[r]]=i;
//                 cout<<"r:"<<r<<endl;
//                 length++;
//                 maxLength=max(maxLength,length);
//             }
//             else{//element present
                
//                 l=mpp[s[r]]+1;
//                 length=0;
//                 mpp[s[r]]=l;
//                 cout<<"l:"<<l<<endl;
//             }
            
//         }
//         return maxLength;
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    struct meeting{
        int start;
        int end;
        int pos;
    };
    // how can we write the
    // struct in the parameters of the
    // function like this?
    
    bool static comparator(struct meeting m1, meeting m2){
        if(m1.end<m2.end)
            return true;
        else if(m1.end>m2.end)
            return false;
        else if(m1.pos<m2.pos)
            return true;
        // m1.pos > m2.pos
        return false;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int s[], int e[], int n)
    {
        // Your code here
        struct meeting meet[n];
        int i=0;
        
        for( i=0;i<n;i++)
        {
            meet[i].start=s[i];
            meet[i].end=e[i];
            meet[i].pos=i;
        }
        
        sort(meet,meet+n,comparator);
        
        vector<int> answer;
        
        // end limit
        int limit=meet[0].end;
        
        answer.push_back(meet[0].pos);
        
        for( i=0;i<n;i++){
            if(meet[i].start>limit){
                limit = meet[i].end;
                answer.push_back(meet[i].pos);
            }
        }
        return answer.size();
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
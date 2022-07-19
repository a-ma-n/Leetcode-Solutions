class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string> q;
      
        //hashset
        set<string> st,words;
        
        // convert to a set
        for(auto it:wordList)
            words.insert(it);
        
        q.push(beginWord);
        st.insert(beginWord);
        
        q.push(beginWord);
        int res=0; // stores the count of the changes
        
        while(q.size()){
            int n = q.size();
            res++;
            for(int i =0;i<n;i++){
                string s = q.front();
                if(s==endWord)
                    return res;
                q.pop();
                string t;
                for(int i =0; i<s.size() ; i++){
                    t=s;
                    for( int j = 'a' ; j<='z' ; j++ ){
                        t[i]=j;
                        if(words.count(t) && !st.count(t) ){
                            q.push(t);
                            st.insert(t);
                        }
                    }
                }
            }
        }
    // we could not find any path
    return 0;    
        
    }
};
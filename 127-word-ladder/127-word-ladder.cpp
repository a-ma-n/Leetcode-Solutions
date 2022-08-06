class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // queue to do bfs with the word list
        queue<string> q;
      
        //visited and wordlist
        // visited set to keep track of already visited nodes (as we are also popping some elements from the queue)
        set<string> visited,words;
        
        // convert to a set
        for(auto it:wordList)
            words.insert(it);
        
        q.push(beginWord);
        visited.insert(beginWord);
        
        q.push(beginWord);
        int changes=0; // stores the count of the changes
        
        while(q.size()){
            int n = q.size();
            // increment the changes variable
            changes++;
            
            for(int i =0;i<n;i++){
                // bfs using the queue
                string s = q.front();
                
                // if wefound the word in the queue
                if(s==endWord)
                    return changes;
                
                q.pop();
                
                string t;
                
                // trying out variations at different positions
                for(int i =0; i<s.size() ; i++){
                    t=s;
                    // trying out variations a-z at that place
                    for( int j = 'a' ; j<='z' ; j++ ){
                        
                        t[i]=j;
                        
                        if(words.count(t) && !visited.count(t) ){
                            // if in the wordList and not in the visited list
                            
                            // push variations in the queue & visited node
                            q.push(t);
                            
                            visited.insert(t);
                        }
                    }
                }
            }
        }
    // we could not find any path
    return 0;    
        
    }
};
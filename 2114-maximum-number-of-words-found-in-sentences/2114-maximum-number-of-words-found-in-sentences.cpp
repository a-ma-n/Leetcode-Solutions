class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
     
        char ch=' ';
        int spaceCount=0,maxWordCount=0;
        // max word count = max space count
        for(auto sent:sentences){
            spaceCount=0;
            sent=sent+" ";
            for(int i=0;i<sent.length();i++){
                if(sent[i]==' ')
                    spaceCount++;
            }
            if(maxWordCount<spaceCount){
                maxWordCount=spaceCount;
            }
        }
        return maxWordCount;
    }
};
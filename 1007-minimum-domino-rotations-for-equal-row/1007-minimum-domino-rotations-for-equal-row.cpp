class Solution {
public:
    
    int dominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        int minRotation = INT_MAX;
        for(int i = 1; i <= 6; ++i)
        {
            int swap = 0 , j;
            for(j = 0; j<tops.size(); ++j)
                {
                    if(tops[j] == i)
                        continue;
                    else if(bottoms[j] == i)
                        ++swap;
                    else
                        break;
                }
                
                // if we reach at the end of vector && minRotation > swap
                if(j == tops.size() && minRotation > swap)
                    minRotation = swap;
        }
        return minRotation == INT_MAX ? -1 : minRotation;
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        // try to make all tops faces same
        int ab = dominoRotations(tops,bottoms);
        
        // try to make all tops faces same
        int ba = dominoRotations(bottoms,tops);
        
        return ab == -1 ? ba : ba == -1 ? ab : min(ab,ba);
    }
};
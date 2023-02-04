from functools import cache

class Solution:
    def isMatch(self, s2: str, s1: str) -> bool:
        def isAllStars(s1,idx):
            for i in range(idx+1):
                if s1[i]!='*':
                    return False
            return True
        
        @cache
        def wildcardMatching(ind1,ind2):
            if ind1<0 and ind2<0: return True
            if ind1<0 and ind2>=0: return False
            if ind1>=0 and ind2<0: return isAllStars(s1,ind1)
            if s1[ind1]==s2[ind2] or s1[ind1]=='?':
                return wildcardMatching(ind1-1,ind2-1)
            else:
                if s1[ind1]=='*':
                    return wildcardMatching(ind1-1,ind2) or wildcardMatching(ind1,ind2-1) 
                else:
                    return False
        return wildcardMatching(len(s1)-1,len(s2)-1)
            
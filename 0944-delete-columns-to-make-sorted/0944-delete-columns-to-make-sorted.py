class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        verticalStrings=[""]*len(strs[0])
        for i in range(len(strs[0])):
            for str in strs:
                verticalStrings[i]+=str[i]
        print(verticalStrings)
        deleteCount=0
        for str in verticalStrings:
            print(str,"".join(sorted(str)))
            if str != "".join(sorted(str)):deleteCount+=1
        return deleteCount
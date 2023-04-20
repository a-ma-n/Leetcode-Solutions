class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        # exists=[]
        last = {}
        # result = []
        
        for name in names:
            modified = name
            if name in last:
                k = last[name]
                while modified in last:
                    k += 1
                    modified = f'{name}({k})'
                last[name] = k
            last[modified] = 0
        return last.keys()
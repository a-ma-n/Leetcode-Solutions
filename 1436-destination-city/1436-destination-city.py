class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        return list(set([j for i,j in paths])-set([i for i,j in paths]))[0]
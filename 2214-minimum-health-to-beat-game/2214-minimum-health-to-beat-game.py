class Solution:
    def minimumHealth(self, damage: List[int], armor: int) -> int:
        if max(damage)>=armor:
            return sum(damage)-armor+1
        return sum(damage)-max(damage)+1
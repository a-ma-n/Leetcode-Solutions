class Solution:
def minimumDeleteSum(self, s1: str, s2: str) -> int:
@lru_cache(100000)
# mem=dict()
def seq(ind1,ind2,ts1,ts2):
key=(str(ind1)+str(ind2),ts1+ts2)
if key in mem:
return mem[key]
if ts1==ts2:
mem[key]=0
return 0
if ind1<0:
mem[key]=sum(ord(c) for c in ts2[:ind2+1])
return mem[key]
if ind2<0:
mem[key]= sum(ord(c) for c in ts1[:ind1+1])
return mem[key]
# print(s1[ind1],s2[ind2],ind1,ind2,ts1,ts2)
if s1[ind1]==s2[ind2]:
mem[key]= seq(ind1-1,ind2-1,ts1,ts2)
return mem[key]
# delete
newStr1=ts1[:ind1]+ts1[ind1+1:]
newStr2=ts2[:ind2]+ts2[ind2+1:]
mem[key]= min(
ord(s1[ind1])+
seq(ind1-1,ind2,newStr1,ts2),
ord(s2[ind2])+
seq(ind1,ind2-1,ts1,newStr2)
)
return mem[key]
​
return seq(len(s1)-1,len(s2)-1,s1,s2)
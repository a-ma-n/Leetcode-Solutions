class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        tables=defaultdict(dict)
        tablenos=set()
        dishes=OrderedDict()
        d=set()
        # dishmap=dict()
        for _,tableno,dish in orders:
            d.add(dish)
            tablenos.add(tableno)
            
        for dish in sorted(list(d)):
            dishes[dish]=0
        
        for _,tableno,dish in orders:
            tables[tableno]=dishes.copy()
            
        for _,tableno,dish in orders:
            tables[tableno][dish]+=1
            
            
        row=[]
        # l=
        # print("temp",sorted(list(tables),key=lambda x:int(x)))
        ans=[]
        ans.append(["Table"]+list(dishes.keys()))
        # print(ans)

        for t in sorted(list(tables),key=lambda x:int(x)):
            
            row.append(t)
            row.extend(map(str,tables[t].values()))
            ans.append(row.copy())
            row.clear()
        # print(ans)
        # print(row)
        return ans
            
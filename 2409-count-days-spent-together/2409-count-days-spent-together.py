class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        month=[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        aam,aad=int(arriveAlice[:2]),int(arriveAlice[3:])
        alm,ald=int(leaveAlice[:2]),int(leaveAlice[3:])
        bam,bad=int(arriveBob[:2]),int(arriveBob[3:])
        blm,bld=int(leaveBob[:2]),int(leaveBob[3:])
        
        sm,sd,em,ed=0,0,0,0
        
        
        
        
        def diff(sm,sd,em,ed):
            print(sm,sd,em,ed)
            if(sm>=em):
                if(sm==em and ed-sd+1>0):
                    return ed-sd+1
                else: 
                    return 0
            
            a = (month[sm-1]-sd+1)
            b=0
            for i in range(sm+1,em):
                b+= month[i-1]
            c = ed
            #print(month[sm-1],aad,c)
            diff=a+b+c
            return diff
        
        d = 0
        
        if aam>=bam and alm>=blm:
            if(blm==alm):
                ed=min(bld,ald)
            else:
                ed=bld
                
            if(aam==bam):
                sd=max(aad,bad)
            else:
                sd=aad
                
            return diff(aam,sd,blm,ed)
            
        elif aam<=bam and alm<=blm:
            if(blm==alm):
                ed=min(bld,ald)
            else:
                ed=ald
                
            if(aam==bam):
                sd=max(aad,bad)
            else:
                sd=bad
                
            return diff(bam,sd,alm,ed)
        
        elif aam>=bam and alm<=blm:
            if(blm==alm):
                ed=min(bld,ald)
            else:
                ed=ald
            if(aam==bam):
                sd=max(aad,bad)
            else:
                sd=aad
                
            return diff(aam,sd,alm,ed)
            
        elif aam<=bam and blm<=alm:
            if(blm==alm):
                ed=min(bld,ald)
            else:
                ed=bld
                
            if(aam==bam):
                sd=max(aad,bad)
            else:
                sd=bad
                
            return diff(bam,sd,blm,ed)
            
        return d

        
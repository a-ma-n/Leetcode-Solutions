class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        # add on the basis of subdomains if they are present in the map
        # google.mail.com => google.mail.com-> subDomain2Freq , mail.com=>subDomain1Freq , com => topDomainFreq
        # key => val : name - frequenct
        subDomain2Freq = {}
        subDomain1Freq = {}
        topDomainFreq = {}
        
        for website in cpdomains: 
            
            
            frequency = int(website.split(' ')[0])
            domains= website.split(' ')[1]
            
            domains = domains.split('.')
            
            if(len(domains)==2):
                subDomain1 = domains[0]+'.'+domains[1]
                topDomain =  domains[1]
            else:
                subDomain2 = domains[0]+'.'+domains[1] + '.' +domains[2]
                subDomain1 = domains[1]+'.'+domains[2]
                topDomain =  domains[2]
                
            if(len(domains)!=2):
                if subDomain2 not in subDomain2Freq:
                    subDomain2Freq[subDomain2]=frequency
                else:
                    subDomain2Freq[subDomain2]+=frequency
            
            if subDomain1 not in subDomain1Freq:
                subDomain1Freq[subDomain1]=frequency
            else:
                subDomain1Freq[subDomain1]+=frequency
                
            if topDomain not in topDomainFreq:
                topDomainFreq[topDomain]=frequency
            else:
                topDomainFreq[topDomain]+=frequency   
            
           
        
        ans = list() 
        for subDomain1 in subDomain1Freq:
            ans.append(str(subDomain1Freq[subDomain1])+" "+subDomain1)
            
        for subDomain2 in subDomain2Freq:
            ans.append(str(subDomain2Freq[subDomain2])+" "+subDomain2)
        
        for topDomain in topDomainFreq:
            ans.append(str(topDomainFreq[topDomain])+" "+topDomain)
            
        return ans
            
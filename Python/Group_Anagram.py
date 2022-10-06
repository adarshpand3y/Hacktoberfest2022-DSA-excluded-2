class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d= {} 
        for i in strs: 
            word = ''.join(sorted(i))
            if word not in d: 
                d[word]=[i]
            else: 
                d[word].extend([i])  
        return d.values()

'''aet aet ant aet ant abt '''
''' {'aet':['eat'],'ant':['tan'],'abt':['bat']}''' 
''' {'aet':['eat','tea','ate'],'ant':['tan','nat'],'abt':['bat']}''' 

import itertools
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        i = 0
        lis = []
        s1 = ''
        for k in range(numRows):
            lis.append([])
        while i<len(s):
            for j in range(len(lis)):
                if i<len(s):
                    lis[j].append(s[i])
                    i+=1
                else:
                    break
            for j in range(numRows-2):
                if i<len(s):
                    lis[len(lis)-j-2].append(s[i])
                    i+=1
                else:
                    break
                
        s1 = "".join(itertools.chain(*lis))
        return s1

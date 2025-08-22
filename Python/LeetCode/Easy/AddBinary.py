# June24,2025

class Solution:
    def addBinary(self, a, b) :
        if a=='0':
            return b
        elif b=='0':
            return a
        carry='0'
        result=[]
        min_length=min(len(a),len(b))
        n=len(a)
        m=len(b)
        for i in range(min(n,m)-1,-1,-1):
            if a[i]=='0' and b[i]=='0':
                if carry=='1':
                    res='1'
                else:
                    res='0'
                carry='0'
            elif a[i]=='1' and b[i]=='1':
                if carry=='1':
                    res='1'
                else:
                    res='0'
                carry='1'
            else:
                if carry=='1':
                    res='0'
                    carry='1'
                else:
                    res='1'
                    carry='0'
            result.append(res)
            print(res)
            print(result)
        
        if n==m:
            if carry=='1':
                result.append('1')
        
        if n<m:
            for i in range(m-n-1,-1,-1):
                if carry=='1':
                    if b[i] =='1':
                        carry='1'
                        res='0'
                    else:
                        carry='0'
                        res='1'
                    result.append(res)
                else:
                    result.append(b[i])
        else:
            for i in range(n-m-1,-1,-1):
                if carry=='1':
                    if a[i] =='1':
                        carry='1'
                        res='0'
                    else:
                        carry='0'
                        res='1'
                    result.append(res)
                else:
                    result.append(a[i])
        print(result)
  
        return ''.join(result[::-1])

S=Solution()
print(S.addBinary('1010','1011'))

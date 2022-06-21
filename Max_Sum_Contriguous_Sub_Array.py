class Solution:
 
    def maxSubArray(self, A):
        current = 0
        max =A[0]
        for i in range(len(A)):
            current = current+A[i]
            if(current>max):
                max=current
            if(current<0):
                current=0
            
        return max
            

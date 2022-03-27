class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        res = []
        for avalue in arr2:
            for index, bvalue in enumerate(arr1):
                if avalue == bvalue:
                    res.append(arr1[index])
        
        res = res + sorted([avalue for avalue in arr1 if avalue not in arr2]) 
        
        return res

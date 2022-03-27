/*

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

*/

class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        res = []
        for avalue in arr2:
            for index, bvalue in enumerate(arr1):
                if avalue == bvalue:
                    res.append(arr1[index])
        
        res = res + sorted([avalue for avalue in arr1 if avalue not in arr2]) 
        
        return res

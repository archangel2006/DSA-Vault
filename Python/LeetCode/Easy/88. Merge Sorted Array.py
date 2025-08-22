# June22,2025

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        # Set up pointers at the end of the initialized parts
        p1 = m - 1  # Last actual element in nums1
        p2 = n - 1  # Last element in nums2
        p = m + n - 1  # End of nums1 array (total length)
        # While there are elements to compare in both arrays
        while p1 >= 0 and p2 >= 0:
            if nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
            p -= 1
        # If anything is left in nums2, copy it (nums1 leftovers are already in place)
        while p2 >= 0:
            nums1[p] = nums2[p2]
            p2 -= 1
            p -= 1
            
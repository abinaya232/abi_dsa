#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    
    if (m > n) {
        return findMedianSortedArrays(nums2, n, nums1, m);
    }

    int imin = 0, imax = m, half_len = (m + n + 1) / 2;

    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = half_len - i;

        int maxLeftA = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRightA = (i == m) ? INT_MAX : nums1[i];

        int maxLeftB = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRightB = (j == n) ? INT_MAX : nums2[j];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if ((m + n) % 2 == 0) {
                return ((double)fmax(maxLeftA, maxLeftB) + fmin(minRightA, minRightB)) / 2.0;
            } else {
                return (double)fmax(maxLeftA, maxLeftB);
            }
        } else if (maxLeftA > minRightB) {
            imax = i - 1;
        } else {
            imin = i + 1;
        }
    }

  
    return 0.0;
}
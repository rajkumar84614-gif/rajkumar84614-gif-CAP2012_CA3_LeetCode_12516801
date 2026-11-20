class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merged;
        
        int i = 0, j = 0;
        
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }
        
        while (i < m) {
            merged.push_back(nums1[i++]);
        }
        
        while (j < n) {
            merged.push_back(nums2[j++]);
        }
        
        int totalSize = m + n;
       
        if (totalSize % 2 != 0) {
            return merged[totalSize / 2];
        } 
        
        else {
            int mid1 = merged[totalSize / 2 - 1];
            int mid2 = merged[totalSize / 2];
            return (double)(mid1 + mid2) / 2.0;
        }
    }
};

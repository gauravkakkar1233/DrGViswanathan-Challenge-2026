// Day-03-2161-Partition-Array-According-to-Given-Pivot.cpp

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();

        vector<int> ans(n);

        int l = 0;
        int r = n - 1;

        // Place elements smaller than pivot
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < pivot)
            {
                ans[l] = nums[i];
                l++;
            }
        }

        // Place elements greater than pivot
        for(int i = n - 1; i >= 0; i--)
        {
            if(nums[i] > pivot)
            {
                ans[r] = nums[i];
                r--;
            }
        }

        // Fill remaining positions with pivot
        while(l <= r)
        {
            ans[l] = pivot;
            l++;
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Algorithm:
1. Create an answer array of the same size as nums.
2. Use two pointers:
      - l starts from the beginning.
      - r starts from the end.
3. Traverse the array from left to right:
      - Place all elements smaller than pivot at index l.
      - Increment l.
4. Traverse the array from right to left:
      - Place all elements greater than pivot at index r.
      - Decrement r.
5. The remaining positions between l and r must contain pivot.
6. Fill all remaining positions with pivot.
7. Return the final partitioned array.

Example:
nums = [9,12,5,10,14,3,10]
pivot = 10

Elements < pivot:
[9,5,3]

Elements = pivot:
[10,10]

Elements > pivot:
[12,14]

Answer:
[9,5,3,10,10,12,14]
*/
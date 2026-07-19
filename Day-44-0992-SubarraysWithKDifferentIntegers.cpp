class Solution {
public:
    /*
        Algorithm:

        atMostK(nums, k)

        1. Maintain a sliding window
           using two pointers:
           - left
           - right

        2. Use a hash map to store
           the frequency of each
           integer inside the window.

        3. Expand the window by
           moving right.

           If the current number
           appears for the first
           time in the window,
           decrease k.

        4. If the number of distinct
           integers becomes greater
           than the allowed limit
           (k < 0), shrink the window
           from the left until the
           window becomes valid.

        5. Every valid window ending
           at right contributes

           (right - left + 1)

           subarrays.

        6. Return the total count of
           subarrays containing
           at most k distinct integers.

        subarraysWithKDistinct(nums, k)

        Number of subarrays having
        exactly k distinct integers

        =
        At Most(k)
        -
        At Most(k - 1)

        Example:

        nums = [1,2,1,2,3]
        k = 2

        At Most 2 = 12
        At Most 1 = 5

        Exactly 2
        = 12 - 5
        = 7
    */

    int atMostK(vector<int>& nums, int k)
    {
        unordered_map<int, int> freq;

        int left = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            // New distinct integer
            if (freq[nums[right]] == 0)
                k--;

            freq[nums[right]]++;

            // Shrink window if
            // distinct integers exceed k
            while (k < 0)
            {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0)
                    k++;

                left++;
            }

            // Count all valid subarrays
            // ending at right
            count += (right - left + 1);
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums,
                               int k)
    {
        return atMostK(nums, k)
             - atMostK(nums, k - 1);
    }
};

/*
Time Complexity:

Sliding window traverses the array once.

Each element is inserted and removed
from the hash map at most one time.

Overall:
O(n)

Space Complexity:

Hash map stores the frequency of
distinct integers.

Worst Case:
O(n)
*/

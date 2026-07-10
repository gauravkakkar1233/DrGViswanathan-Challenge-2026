class Solution {
public:
    /*
        Algorithm:

        countAtMost(nums, k)

        1. Initialize two pointers:
           - l = left pointer
           - r = right pointer

        2. Expand the window by moving
           the right pointer.

        3. If the current element is odd,
           decrease k because one odd number
           is included in the window.

        4. If the number of odd numbers
           exceeds the allowed limit (k < 0),
           shrink the window from the left:
           - If the left element is odd,
             increase k.
           - Move the left pointer forward.

        5. After the window becomes valid,
           every subarray ending at r and
           starting from l to r is valid.

           Number of valid subarrays:
           (r - l + 1)

        6. Add this count to the answer.

        7. Return the total count of
           subarrays having at most k
           odd numbers.

        To find subarrays with exactly
        k odd numbers:

        Exactly(k) =
        AtMost(k) - AtMost(k - 1)

        Example:

        nums = [1,1,2,1,1]
        k = 3

        AtMost(3) counts all subarrays
        having at most 3 odd numbers.

        AtMost(2) counts all subarrays
        having at most 2 odd numbers.

        Their difference gives the number
        of subarrays having exactly
        3 odd numbers.
    */

    int countAtMost(vector<int>& nums, int k)
    {
        int l = 0;
        int count = 0;

        // Expand the window
        for (int r = 0; r < nums.size(); r++)
        {
            // Include current odd number
            if (nums[r] % 2 != 0)
            {
                k--;
            }

            // Shrink the window if odd count exceeds k
            while (k < 0)
            {
                if (nums[l] % 2 != 0)
                {
                    k++;
                }

                l++;
            }

            // Count all valid subarrays ending at r
            count += (r - l + 1);
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k)
    {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};

/*
Time Complexity:

countAtMost() : O(n)

- The right pointer traverses the array once.
- The left pointer also moves at most n times.

numberOfSubarrays():

- countAtMost(nums, k)     -> O(n)
- countAtMost(nums, k - 1) -> O(n)

Overall:
O(2n) = O(n)

Space Complexity:

O(1)

Only a few integer variables are used.

Overall:
O(1)
*/

class Solution {
public:
    /*
        Algorithm:

        1. Initialize two pointers:
           - l = left pointer
           - r = right pointer

        2. Expand the window by moving the
           right pointer one step at a time.

        3. If the current element is 0,
           increase the zero count.

        4. If the number of zeros exceeds k,
           shrink the window from the left:
           - If the left element is 0,
             decrease the zero count.
           - Move the left pointer forward.

        5. At every step, calculate the
           current window length and update
           the maximum length.

        6. After traversing the entire array,
           return the maximum valid window length.

        Example:

        nums = [1,1,1,0,0,0,1,1,1,1,0]
        k = 2

        Window Expansion:

        [1]
        Length = 1

        [1,1]
        Length = 2

        [1,1,1]
        Length = 3

        [1,1,1,0]
        zeros = 1
        Length = 4

        [1,1,1,0,0]
        zeros = 2
        Length = 5

        [1,1,1,0,0,0]
        zeros = 3 (> k)

        Shrink the window until it becomes valid.

        Continue expanding and updating
        the maximum window length.

        Maximum Length = 6
    */

    int longestOnes(vector<int>& nums, int k)
    {
        int l = 0;
        int zeros = 0;
        int maxlen = 0;

        // Expand the window
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] == 0)
            {
                zeros++;
            }

            // Shrink the window if zeros exceed k
            if (zeros > k)
            {
                if (nums[l] == 0)
                {
                    zeros--;
                }

                l++;
            }

            // Update the maximum window length
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};

/*
Time Complexity:

O(n)

- The right pointer traverses the array once.
- The left pointer also moves at most n times.

Overall:
O(n)

Space Complexity:

O(1)

Only a few integer variables are used.

Overall:
O(1)
*/

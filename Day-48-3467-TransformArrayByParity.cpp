class Solution {
public:
    /*
        Algorithm:

        transformArray(nums)

        1. Initialize a variable:
           - even = 0
             (counts the number
              of even elements)

        2. Traverse the array.

           If the current element
           is even, increment the
           even counter.

        3. Traverse the array again.

           - Fill the first 'even'
             positions with 0.
           - Fill the remaining
             positions with 1.

        4. Return the modified array.
    */

    vector<int> transformArray(vector<int>& nums)
    {
        int even = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                even++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = (i < even) ? 0 : 1;
        }

        return nums;
    }
};

/*
Time Complexity:

First traversal counts
the even elements.

Second traversal fills
the transformed array.

Overall:
O(n)

Space Complexity:

The transformation is
performed in-place using
only a few extra variables.

Overall:
O(1)
*/

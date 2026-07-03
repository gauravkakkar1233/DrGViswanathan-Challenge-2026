class Solution {
public:
    /*
        Algorithm:

        1. XOR all elements of the array.
           Since every duplicate number appears exactly twice,
           they cancel each other out using XOR.

           Result:
           xorAll = unique1 ^ unique2

        2. Find the rightmost set bit in xorAll.
           This bit is set because the two unique numbers differ
           at this position.

           rightMost = (xorAll & (xorAll - 1)) ^ xorAll
           (Using unsigned avoids overflow when xorAll = INT_MIN)

        3. Divide all numbers into two groups:
           • Group 1: Numbers having the rightmost set bit.
           • Group 2: Numbers not having the rightmost set bit.

        4. XOR all numbers within each group.
           Duplicate numbers cancel out, leaving one unique
           number in each group.

        5. Return the two remaining numbers.

        Example:
        nums = [1, 2, 1, 3, 2, 5]

        Step 1:
        xorAll = 1 ^ 2 ^ 1 ^ 3 ^ 2 ^ 5
               = 3 ^ 5
               = 6 (110)

        Step 2:
        rightMost = 2 (010)

        Step 3:
        Group 1 (bit set):
        2, 3, 2

        Group 2 (bit not set):
        1, 1, 5

        Step 4:
        Group 1 XOR:
        2 ^ 3 ^ 2 = 3

        Group 2 XOR:
        1 ^ 1 ^ 5 = 5

        Answer:
        [3, 5]
    */

    vector<int> singleNumber(vector<int>& nums)
    {
        // Stores XOR of all elements
        int xorAll = 0;

        // XOR every element
        for (int num : nums)
        {
            xorAll ^= num;
        }

        // Find the rightmost set bit
        unsigned int x = xorAll;
        int rightMost = (x & (x - 1)) ^ x;
        // Alternatively:
        // int rightMost = xorAll & (-xorAll);

        // Stores the two unique numbers
        int bucket1 = 0;
        int bucket2 = 0;

        // Divide numbers into two groups
        for (int num : nums)
        {
            if (num & rightMost)
            {
                bucket1 ^= num;
            }
            else
            {
                bucket2 ^= num;
            }
        }

        // Return the two unique numbers
        return {bucket1, bucket2};
    }
};

/*
Time Complexity:

O(n)

The array is traversed twice:
1. First traversal computes the XOR of all elements.
2. Second traversal separates the elements into two groups.

Overall:
O(n)

Space Complexity:

O(1)

Only a constant number of integer variables are used,
regardless of the input size.
*/

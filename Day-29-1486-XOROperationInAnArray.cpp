class Solution {
public:
    /*
        Algorithm:

        1. Initialize the answer as 0.
           XOR with 0 does not change the value.

        2. Traverse from i = 0 to i = n - 1.

        3. Generate each element of the array using:
           num = start + 2 * i

           This follows the problem statement:
           nums[i] = start + 2 * i

        4. XOR the current element with the answer.
           Since XOR is associative and commutative,
           we can compute the result without storing
           the entire array.

        5. Return the final XOR value.

        Example:

        n = 5
        start = 0

        Generated array:
        [0, 2, 4, 6, 8]

        XOR computation:

        ans = 0

        ans ^= 0  -> 0
        ans ^= 2  -> 2
        ans ^= 4  -> 6
        ans ^= 6  -> 0
        ans ^= 8  -> 8

        Answer:
        8
    */

    int xorOperation(int n, int start)
    {
        // Stores the XOR of all generated numbers
        int ans = 0;

        // Generate each element and XOR it
        for (int i = 0; i < n; i++)
        {
            int num = start + 2 * i;
            ans ^= num;
        }

        // Return the final XOR value
        return ans;
    }
};

/*
Time Complexity:

O(n)

The loop runs exactly n times.
Each iteration performs constant-time operations.

Overall:
O(n)

Space Complexity:

O(1)

Only a constant number of integer variables are used,
regardless of the input size.
*/

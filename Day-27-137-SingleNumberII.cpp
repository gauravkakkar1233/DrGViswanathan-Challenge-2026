class Solution {
public:
    /*
        Algorithm:

        1. Initialize two variables:
           ones → stores bits that have appeared exactly once.
           twos → stores bits that have appeared exactly twice.

        2. Traverse each element in the array.

        3. For every number:
           • Update ones by toggling the current number's bits using XOR.
           • Remove any bits that already exist in twos.

        4. Update twos:
           • Toggle the current number's bits using XOR.
           • Remove any bits that now exist in ones.

        5. Since every bit appearing three times is removed from both
           ones and twos, only the bits of the unique number remain
           in ones.

        Example:
        nums = [2, 2, 2, 3]

        Initial:
        ones = 0
        twos = 0

        After first 2:
        ones = 2
        twos = 0

        After second 2:
        ones = 0
        twos = 2

        After third 2:
        ones = 0
        twos = 0

        After 3:
        ones = 3
        twos = 0

        Answer:
        3
    */

    int singleNumber(vector<int>& nums)
    {
        // Stores bits that have appeared once
        int ones = 0;

        // Stores bits that have appeared twice
        int twos = 0;

        // Traverse all numbers
        for(int i = 0; i < nums.size(); i++)
        {
            // Update bits appearing once
            ones = (ones ^ nums[i]) & ~twos;

            // Update bits appearing twice
            twos = (twos ^ nums[i]) & ~ones;
        }

        // The remaining bits in ones form the unique number
        return ones;
    }
};

/*
Time Complexity:

O(n)

The array is traversed exactly once, and each iteration performs
a constant number of bitwise operations.

Space Complexity:

O(1)

Only two integer variables (ones and twos) are used,
regardless of the input size.
*/

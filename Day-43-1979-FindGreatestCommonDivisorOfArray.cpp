class Solution {
public:
    /*
        Algorithm:

        findGCD(nums)

        1. Traverse the array once
           to find:
           - Minimum element (mn)
           - Maximum element (mx)

        2. Compute the Greatest
           Common Divisor (GCD)
           of mn and mx.

        3. Return the GCD.

        Example:

        nums = [2, 5, 6, 9, 10]

        Initial:
        mn = 2
        mx = 2

        Visit 5:
        mn = 2
        mx = 5

        Visit 6:
        mn = 2
        mx = 6

        Visit 9:
        mn = 2
        mx = 9

        Visit 10:
        mn = 2
        mx = 10

        GCD(2, 10) = 2

        Answer = 2
    */

    int findGCD(vector<int>& nums)
    {
        // Find the smallest element
        int mn = *min_element(nums.begin(),
                              nums.end());

        // Find the largest element
        int mx = *max_element(nums.begin(),
                              nums.end());

        // Return the GCD of
        // minimum and maximum
        return gcd(mn, mx);
    }
};

/*
Time Complexity:

Finding the minimum element:
O(n)

Finding the maximum element:
O(n)

Computing GCD:
O(log(max(nums)))

Overall:
O(n)

Space Complexity:

Only a few variables are used.

Overall:
O(1)
*/

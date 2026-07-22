class Solution {
public:
    /*
        Algorithm:

        sortArrayByParityII(nums)

        1. Initialize two pointers:
           - even = 0
             (points to even indices)
           - odd = 1
             (points to odd indices)

        2. Traverse the even indices.

           If the element at the
           current even index is odd,
           it is misplaced.

        3. Move the odd pointer until
           an even number is found at
           an odd index.

        4. Swap the misplaced odd
           number at the even index
           with the misplaced even
           number at the odd index.

        5. Continue until all even
           indices contain even
           numbers and all odd
           indices contain odd
           numbers.

        6. Return the modified array.
    */

    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        int even = 0;
        int odd = 1;
        int n = nums.size();

        while (even < n && odd < n)
        {
            if (nums[even] % 2 == 0)
            {
                even += 2;
            }
            else if (nums[odd] % 2 == 1)
            {
                odd += 2;
            }
            else
            {
                swap(nums[even], nums[odd]);
                even += 2;
                odd += 2;
            }
        }

        return nums;
    }
};

/*
Time Complexity:

Each pointer visits every
index at most once.

Overall:
O(n)

Space Complexity:

The sorting is performed
in-place using only a few
extra variables.

Overall:
O(1)
*/

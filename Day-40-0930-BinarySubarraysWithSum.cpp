class Solution {
public:
    /*
        Algorithm:

        numSubarraysWithSum(nums, goal)

        1. The number of subarrays
           having sum exactly equal
           to goal is:

           atMost(goal) -
           atMost(goal - 1)

        2. Create a helper function
           atMost(nums, goal) that
           counts the number of
           subarrays having sum
           less than or equal to
           goal.

        3. If goal becomes negative,
           return 0 because a binary
           array cannot have a
           negative subarray sum.

        4. Initialize:
           - l = left pointer
           - sum = current window sum
           - count = stores the answer

        5. Expand the window by moving
           the right pointer:
           - Add nums[r] to sum.

        6. If the window sum becomes
           greater than goal:
           - Remove elements from the
             left side.
           - Move the left pointer
             forward until the window
             becomes valid again.

        7. Once the window is valid,
           every subarray ending at
           index r and starting from
           l to r has sum <= goal.

           Number of such subarrays:

           (r - l + 1)

           Add this to count.

        8. Continue until the right
           pointer reaches the end.

        9. Return count.

        Example:

        nums = [1,0,1,0,1]
        goal = 2

        atMost(2):

        Window = [1]
        Count += 1

        Window = [1,0]
        Count += 2

        Window = [1,0,1]
        Sum = 2
        Count += 3

        Window = [1,0,1,0]
        Sum = 2
        Count += 4

        Window = [1,0,1,0,1]
        Sum = 3 > 2

        Shrink window:

        Window = [0,1,0,1]
        Sum = 2

        Count += 4

        Final:

        Exact(goal) =
        atMost(2) - atMost(1)
    */

    int atMost(vector<int>& nums, int goal)
    {
        // Binary array cannot have
        // a negative subarray sum
        if (goal < 0)
        {
            return 0;
        }

        // Left pointer
        int l = 0;

        // Stores the current
        // window sum
        int sum = 0;

        // Stores the number of
        // valid subarrays
        int count = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            // Include the current element
            sum += nums[r];

            // Shrink the window until
            // the sum becomes valid
            while (sum > goal)
            {
                sum -= nums[l];
                l++;
            }

            // Number of valid subarrays
            // ending at index r
            count += (r - l + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

/*
Time Complexity:

Let:
n = size of the array

For atMost():

Each element is added to the
window once:
O(n)

Each element is removed from the
window at most once:
O(n)

Overall:
O(n)

Since atMost() is called twice:

O(n) + O(n) = O(n)

Space Complexity:

Only a few variables are used.

Overall:
O(1)
*/

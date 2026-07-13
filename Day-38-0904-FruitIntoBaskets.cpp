class Solution {
public:
    /*
        Algorithm:

        totalFruit(fruits)

        1. Initialize two pointers:
           - l = left pointer
           - r = right pointer

        2. Use a hash map to store
           the frequency of each fruit
           type inside the current window.

        3. Expand the window by moving
           the right pointer:
           - Add the current fruit
             to the hash map.

        4. If the window contains more
           than two distinct fruit types:
           - Remove one occurrence of
             the fruit at the left pointer.
           - If its frequency becomes zero,
             remove it from the hash map.
           - Move the left pointer forward.

        5. If the window contains at most
           two distinct fruit types:
           - Update the maximum window length.

        6. Continue until the right pointer
           reaches the end of the array.

        7. Return the maximum length found.

        Example:

        fruits = [1, 2, 1, 2, 3]

        Window Progress:

        [1]
        Types = {1}
        Max = 1

        [1, 2]
        Types = {1, 2}
        Max = 2

        [1, 2, 1]
        Types = {1, 2}
        Max = 3

        [1, 2, 1, 2]
        Types = {1, 2}
        Max = 4

        Add 3:
        Types = {1, 2, 3}
        Shrink from left until
        only two types remain.

        Maximum Answer = 4
    */

    int totalFruit(vector<int>& fruits)
    {
        int n = fruits.size();

        // Left and right pointers
        int l = 0, r = 0;

        // Stores maximum valid window length
        int maxLen = 0;

        // Stores frequency of fruit types
        unordered_map<int, int> mpp;

        while (r < n)
        {
            // Include current fruit
            mpp[fruits[r]]++;

            // Shrink the window if more than
            // two fruit types are present
            if (mpp.size() > 2)
            {
                mpp[fruits[l]]--;

                if (mpp[fruits[l]] == 0)
                {
                    mpp.erase(fruits[l]);
                }

                l++;
            }

            // Update the maximum valid window
            if (mpp.size() <= 2)
            {
                maxLen = max(maxLen, r - l + 1);
            }

            r++;
        }

        return maxLen;
    }
};

/*
Time Complexity:

Let:
n = size of the fruits array

Each element is added to the
window once:
O(n)

Each element is removed from the
window at most once:
O(n)

Hash map operations:
O(1) on average

Overall:
O(n)

Space Complexity:

Hash map stores at most
three fruit types at any time.

Overall:
O(1)
*/

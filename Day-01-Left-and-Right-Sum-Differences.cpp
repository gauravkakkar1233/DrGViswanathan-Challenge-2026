class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        vector<int> right;
        vector<int> left;

        left.push_back(0);
        int lsum = 0;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            lsum += nums[i];
            left.push_back(lsum);
        }

        right.push_back(0);
        int rsum = 0;

        for(int i = nums.size() - 1; i > 0; i--)
        {
            rsum += nums[i];
            right.push_back(rsum);
        }

        reverse(right.begin(), right.end());

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++)
        {
            ans.push_back(abs(left[i] - right[i]));
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Algorithm:
1. Create a 'left' array where left[i] stores the sum of all elements to the left of index i.
2. Create a 'right' array where right[i] stores the sum of all elements to the right of index i.
3. Build the left array using a running prefix sum.
4. Build the right array using a running suffix sum and reverse it to align indices.
5. For each index i, calculate:
      abs(left[i] - right[i])
6. Store the result in the answer array and return it.

Example:
nums = [10, 4, 8, 3]

left  = [0, 10, 14, 22]
right = [15, 11, 3, 0]

answer = [15, 1, 11, 22]
*/
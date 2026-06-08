class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> ans;

        // First Window
        for(int i = 0; i < k; i++)
        {
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        // Remaining Windows
        for(int i = k; i < nums.size(); i++)
        {
            // Remove elements out of current window
            if(!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // Remove smaller elements from back
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            // Maximum element of current window
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(k)

/*
Algorithm:
1. Use a deque to store indices of useful elements.
2. For each element:
      - Remove indices that are outside the current window.
      - Remove smaller elements from the back since they
        can never be the maximum.
3. The front of the deque always contains the index of
   the maximum element of the current window.
4. Process the first window separately.
5. For every new element:
      - Remove expired indices.
      - Maintain decreasing order in deque.
      - Add current index.
      - Store nums[dq.front()] as the window maximum.
6. Return the answer array.

Example:
nums = [1,3,-1,-3,5,3,6,7], k = 3

Window [1,3,-1]   -> 3
Window [3,-1,-3]  -> 3
Window [-1,-3,5]  -> 5
Window [-3,5,3]   -> 5
Window [5,3,6]    -> 6
Window [3,6,7]    -> 7

answer = [3,3,5,5,6,7]
*/
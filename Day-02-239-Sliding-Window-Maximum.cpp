class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        // First window 
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // answer
        ans.push_back(nums[dq.front()]);
        // Remaining windows
        for (int i = k; i < nums.size(); i++) {
        // removal
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
        // Addition
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        // answer
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
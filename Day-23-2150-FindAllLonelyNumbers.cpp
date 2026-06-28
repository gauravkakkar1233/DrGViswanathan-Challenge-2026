class Solution {
public:
    /*
        Algorithm:

        1. Count frequency of every number:
           Use unordered_map to store how many times
           each number appears in the array.

        2. A number is called lonely if:
           Condition 1:
           It appears exactly once.
           Condition 2:
           Its previous number (num - 1)
           does not exist.
           Condition 3:
           Its next number (num + 1)
           does not exist.

        3. Traverse the array:
           For every number:
           Check if it has frequency 1.
           Check if num-1 is absent.
           Check if num+1 is absent.

        4. If all conditions are satisfied:
           Add the number into answer array.

        5. Return all lonely numbers.

        Example:
        nums = [10,6,5,8]
        Frequency map:
        10 -> 1

        6  -> 1

        5  -> 1

        8  -> 1

        Check:
        10:
        9 and 11 don't exist
        Add 10

        6:
        5 exists
        Skip

        5:
        6 exists
        Skip

        8:
        7 and 9 don't exist
        Add 8

        Answer:

        [10,8]

    */

    vector<int> findLonely(vector<int>& nums) {
        // Stores frequency of each number
        unordered_map<int,int> mpp;
        // Count occurrences
        for(int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        // Stores lonely numbers
        vector<int> ans;
        // Check every number
        for(int i = 0; i < nums.size(); i++)
        {
            int v = nums[i];
            // If duplicate exists
            // or adjacent value exists
            if(
                mpp[v] > 1 ||
                mpp.find(v-1) != mpp.end() ||
                mpp.find(v+1) != mpp.end()
              )
            {
                continue;
            }
            // Number satisfies all conditions
            ans.push_back(v);
        }
        // Return result
        return ans;
    }
};

// Time Complexity:
//
// O(n)
//
// First loop counts frequency
// Second loop checks every number
// Hash map operations are O(1) average.

// Space Complexity:
//
// O(n)
//
// Hash map stores frequencies
// Answer array stores lonely numbers.

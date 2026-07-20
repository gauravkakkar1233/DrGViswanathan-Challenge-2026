class Solution {
public:
    /*
        Algorithm:

        minWindow(s, t)

        1. Create a frequency array
           of size 256 to store the
           count of every character
           present in string t.

        2. Initialize two pointers:
           - left
           - right

           to represent the current
           sliding window.

        3. Maintain a variable cnt
           to count how many required
           characters of t have been
           matched inside the current
           window.

        4. Expand the window by
           moving right.

           If the current character
           is still required
           (frequency > 0),
           increment cnt.

           Decrease its frequency
           in the array.

        5. Whenever all characters
           of t are matched
           (cnt == t.size()),

           try to shrink the window
           from the left while it
           remains valid.

        6. During shrinking,

           update the minimum window
           whenever a smaller valid
           window is found.

           Increase the frequency
           of the left character.

           If its frequency becomes
           positive, the window loses
           one required character,
           so decrement cnt.

        7. Continue until the entire
           string has been processed.

        8. If no valid window exists,
           return an empty string.

           Otherwise, return the
           smallest valid substring.
    */

    string minWindow(string s, string t)
    {
        vector<int> freq(256, 0);

        // Store frequencies of
        // characters in t
        for (char c : t)
            freq[c]++;

        int left = 0;
        int cnt = 0;

        int minLen = INT_MAX;
        int start = -1;

        for (int right = 0; right < s.size(); right++)
        {
            // Required character found
            if (freq[s[right]] > 0)
                cnt++;

            freq[s[right]]--;

            // Shrink the window
            while (cnt == t.size())
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                // Window becomes invalid
                if (freq[s[left]] > 0)
                    cnt--;

                left++;
            }
        }

        return (start == -1)
               ? ""
               : s.substr(start, minLen);
    }
};

/*
Time Complexity:

Both pointers traverse the string
at most once.

Overall:
O(n)

where n = length of string s.

Space Complexity:

Frequency array of size 256.

Overall:
O(1)
*/

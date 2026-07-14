class Solution {
public:
    /*
        Algorithm:

        characterReplacement(s, k)

        1. Initialize two pointers:
           - l = left pointer
           - r = right pointer

        2. Use a hash map to store
           the frequency of each
           character inside the
           current window.

        3. Keep track of the maximum
           frequency (maxFreq) of any
           character in the current
           window.

        4. Expand the window by moving
           the right pointer:
           - Add the current character
             to the hash map.
           - Update maxFreq.

        5. If the number of characters
           that need to be replaced
           exceeds k:
           - Remove one occurrence of
             the character at the
             left pointer.
           - Move the left pointer
             forward.

        6. Once the window becomes
           valid, update the maximum
           window length.

        7. Continue until the right
           pointer reaches the end
           of the string.

        8. Return the maximum valid
           window length.

        Example:

        s = "AABABBA"
        k = 1

        Window Progress:

        "A"
        MaxFreq = 1
        Changes = 0
        Max = 1

        "AA"
        MaxFreq = 2
        Changes = 0
        Max = 2

        "AAB"
        MaxFreq = 2
        Changes = 1
        Max = 3

        "AABA"
        MaxFreq = 3
        Changes = 1
        Max = 4

        Add 'B':
        Window = "AABAB"
        Changes = 2 > k

        Shrink the window from
        the left until the window
        becomes valid again.

        Maximum Answer = 4
    */

    int characterReplacement(string s, int k)
    {
        int n = s.size();

        // Left and right pointers
        int l = 0, r = 0;

        // Stores the maximum frequency
        // of any character in the window
        int maxFreq = 0;

        // Stores the maximum valid
        // window length
        int maxLen = 0;

        // Stores the frequency of
        // characters in the window
        unordered_map<char, int> mpp;

        while (r < n)
        {
            // Include the current character
            mpp[s[r]]++;

            // Update the maximum frequency
            maxFreq = max(maxFreq, mpp[s[r]]);

            // Shrink the window if more than
            // k replacements are needed
            while ((r - l + 1) - maxFreq > k)
            {
                mpp[s[l]]--;
                l++;
            }

            // Update the maximum valid window
            maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};

/*
Time Complexity:

Let:
n = length of the string

Each character is added to the
window once:
O(n)

Each character is removed from the
window at most once:
O(n)

Hash map operations:
O(1) on average

Overall:
O(n)

Space Complexity:

The hash map stores the frequency
of at most 26 uppercase English
letters.

Overall:
O(26) ≈ O(1)

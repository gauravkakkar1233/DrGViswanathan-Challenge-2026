class Solution {
public:
    /*
        Algorithm:

        strStr(haystack, needle)

        1. If the needle is empty,
           return 0 because an empty
           string is always found at
           index 0.

        2. Let:
           - n = length of haystack
           - m = length of needle

        3. Traverse every possible
           starting index in haystack
           where needle can fit:
           i = 0 to (n - m)

        4. For each starting position,
           compare characters of
           haystack and needle one by one.

        5. Continue comparing while
           characters are equal.

        6. If all m characters match,
           return the current starting
           index i.

        7. If no complete match is found
           after checking every possible
           position, return -1.

        Example:

        haystack = "sadbutsad"
        needle   = "sad"

        i = 0
        Compare:
        s == s
        a == a
        d == d

        All characters match.

        Return 0.
    */

    int strStr(string haystack, string needle)
    {
        // Empty needle is always found at index 0
        if (needle.size() == 0)
        {
            return 0;
        }

        int n = haystack.size();
        int m = needle.size();

        // Check every possible starting position
        for (int i = 0; i <= n - m; i++)
        {
            int j = 0;

            // Compare characters one by one
            while (j < m && haystack[i + j] == needle[j])
            {
                j++;
            }

            // Complete match found
            if (j == m)
            {
                return i;
            }
        }

        // Needle not found
        return -1;
    }
};

/*
Time Complexity:

Let:
n = length of haystack
m = length of needle

Outer loop:
- Runs (n - m + 1) times.

Inner loop:
- In the worst case,
  compares m characters
  for each starting index.

Overall:
O((n - m + 1) * m)

Worst Case:
O(n * m)

Space Complexity:

O(1)

Only a few integer variables
are used.

Overall:
O(1)
*/

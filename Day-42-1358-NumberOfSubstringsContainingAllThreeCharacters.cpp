class Solution {
public:
    /*
        Algorithm:

        numberOfSubstrings(s)

        1. Maintain an array last[]
           of size 3 to store the
           most recent index of
           characters:
           - 'a'
           - 'b'
           - 'c'

           Initially:
           last = {-1, -1, -1}

        2. Traverse the string
           from left to right.

        3. For each character,
           update its latest index.

        4. At every index i,
           consider all substrings
           ending at i.

           Let:

           earliest = min(last[0],
                          last[1],
                          last[2])

        5. If all three characters
           have appeared, then
           earliest will be
           non-negative.

           Every starting index from

           0 ... earliest

           forms a valid substring
           ending at i because each
           substring contains at
           least one 'a', one 'b',
           and one 'c'.

           Number of valid starting
           positions:

           earliest + 1

        6. Add (earliest + 1)
           to the answer.

           If any character has not
           appeared yet, one of the
           values in last[] is -1.

           Then:

           earliest = -1

           earliest + 1 = 0

           so nothing is added.

        7. Return the total count.

        Example:

        s = "abcabc"

        i = 0
        last = {0,-1,-1}
        add = 0

        i = 1
        last = {0,1,-1}
        add = 0

        i = 2
        last = {0,1,2}
        earliest = 0
        add = 1

        i = 3
        last = {3,1,2}
        earliest = 1
        add = 2

        i = 4
        last = {3,4,2}
        earliest = 2
        add = 3

        i = 5
        last = {3,4,5}
        earliest = 3
        add = 4

        Total = 1 + 2 + 3 + 4 = 10
    */

    int numberOfSubstrings(string s)
    {
        int cnt = 0;

        // Stores the latest occurrence
        // of 'a', 'b', and 'c'
        vector<int> last(3, -1);

        for (int i = 0; i < s.size(); i++)
        {
            // Update the latest index
            // of the current character
            last[s[i] - 'a'] = i;

            // Count all valid substrings
            // ending at index i
            cnt += 1 + min(last[0],
                           min(last[1], last[2]));
        }

        return cnt;
    }
};

/*
Time Complexity:

The string is traversed only once.

Each iteration performs only
constant-time operations.

Overall:
O(n)

Space Complexity:

Only an array of size 3 is used.

Overall:
O(1)
*/

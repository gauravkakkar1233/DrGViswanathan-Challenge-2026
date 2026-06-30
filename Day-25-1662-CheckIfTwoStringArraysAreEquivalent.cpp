class Solution {
public:
    /*
        Algorithm:
        
        1. Create two empty strings:
           ans1 → stores complete string formed from word1
           ans2 → stores complete string formed from word2

        2. Traverse word1 array:
           Append every string into ans1.

           Example:
           word1 = ["ab","c"]
           ans1 = "abc"

        3. Traverse word2 array:
           Append every string into ans2.

           Example:
           word2 = ["a","bc"]
           ans2 = "abc"

        4. Compare both final strings:
           If ans1 == ans2:
           Both string arrays are equivalent.
           Otherwise:

           They are different.

        Example:
        word1 = ["ab","c"]
        word2 = ["a","bc"]

        After concatenation:
        ans1 = "abc"
        ans2 = "abc"

        Answer:
        true
    */

    bool arrayStringsAreEqual(
        vector<string>& word1,
        vector<string>& word2
    )
    {
        // Stores complete word1 string
        string ans1 = "";
        // Stores complete word2 string
        string ans2 = "";
        // Build string from word1
        for(int i = 0; i < word1.size(); i++)
        {
            ans1 += word1[i];
        }
        // Build string from word2
        for(int i = 0; i < word2.size(); i++)
        {
            ans2 += word2[i];
        }
        // Compare both strings
        return ans1 == ans2;
    }
};

// Time Complexity:
//
// O(n + m)
//
// n = total characters in word1
// m = total characters in word2
//
// Every character is processed once.

// Space Complexity:
//
// O(n + m)
//
// Extra strings store concatenated results.

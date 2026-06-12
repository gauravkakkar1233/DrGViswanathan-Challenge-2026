class Solution {
public:

    /*
        Algorithm:

        1. Traverse the string from left to right.

        2. Whenever we find '*':
              - Remove the character before '*'
              - Remove the '*'
              - Move index back because string size changed

        3. Continue until all stars are removed.

        Example:

        s = "leet**cod*e"

        i=4 -> '*'
        remove "t*"

        s = "lee*cod*e"

        i=3 -> '*'
        remove "e*"

        s = "lecod*e"

        i=5 -> '*'
        remove "d*"

        Answer:
        "lecoe"
    */


    string removeStars(string s) {


        int n = s.size();


        // Traverse string
        for(int i = 0; i < s.size(); i++)
        {

            // If star found
            if(s[i] == '*')
            {

                // Remove previous character and star
                s.erase(i-1,2);


                // Move index back because string size reduced
                i = i - 2;
            }
        }


        return s;
    }
};


// Time Complexity:
// erase() takes O(n) in worst case
// Loop runs n times
// Overall -> O(n^2)


// Space Complexity:
// O(1)

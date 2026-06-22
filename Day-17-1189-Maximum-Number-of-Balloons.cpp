class Solution {
public:

    /*
        Algorithm:

        1. Count the frequency of required characters:

           The word "balloon" requires:

           b -> 1 time
           a -> 1 time
           l -> 2 times
           o -> 2 times
           n -> 1 time


           Traverse the string:
           - Store the count of only these characters.
           - Ignore all other characters.



        2. Calculate maximum balloons possible:

           For each required character:

           b:
              One b is needed for one balloon.

           a:
              One a is needed for one balloon.

           l:
              Two l's are needed for one balloon.
              So possible balloons = l count / 2

           o:
              Two o's are needed for one balloon.
              So possible balloons = o count / 2

           n:
              One n is needed for one balloon.



        3. The character with the minimum availability decides
           the maximum number of "balloon" words we can create.



        Example:

        text = "loonbalxballpoon"


        Character counts:

        b = 2
        a = 2
        l = 4
        o = 4
        n = 2


        Possible balloons:

        b -> 2
        a -> 2
        l -> 4/2 = 2
        o -> 4/2 = 2
        n -> 2


        Answer:
        2 balloons

    */


    int maxNumberOfBalloons(string text) {


        // Stores frequency of required characters
        unordered_map<char,int> mpp;



        // Count characters needed for "balloon"
        for(int i = 0; i < text.size(); i++)
        {

            char ch = text[i];


            // Store only useful characters
            if(ch=='b' || ch=='a' || ch=='l' || ch=='o' || ch=='n')
            {
                mpp[ch]++;
            }

        }



        // Start with maximum possible value
        int ans = INT_MAX;



        // Check how many balloons each character can make

        // One 'b' needed
        ans = min(ans, mpp['b']);


        // One 'a' needed
        ans = min(ans, mpp['a']);


        // Two 'l' needed
        ans = min(ans, mpp['l'] / 2);


        // Two 'o' needed
        ans = min(ans, mpp['o'] / 2);


        // One 'n' needed
        ans = min(ans, mpp['n']);



        // Return maximum balloons possible
        return ans;

    }

};


// Time Complexity:
// Counting characters takes O(n)
// Checking fixed characters takes O(1)
// Total: O(n)


// Space Complexity:
// HashMap stores only 5 characters
// Extra space: O(1)

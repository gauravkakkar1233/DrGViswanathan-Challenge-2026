class Solution {
public:

    /*
        Algorithm:

        1. Given an array gain.

        2. The biker starts at altitude 0.

        3. Traverse the gain array.

        4. For every value:

            - Add current gain to current altitude.

            - Update maximum altitude reached.


        Example:

        gain = [-5,1,5,0,-7]


        Start:
        altitude = 0


        Add -5:
        altitude = -5
        max = -5


        Add 1:
        altitude = -4
        max = -4


        Add 5:
        altitude = 1
        max = 1


        Add 0:
        altitude = 1
        max = 1


        Add -7:
        altitude = -6
        max = 1


        Highest Altitude:
        1
    */


    int largestAltitude(vector<int>& gain) {


        // Stores current altitude
        int sum = 0;


        // Stores maximum altitude reached
        int ans = 0;



        // Traverse complete gain array
        for(int i = 0; i < gain.size(); i++)
        {


            // Update current altitude
            sum += gain[i];



            // Update maximum altitude
            ans = max(ans, sum);

        }



        // Return highest altitude
        return ans;

    }
};


// Time Complexity:
// Every element is visited once
// O(n)


// Space Complexity:
// Only variables are used
// O(1)

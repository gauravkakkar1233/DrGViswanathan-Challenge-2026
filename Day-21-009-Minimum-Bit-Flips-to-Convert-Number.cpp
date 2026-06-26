class Solution {
public:


    /*
        Algorithm:


        1. Find the bits which are different:

           Use XOR operation:


           n = start ^ goal



           XOR property:


           Same bits  -> 0

           Different bits -> 1



           Example:


           start = 10

           binary: 1010


           goal = 7

           binary: 0111



           XOR:


           1010
           0111
           ----
           1101



           Here 3 bits are different,
           so we need 3 flips.




        2. Count the number of set bits (1s):


           Use Brian Kernighan's Algorithm:



           n = n & (n - 1)



           This removes the lowest set bit
           from the number.



           Example:


           n = 1101


           n-1 = 1100



           1101
           1100
           ----
           1100



           One set bit removed.



           Repeat until n becomes 0.




        3. Return count:


           Count represents the minimum number
           of bit flips required.





        Example:


        start = 10

        goal = 7



        start ^ goal:


        1010
        0111
        ----
        1101



        Count set bits:


        1101 -> remove 1

        1100 -> remove 1

        1000 -> remove 1

        0000



        Answer = 3

    */





    int minBitFlips(int start, int goal) {


        // XOR gives positions where bits differ

        int n = start ^ goal;



        // Stores number of flips

        int cnt = 0;





        // Count set bits

        while(n != 0)
        {


            // Remove the lowest set bit

            n = n & (n - 1);



            // Increase flip count

            cnt++;

        }





        // Return minimum flips

        return cnt;
    }
};




// Time Complexity:
//
// O(k)
//
// k = number of set bits in start ^ goal
//
// At most 32 iterations for integer.



// Space Complexity:
//
// O(1)
//
// Only variables are used.

class Solution {
public:
    /*
        Algorithm:

        trailingZeroes(n)

        1. Initialize a variable cnt
           to store the total number
           of trailing zeroes.

        2. Iterate through every
           multiple of 5 from
           5 to n.

        3. For each multiple,

           repeatedly divide it
           by 5 until it is no
           longer divisible.

           Each division contributes
           one additional factor of 5.

        4. Add all such factors of 5
           to cnt.

        5. After processing all
           multiples of 5,

           return cnt as the total
           number of trailing zeroes
           in n!.
    */

    int trailingZeroes(int n)
    {
        int cnt = 0;

        for (int i = 5; i <= n; i += 5)
        {
            int num = i;

            while (num % 5 == 0)
            {
                cnt++;
                num /= 5;
            }
        }

        return cnt;
    }
};

/*
Time Complexity:

The outer loop iterates over
all multiples of 5 up to n.

The inner loop runs only for
numbers having multiple factors
of 5.

Overall:
O(n)

Space Complexity:

Only a few integer variables
are used.

Overall:
O(1)
*/

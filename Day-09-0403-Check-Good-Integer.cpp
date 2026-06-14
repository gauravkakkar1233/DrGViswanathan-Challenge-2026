class Solution {
public:

    /*
        Algorithm:

        1. Take the given integer n.

        2. Traverse all digits of n from right to left.

        3. For every digit:
              - Ignore digit 0.
              - Add digit to sum.
              - Add square of digit to squaresum.

        4. Calculate:
              ans = squaresum - sum

        5. If ans >= 50:
              return true
           Else:
              return false


        Example:

        n = 123

        digit = 3
        sum = 3
        squaresum = 9

        digit = 2
        sum = 5
        squaresum = 13

        digit = 1
        sum = 6
        squaresum = 14

        ans = 14 - 6 = 8

        Since 8 < 50

        Answer:
        false
    */


    bool checkGoodInteger(int n) {


        long long sum = 0;
        long long squaresum = 0;


        // Traverse digits
        while(n > 0)
        {

            // Extract last digit
            long long digit = n % 10;


            // Remove last digit
            n = n / 10;


            // Ignore zero digit
            if(digit == 0)
            {
                continue;
            }


            // Add digit
            sum += digit;


            // Add square of digit
            squaresum += digit * digit;
        }


        // Difference between square sum and sum
        long long ans = squaresum - sum;


        return ans >= 50;
    }
};


// Time Complexity:
// Loop runs for number of digits in n
// O(log10(n))


// Space Complexity:
// Only variables are used
// O(1)

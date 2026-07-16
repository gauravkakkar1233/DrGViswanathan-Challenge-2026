class Solution {
public:
    /*
        Algorithm:

        gcdOfOddEvenSums(n)

        1. Observe the first n odd numbers:

           1, 3, 5, ...

           Sum of first n odd numbers:

           oddSum = n²

        2. Observe the first n even numbers:

           2, 4, 6, ...

           Sum of first n even numbers:

           evenSum = n(n + 1)

        3. We need to find:

           gcd(oddSum, evenSum)

           = gcd(n², n(n + 1))

        4. Factor out n:

           = n × gcd(n, n + 1)

        5. Since two consecutive numbers
           are always coprime:

           gcd(n, n + 1) = 1

        6. Therefore:

           gcd(n², n(n + 1)) = n

        7. Return n.

        Example:

        n = 4

        Odd numbers:
        1 + 3 + 5 + 7 = 16

        Even numbers:
        2 + 4 + 6 + 8 = 20

        gcd(16, 20) = 4

        Return 4.
    */

    int gcdOfOddEvenSums(int n)
    {
        // From the mathematical proof:
        //
        // gcd(n², n(n + 1))
        // = n × gcd(n, n + 1)
        // = n × 1
        // = n

        return n;
    }
};

/*
Time Complexity:

Only a single return statement
is executed.

Overall:
O(1)

Space Complexity:

No extra space is used.

Overall:
O(1)
*/

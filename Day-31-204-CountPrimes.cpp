class Solution {
public:
    /*
        Algorithm:

        1. If n <= 2, return 0 because there are
           no prime numbers less than 2.

        2. Create a boolean array (prime) of size n.
           Initially, mark all numbers from 2 to n - 1
           as prime.

        3. Apply the Sieve of Eratosthenes:

           - Start from i = 2.
           - Continue while i * i <= n - 1.
           - If i is still marked as prime,
             then all of its multiples cannot
             be prime.

        4. Mark every multiple of i starting from
           i * i as non-prime because all smaller
           multiples have already been processed.

        5. Repeat this process until every composite
           number is marked.

        6. Traverse the prime array from 2 to n - 1
           and count every number still marked as prime.

        7. Return the total count.

        Example:

        n = 10

        Initially:

        2 3 4 5 6 7 8 9
        P P P P P P P P

        Using i = 2:

        Mark:
        4, 6, 8

        Using i = 3:

        Mark:
        9

        Final prime numbers:

        2, 3, 5, 7

        Answer:
        4
    */

    void primegen(vector<int>& prime, int n)
    {
        // Mark every number as prime initially
        for (int i = 2; i <= n; i++)
        {
            prime[i] = 1;
        }

        // Apply Sieve of Eratosthenes
        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i])
            {
                // Mark all multiples of i as non-prime
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
    }

    int countPrimes(int n)
    {
        // No prime numbers less than 2
        if (n <= 2)
        {
            return 0;
        }

        // Create prime array
        vector<int> prime(n, 0);

        // Generate all prime numbers
        primegen(prime, n - 1);

        int cnt = 0;

        // Count all prime numbers less than n
        for (int i = 2; i < n; i++)
        {
            cnt += prime[i];
        }

        return cnt;
    }
};

/*
Time Complexity:

O(n log log n)

The Sieve of Eratosthenes marks
multiples of every prime number only once.

Overall:
O(n log log n)

Space Complexity:

O(n)

An additional array of size n
is used to store whether each
number is prime or not.

Overall:
O(n)
*/

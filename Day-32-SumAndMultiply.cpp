class Solution {
public:
    /*
        Algorithm:

        1. Convert the integer n into a string.

        2. Traverse each character of the string:
           - Ignore every '0'.
           - Append every non-zero digit to a new string.

        3. If the new string becomes empty,
           return 0 because there are no
           non-zero digits.

        4. Convert the new string back into
           an integer.

        5. Store this integer because it will
           be used later for multiplication.

        6. Find the sum of all digits of
           the newly formed number.

        7. Multiply the new number with
           its digit sum.

        8. Return the final result.

        Example:

        n = 10230

        Remove all zeros:

        "10230" → "123"

        New Number:
        123

        Sum of digits:
        1 + 2 + 3 = 6

        Answer:
        123 × 6 = 738
    */

    long long sumAndMultiply(int n)
    {
        // Convert integer to string
        string num = to_string(n);

        // Store number after removing zeros
        string ans = "";

        // Remove all zero digits
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] != '0')
            {
                ans += num[i];
            }
        }

        // If no non-zero digits exist
        if (ans.empty())
        {
            return 0;
        }

        // Convert the new string to an integer
        int number = stoi(ans);

        int temp = number;
        int sum = 0;

        // Calculate the sum of digits
        while (temp > 0)
        {
            int digit = temp % 10;
            sum += digit;
            temp /= 10;
        }

        // Return number × digit sum
        return 1LL * number * sum;
    }
};

/*
Time Complexity:

O(d)

where d is the number of digits in n.

- Converting to string takes O(d).
- Removing zeros takes O(d).
- Summing digits takes O(d).

Overall:
O(d)

Space Complexity:

O(d)

An additional string is used to
store the non-zero digits.

Overall:
O(d)

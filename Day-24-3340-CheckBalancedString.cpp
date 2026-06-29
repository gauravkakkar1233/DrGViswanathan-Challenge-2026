class Solution {
public:
    /*
        Algorithm:

        1. Calculate sum of digits at even positions
           and odd positions separately.


        2. Traverse the string:
           For every character:
           Convert character digit into integer:
           value = ch - '0'

        3. Check index:
           If index is even:
           Add digit to even sum.
           Else:
           Add digit to odd sum.

        4. After traversal:
           If both sums are equal:
           String is balanced.
           Otherwise:
           String is not balanced.

        Example:
        num = "123456"
        Index:
        0 1 2 3 4 5
        Digits:
        1 2 3 4 5 6

        Even index sum:
        1 + 3 + 5 = 9
        Odd index sum:
        2 + 4 + 6 = 12

        Since:
        9 != 12
        Answer:
        false

    */
    bool isBalanced(string num) {
        // Stores sum of digits
        // at even indices
        int esum = 0;
        // Stores sum of digits
        // at odd indices
        int osum = 0;
        // Traverse the string
        for(int i = 0; i < num.size(); i++)
        {
            // Convert character
            // into integer digit
            int value = num[i] - '0';
            // Check index position
            if(i % 2 == 0)
            {
                // Add to even sum
                esum += value;
            }
            else
            {
                // Add to odd sum
                osum += value;
            }
        }
        // Balanced if both sums are equal
        return esum == osum;
    }
};

// Time Complexity:
//
// O(n)
//
// Traverse the string once
// and process every digit.

// Space Complexity:
//
// O(1)
//
// Only two variables are used
// for storing sums.

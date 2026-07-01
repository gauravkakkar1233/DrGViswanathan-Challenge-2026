class Solution {
public:
    /*
        Algorithm:

        1. Create two arrays:
           value  → stores integer values in descending order.
           symbol → stores corresponding Roman numeral symbols.

        2. Create an empty string:
           ans → stores the final Roman numeral.

        3. Traverse the value array from largest to smallest.

        4. For each value:
           While the current number is greater than or equal to that value:
           • Append the corresponding Roman symbol to ans.
           • Subtract that value from num.

        5. Continue until num becomes 0.

        Example:
        num = 58

        58 >= 50
        ans = "L"
        num = 8

        8 >= 5
        ans = "LV"
        num = 3

        3 >= 1
        ans = "LVI"
        num = 2

        2 >= 1
        ans = "LVII"
        num = 1

        1 >= 1
        ans = "LVIII"
        num = 0

        Answer:
        "LVIII"
    */

    string intToRoman(int num)
    {
        // Stores integer values in descending order
        vector<int> value = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        // Stores corresponding Roman numeral symbols
        vector<string> symbol = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        // Stores the final Roman numeral
        string ans = "";

        // Traverse all value-symbol pairs
        for(int i = 0; i < value.size(); i++)
        {
            // Append the current Roman symbol
            // while its value can be subtracted
            while(num >= value[i])
            {
                ans += symbol[i];
                num -= value[i];
            }
        }

        // Return the constructed Roman numeral
        return ans;
    }
};

// Time Complexity:
//
// O(1)
//
// The value and symbol arrays contain only 13 fixed elements.
// Hence, the number of iterations is constant.

// Space Complexity:
//
// O(1)
//
// Only a fixed-size lookup table is used.
// (Excluding the output string.)

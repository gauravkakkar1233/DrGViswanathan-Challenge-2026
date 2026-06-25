class Solution {
public:


    /*
        Algorithm:


        1. Initialize variables:

           num = 0

           Stores the final number.

           
           i = 0

           Used to traverse the string.


           sign = 1

           Default sign is positive.



        2. Ignore leading spaces:


           Example:

           s = "     42"


           Move i forward until a non-space character
           is found.




        3. Check sign:


           If current character is:

           '+'

           sign remains 1


           '-'

           sign becomes -1



           Example:


           "-42"

           sign = -1




        4. Convert characters into number:


           Traverse while characters are digits.


           Character to integer conversion:


           digit = s[i] - '0'



           Example:


           '7' - '0'


           gives:


           7




        5. Handle integer overflow:


           Before adding digit:


           num * 10 + digit


           may exceed INT range.



           Check:


           num > INT_MAX / 10


           OR


           num == INT_MAX / 10
           AND
           digit > 7



           If overflow:


           return INT_MAX
           or
           INT_MIN



        6. Return answer:


           Multiply number with sign.



           Example:


           s = "-123"


           num = 123

           sign = -1


           answer = -123




        Example:


        s = "   -42abc"



        Step 1:

        Skip spaces


        i points to '-'


        Step 2:

        sign = -1



        Step 3:

        Convert digits:


        num = 42



        Step 4:

        Stop at 'a'



        Answer:

        -42

    */





    int myAtoi(string s) {


        // Stores converted number

        int num = 0;



        // Pointer for string traversal

        int i = 0;



        // Positive by default

        int sign = 1;





        // Remove leading spaces

        while(i < s.size() && s[i] == ' ')
        {
            i++;
        }





        // Check sign

        if(i < s.size() && (s[i] == '-' || s[i] == '+'))
        {

            if(s[i] == '-')
            {
                sign = -1;
            }

            else
            {
                sign = 1;
            }


            i++;
        }





        // Convert digits

        while(i < s.size() && isdigit(s[i]))
        {

            int digit = s[i] - '0';




            // Overflow check

            if(num > INT_MAX / 10 ||
              (num == INT_MAX / 10 && digit > 7))
            {

                if(sign == -1)
                {
                    return INT_MIN;
                }

                else
                {
                    return INT_MAX;
                }
            }




            // Build number

            num = num * 10 + digit;


            i++;
        }





        // Apply sign

        return sign * num;
    }
};




// Time Complexity:
//
// O(n)
//
// n = length of string
//
// We traverse the string once.




// Space Complexity:
//
// O(1)
//
// Only variables are used.

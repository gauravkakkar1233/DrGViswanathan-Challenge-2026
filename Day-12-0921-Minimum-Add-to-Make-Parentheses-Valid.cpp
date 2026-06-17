class Solution {
public:

    /*
        Algorithm:

        1. Take the given parentheses string s.

        2. Traverse the string from left to right.

        3. Maintain a stack to store unmatched opening brackets.

        4. For every character:
              
              - If character is '(':
                    Push it into stack.
                    Increase answer because this opening bracket
                    currently needs a matching ')'.

              - If character is ')':
                    If stack is not empty:
                        Pop one '(' because it forms a valid pair.
                        Decrease answer because one required addition
                        is cancelled.

                    Else:
                        There is no matching '('.
                        We need to add one '(' before this ')'.
                        Increase answer.

        5. Return answer.


        Example:

        s = "())"

        '('
        Push '('
        ans = 1

        ')'
        Match with '('
        Pop
        ans = 0

        ')'
        Stack empty
        Need '('
        ans = 1


        Answer:
        1
    */


    int minAddToMakeValid(string s) {


        stack<char> st;

        int ans = 0;


        // Traverse string
        for(int i = 0; i < s.size(); i++)
        {

            char ch = s[i];


            // Opening bracket
            if(ch == '(')
            {

                // Store unmatched '('
                st.push(ch);


                // Need closing bracket
                ans++;
            }


            // Closing bracket
            else
            {

                // If matching '(' exists
                if(!st.empty())
                {

                    // Remove matched bracket
                    st.pop();


                    // Valid pair formed
                    ans--;
                }


                // No matching '('
                else
                {

                    // Need opening bracket
                    ans++;
                }
            }
        }


        return ans;
    }
};


// Time Complexity:
// Traverse string once
// O(n)


// Space Complexity:
// Stack stores unmatched '('
// O(n)

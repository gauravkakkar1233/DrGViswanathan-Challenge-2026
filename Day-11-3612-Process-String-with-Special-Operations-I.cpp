class Solution {
public:

    /*
        Algorithm:

        1. Create a stack to store the current result.

        2. Traverse the string from left to right.

        3. For each character:

           - If it is a lowercase letter:
                Push it into stack.

           - If it is '*':
                Remove the last character by popping stack.

           - If it is '#':
                Duplicate the current string.
                Store stack elements in a temporary vector,
                restore original string,
                then push the copy again.

           - If it is '%':
                Reverse the current string.
                Store stack elements in a vector and push them back.

        4. After processing all characters:
              Convert stack into final answer string.

        Example:

        s = "a#b%*"


        'a'
        Stack:
        a


        '#'
        Duplicate:
        aa


        'b'
        Stack:
        aab


        '%'
        Reverse:
        baa


        '*'
        Remove last:
        ba


        Final Answer:
        "ba"

    */


    string processStr(string s) {


        // Stack to store current result
        stack<char> st;



        // Process string
        for(char ch : s)
        {


            // Add character
            if(ch >= 'a' && ch <= 'z')
            {
                st.push(ch);
            }



            // Remove last character
            else if(ch == '*')
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }




            // Duplicate current string
            else if(ch == '#')
            {

                vector<char> temp;


                // Store current string
                while(!st.empty())
                {
                    temp.push_back(st.top());
                    st.pop();
                }



                // Restore original order
                reverse(temp.begin(), temp.end());



                // Push original string
                for(char c : temp)
                {
                    st.push(c);
                }



                // Push duplicate
                for(char c : temp)
                {
                    st.push(c);
                }

            }




            // Reverse current string
            else if(ch == '%')
            {

                vector<char> temp;



                // Take all elements
                while(!st.empty())
                {
                    temp.push_back(st.top());
                    st.pop();
                }



                // Push reversed order
                for(char c : temp)
                {
                    st.push(c);
                }

            }

        }



        // Create final answer
        string ans = "";



        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }



        // Stack gives reverse order
        reverse(ans.begin(), ans.end());



        return ans;
    }
};


// Time Complexity:
// Each operation can traverse stack
// O(n^2)


// Space Complexity:
// Stack + temporary vector used
// O(n)

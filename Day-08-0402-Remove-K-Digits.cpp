class Solution {
public:

    /*
        Algorithm:

        1. Traverse the number from left to right.

        2. Use a stack to maintain digits in increasing order.

        3. Whenever current digit is smaller than stack top:
              - Remove the larger digit from stack
              - Decrease k
              - Continue until the stack becomes valid or k becomes 0

        4. Push the current digit into stack.

        5. If k is still remaining:
              - Remove digits from the end of stack.

        6. Build answer from stack.
           Reverse it because stack stores digits in reverse order.

        7. Remove leading zeros.
           If answer becomes empty return "0".


        Example:

        num = "1432219", k = 3


        digit = 1
        stack = 1


        digit = 4
        stack = 14


        digit = 3
        4 > 3
        remove 4

        stack = 13


        digit = 2
        3 > 2
        remove 3

        stack = 12


        digit = 2
        stack = 122


        digit = 1
        2 > 1
        remove 2

        stack = 121


        remaining k = 0

        Answer = "1219"


    */


    string removeKdigits(string num, int k) {

        stack<char> st;


        // Traverse number
        for(auto digit : num)
        {

            // Remove bigger digits to make smallest number
            while(!st.empty() && k > 0 && st.top() > digit)
            {
                st.pop();
                k--;
            }


            // Add current digit
            st.push(digit);
        }


        // If removals are remaining
        while(!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }


        string ans;


        // Store stack elements
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }


        // Reverse because stack gives reverse order
        reverse(ans.begin(), ans.end());


        // Remove leading zeros
        int i = 0;

        while(i < ans.size() && ans[i] == '0')
        {
            i++;
        }


        ans = ans.substr(i);


        return ans == "" ? "0" : ans;
    }
};


// Time Complexity:
// Each digit is pushed once and popped once
// Overall -> O(n)


// Space Complexity:
// Stack stores n digits
// Overall -> O(n)

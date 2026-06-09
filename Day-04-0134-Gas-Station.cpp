// Day-04-0134-Gas-Station.cpp

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int start = 0;
        int deficit = 0;
        int balance = 0;

        int n = gas.size();

        for(int i = 0; i < n; i++)
        {
            // If we cannot reach the next station
            if(balance + gas[i] < cost[i])
            {
                deficit += balance + gas[i] - cost[i];
                start = i + 1;
                balance = 0;
            }
            else
            {
                balance += gas[i] - cost[i];
            }
        }

        // Check if total gas is sufficient
        if(balance + deficit >= 0)
        {
            return start;
        }

        return -1;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Algorithm:
1. Initialize:
      - start = 0 (candidate starting station)
      - balance = 0 (current fuel in tank)
      - deficit = 0 (fuel shortage accumulated from failed starts)

2. Traverse all gas stations:
      - If balance + gas[i] < cost[i]:
            a) We cannot reach the next station.
            b) Add the shortage to deficit.
            c) Set the next station as the new candidate start.
            d) Reset balance to 0.
      - Otherwise:
            a) Update balance with the remaining fuel after travel.

3. After the traversal:
      - balance stores the surplus fuel from the final candidate start.
      - deficit stores the total shortage from previous failed attempts.

4. If balance + deficit >= 0:
      - Total gas is enough to complete the circuit.
      - Return start.

5. Otherwise:
      - No valid starting station exists.
      - Return -1.

Example 1:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Traversal:
i = 0 -> fail, start = 1
i = 1 -> fail, start = 2
i = 2 -> fail, start = 3
i = 3 -> balance = 3
i = 4 -> balance = 6

balance + deficit = 0

Answer:
3

Example 2:
gas  = [2,3,4]
cost = [3,4,3]

After traversal:
balance + deficit < 0

Answer:
-1
*/
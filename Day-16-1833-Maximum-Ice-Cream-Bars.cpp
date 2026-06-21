class Solution {
public:

    /*
        Algorithm:

        1. Sort the costs array:
           
           - Arrange ice cream prices in increasing order.
           - This helps us choose the cheapest ice creams first.


        2. Traverse the sorted array:

           For every ice cream:

           If we have enough coins:
              - Buy that ice cream.
              - Increase the count.
              - Reduce coins by its cost.

           Else:
              - We cannot buy more expensive ice creams.
              - Continue checking.


        Example:

        costs = [1,3,2,4,1]
        coins = 7


        After sorting:

        costs = [1,1,2,3,4]


        Buy cost 1:
        coins = 6
        count = 1


        Buy cost 1:
        coins = 5
        count = 2


        Buy cost 2:
        coins = 3
        count = 3


        Buy cost 3:
        coins = 0
        count = 4


        Cannot buy cost 4.

        Answer:
        4 ice creams


    */


    int maxIceCream(vector<int>& costs, int coins) {


        // Sort costs in increasing order
        sort(costs.begin(), costs.end());



        // Stores number of ice creams bought
        int count = 0;



        // Traverse all ice cream prices
        for(int i = 0; i < costs.size(); i++)
        {


            // If we can afford current ice cream
            if(coins >= costs[i])
            {

                // Buy ice cream
                count++;


                // Reduce remaining coins
                coins -= costs[i];

            }

            else
            {
                // Remaining ice creams are more expensive
                break;
            }

        }



        // Return maximum ice creams bought
        return count;

    }

};


// Time Complexity:
// Sorting takes O(n log n)
// Traversing array takes O(n)
// Total: O(n log n)


// Space Complexity:
// Sorting uses O(log n) stack space
// Extra space: O(1)

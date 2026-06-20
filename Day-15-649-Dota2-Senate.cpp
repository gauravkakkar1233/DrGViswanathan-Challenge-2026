class Solution {
public:

    /*
        Algorithm:

        1. Create two queues:
           - r queue stores indexes of Radiant senators.
           - d queue stores indexes of Dire senators.


        2. Traverse the senate string:
           
           If current senator is 'R':
              - Push its index into r queue.

           Else:
              - Push its index into d queue.


        3. Simulate the voting process:

           While both queues are not empty:

           - Take the front senator from both queues.
           - The senator with smaller index gets the current round.
           
           If Radiant index is smaller:
              - Radiant bans Dire.
              - Radiant gets another chance in next round.
              - Push index + n back into r queue.

           Else:
              - Dire bans Radiant.
              - Dire gets another chance in next round.
              - Push index + n back into d queue.


        Example:

        senate = "RDD"


        Initial:
        R queue = [0]
        D queue = [1,2]


        Round 1:

        R = 0
        D = 1

        R wins because 0 < 1

        Push R again:
        R queue = [3]


        Round 2:

        R = 3
        D = 2

        D wins because 2 < 3


        No R senators left.

        Winner:
        Dire
    */


    string predictPartyVictory(string senate) {


        // Stores Radiant senator positions
        queue<int> r;


        // Stores Dire senator positions
        queue<int> d;



        // Store indexes of both parties
        for(int i = 0; i < senate.size(); i++)
        {

            char ch = senate[i];


            if(ch == 'R')
            {
                r.push(i);
            }
            else
            {
                d.push(i);
            }

        }



        // Continue until one party loses completely
        while(!r.empty() && !d.empty())
        {


            // Size of senate
            int n = senate.size();



            // Get front senators
            int rfront = r.front();
            r.pop();


            int dfront = d.front();
            d.pop();



            // Radiant gets the chance first
            if(rfront < dfront)
            {

                // Radiant bans Dire and comes again
                r.push(rfront + n);

            }
            else
            {

                // Dire bans Radiant and comes again
                d.push(dfront + n);

            }

        }



        // Return winning party
        return r.empty() ? "Dire" : "Radiant";

    }
};


// Time Complexity:
// Each senator gets processed multiple times
// O(n)


// Space Complexity:
// Two queues are used
// O(n)

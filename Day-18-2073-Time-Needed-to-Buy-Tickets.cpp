class Solution {
public:


    /*
        Algorithm:

        1. Create a queue:

           Store each person with:

           - their index
           - remaining number of tickets


           Example:

           tickets = [2,3,2]

           Queue:

           (0,2)
           (1,3)
           (2,2)



        2. Simulate the buying process:

           Every person at the front buys exactly 1 ticket.

           Steps:

           - Remove the front person.
           - Decrease their ticket count by 1.
           - Increase time by 1 second.



        3. Check if this person is the target person k:

           If the target person has bought their last ticket,
           return the current time.



        4. If the person still has tickets left:

           Put them back at the end of the queue.



        Example:

        tickets = [2,3,2]
        k = 2


        Queue:

        (0,2) (1,3) (2,2)


        Person 0 buys:
        time = 1
        queue = (1,3) (2,2) (0,1)


        Person 1 buys:
        time = 2
        queue = (2,2) (0,1) (1,2)


        Person 2 buys:
        time = 3
        queue = (0,1) (1,2) (2,1)


        Person 0 buys:
        time = 4
        leaves


        Person 1 buys:
        time = 5


        Person 2 buys last ticket:
        time = 6


        Answer = 6

    */


    int timeRequiredToBuy(vector<int>& tickets, int k) {


        // Queue stores:
        // {person index, remaining tickets}

        queue<pair<int,int>> q;



        // Add all people into queue

        for(int i = 0; i < tickets.size(); i++)
        {
            q.push({i, tickets[i]});
        }



        // Stores total time taken

        int time = 0;



        // Continue until queue becomes empty

        while(!q.empty())
        {


            // Get person at front

            int index = q.front().first;
            int ticket = q.front().second;



            // Remove from queue

            q.pop();



            // Person buys one ticket

            ticket--;



            // One second passed

            time++;



            // Target person finished buying

            if(index == k && ticket == 0)
            {
                return time;
            }



            // Person still needs tickets

            if(ticket > 0)
            {
                q.push({index, ticket});
            }

        }



        return time;

    }

};



// Time Complexity:
//
// Each ticket is processed once.
// Maximum operations = total tickets.
//
// O(sum(tickets))



// Space Complexity:
//
// Queue stores n people.
//
// O(n)

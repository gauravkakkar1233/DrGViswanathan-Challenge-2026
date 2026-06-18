/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     bool isInteger() const;
 *
 *     int getInteger() const;
 *
 *     const vector<NestedInteger> &getList() const;
 * };
 */


class NestedIterator {

    /*
        Algorithm:

        1. Given a nested list of integers.

        2. Traverse every element of the list recursively.

        3. For every element:

            - If it contains a single integer:
                  Store it in a queue.

            - If it contains another nested list:
                  Recursively flatten that list.

        4. next():
              Return the front element of queue
              and remove it.

        5. hasNext():
              Check whether queue still contains elements.


        Example:

        nestedList = [1,[4,[6]]]


        Traverse:

        1
        Store 1


        [4,[6]]

        4
        Store 4


        [6]

        6
        Store 6


        Queue:
        1 4 6


        Output:
        1 4 6
    */


    queue<int> q;


    // Function to convert nested list into flat list
    void flatten(vector<NestedInteger> &nestedList)
    {

        // Traverse every element
        for(auto &item : nestedList)
        {


            // If current element is integer
            if(item.isInteger())
            {

                // Store integer in queue
                q.push(item.getInteger());

            }


            // If current element is a nested list
            else
            {

                // Get inner list
                vector<NestedInteger> list = item.getList();


                // Recursively flatten
                flatten(list);

            }
        }
    }



public:


    // Constructor
    NestedIterator(vector<NestedInteger> &nestedList) {


        // Flatten complete nested structure
        flatten(nestedList);

    }



    int next() {


        // Get first element
        int front = q.front();


        // Remove used element
        q.pop();


        // Return value
        return front;

    }



    bool hasNext() {


        // Queue has remaining elements
        return !q.empty();

    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 *
 * NestedIterator i(nestedList);
 *
 * while (i.hasNext())
 *      cout << i.next();
 */


// Time Complexity:
// Every integer is visited once
// O(n)


// Space Complexity:
// Queue stores all flattened integers
// Recursion stack for nested lists
// O(n)

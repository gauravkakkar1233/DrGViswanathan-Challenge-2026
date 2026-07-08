class Solution {
public:
    /*
        Algorithm:

        1. Calculate the sum of the first k cards
           from the left side.

        2. Initialize the answer with this sum,
           since initially all selected cards
           are taken from the left.

        3. Gradually replace one card from the
           left with one card from the right.

        4. In every iteration:
           - Remove one card from the left sum.
           - Add one card from the right sum.
           - Calculate the current total score.
           - Update the maximum score.

        5. After checking all possible
           combinations of taking cards
           from the left and right,
           return the maximum score.

        Example:

        cardPoints = [1,2,3,4,5,6,1]
        k = 3

        Initially:
        Left cards = [1,2,3]
        Sum = 6

        Replace cards one by one:

        Left = [1,2], Right = [1]
        Sum = 3 + 1 = 4

        Left = [1], Right = [6,1]
        Sum = 1 + 7 = 8

        Left = [], Right = [5,6,1]
        Sum = 12

        Maximum Score = 12
    */

    int maxScore(vector<int>& cardPoints, int k)
    {
        int n = cardPoints.size();

        int lsum = 0;
        int rsum = 0;

        // Calculate the sum of first k cards
        for (int i = 0; i < k; i++)
        {
            lsum += cardPoints[i];
        }

        int maxsum = lsum;

        // Replace left cards with right cards
        for (int i = k - 1; i >= 0; i--)
        {
            lsum -= cardPoints[i];
            rsum += cardPoints[n - k + i];

            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};

/*
Time Complexity:

O(k)

- Calculating the initial left sum takes O(k).
- The second loop also runs k times.

Overall:
O(k)

Space Complexity:

O(1)

Only a few integer variables are used.

Overall:
O(1)
*/

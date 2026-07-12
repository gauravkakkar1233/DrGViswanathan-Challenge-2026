class Solution {
public:
    /*
        Algorithm:

        arrayRankTransform(arr)

        1. Create a copy of the given array.

        2. Sort the copied array.

        3. Create a hash map to store
           the rank of each unique element.

        4. Traverse the sorted array:
           - If the current element has
             not been assigned a rank,
             assign the current rank.
           - Increase the rank only when
             a new unique element is found.

        5. Traverse the original array:
           - Replace each element with
             its corresponding rank
             from the hash map.

        6. Return the transformed array.

        Example:

        arr = [40, 10, 20, 30, 20]

        Copy after sorting:
        [10, 20, 20, 30, 40]

        Assigned Ranks:
        10 -> 1
        20 -> 2
        30 -> 3
        40 -> 4

        Result:
        [4, 1, 2, 3, 2]
    */

    vector<int> arrayRankTransform(vector<int>& arr)
    {
        // Create a copy of the original array
        vector<int> copy = arr;

        // Sort the copied array
        sort(copy.begin(), copy.end());

        // Map to store rank of each unique element
        unordered_map<int, int> rank;

        int currRank = 1;

        // Assign ranks to unique elements
        for (int num : copy)
        {
            if (rank.find(num) == rank.end())
            {
                rank[num] = currRank;
                currRank++;
            }
        }

        vector<int> ans;

        // Replace each element with its rank
        for (int num : arr)
        {
            ans.push_back(rank[num]);
        }

        return ans;
    }
};

/*
Time Complexity:

Let:
n = size of the array

Copying the array:
O(n)

Sorting the copied array:
O(n log n)

Assigning ranks:
O(n)

Building the answer array:
O(n)

Overall:
O(n log n)

Space Complexity:

Copy array:
O(n)

Hash map:
O(n)

Answer array:
O(n)

Overall:
O(n)
*/

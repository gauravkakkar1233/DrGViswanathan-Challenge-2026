class Solution {
public:


    /*
        Algorithm:


        1. Generate all possible subsets:

           Use recursion / backtracking approach.



           For every element we have two choices:


           Choice 1:
           
           Include the current element in subset


           Choice 2:

           Exclude the current element from subset




        2. Recursive function:


           findsubset(index, nums, currentSubset, answer)



           Base Condition:


           When index reaches the size of array,


           store the current subset into answer.




        3. Include case:


           Add current element:


           ds.push_back(nums[index])


           Move to next index.



        4. Exclude case:


           Remove the added element:


           ds.pop_back()


           Move to next index.



        5. Return all generated subsets.





        Example:


        nums = [1,2,3]



        Recursion tree:



                         []
                       /    \
                    [1]      []
                   /  \      / \
                [1,2] [1]  [2] []



        Continuing:



        Subsets are:


        []

        [1]

        [2]

        [3]

        [1,2]

        [1,3]

        [2,3]

        [1,2,3]




        Answer size:


        2^n subsets are generated.

    */







    void findsubset(
        int i,
        vector<int> &arr,
        vector<int> &ds,
        vector<vector<int>> &ans
    )
    {


        // Base case:
        // Reached end of array

        if(i >= arr.size())
        {

            // Store current subset

            ans.push_back(ds);

            return;
        }






        // Include current element

        ds.push_back(arr[i]);



        // Move to next element

        findsubset(i+1, arr, ds, ans);






        // Backtrack:
        // Remove current element

        ds.pop_back();






        // Exclude current element

        findsubset(i+1, arr, ds, ans);

    }







    vector<vector<int>> subsets(vector<int>& nums) {


        // Stores all subsets

        vector<vector<int>> ans;



        // Stores current subset

        vector<int> ds;





        // Start recursion from index 0

        findsubset(0, nums, ds, ans);





        // Return all subsets

        return ans;
    }
};




// Time Complexity:
//
// O(n * 2^n)
//
// There are 2^n possible subsets
// and copying each subset takes O(n).




// Space Complexity:
//
// O(n)
//
// Recursion depth is n
// and temporary subset uses O(n).

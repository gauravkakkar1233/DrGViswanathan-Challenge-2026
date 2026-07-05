class Solution {
public:
    /*
        Algorithm:

        1. Let n be the size of the array.

        2. Handle edge cases:
           - If the array contains only one element,
             it is the peak element.
           - If the first element is greater than the
             second element, return index 0.
           - If the last element is greater than the
             second last element, return index n - 1.

        3. Perform Binary Search on the remaining
           portion of the array:
           low = 1
           high = n - 2

        4. Find the middle index:
           mid = low + (high - low) / 2

        5. Check if arr[mid] is greater than both
           its adjacent elements.
           If yes, it is a peak element.
           Return mid.

        6. Otherwise:
           - If the right neighbor is greater than
             the current element, a peak must exist
             on the right side.
             Move:
             low = mid + 1

           - Otherwise, a peak lies on the left side.
             Move:
             high = mid - 1

        7. Continue until the peak element is found.

        Example:

        arr = [1, 2, 3, 1]

        Initial:
        low = 1
        high = 2

        mid = 1
        arr[mid] = 2

        Since arr[mid + 1] > arr[mid],
        move right.

        low = 2

        mid = 2
        arr[mid] = 3

        3 > 2 and 3 > 1

        Peak found at index 2.

        Answer:
        2
    */

    int findPeakElement(vector<int>& arr)
    {
        int n = arr.size();

        // If only one element exists, it is the peak
        if (n == 1)
        {
            return 0;
        }

        // Check if the first element is the peak
        if (arr[0] > arr[1])
        {
            return 0;
        }

        // Check if the last element is the peak
        if (arr[n - 1] > arr[n - 2])
        {
            return n - 1;
        }

        // Binary Search on the remaining elements
        int low = 1;
        int high = n - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Peak element found
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            // Peak lies on the right side
            else if (arr[mid + 1] > arr[mid])
            {
                low = mid + 1;
            }
            // Peak lies on the left side
            else
            {
                high = mid - 1;
            }
        }

        // This statement will never be reached for valid input
        return -1;
    }
};

/*
Time Complexity:

O(log n)

Binary Search halves the search space
in every iteration.

Overall:
O(log n)

Space Complexity:

O(1)

Only a constant number of variables
are used regardless of the input size.

Overall:
O(1)
*/

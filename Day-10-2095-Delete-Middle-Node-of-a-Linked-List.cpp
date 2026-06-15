/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    /*
        Algorithm:

        1. Handle edge cases:
           - If list is empty
           - If list has only one node
           return NULL.

        2. Use two pointers:
           
           slow -> moves one step
           fast -> moves two steps

        3. Start fast from head->next->next
           so that slow stops at the node
           before the middle node.

        4. When fast reaches the end:
              slow will be previous node of middle.

        5. Delete middle node:
              slow->next = slow->next->next

        Example:

        1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6

        slow stops at 4

        Delete 7

        Result:

        1 -> 3 -> 4 -> 1 -> 2 -> 6
    */


    ListNode* deleteMiddle(ListNode* head) {


        // If only one node exists
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }


        // Slow pointer
        ListNode* slow = head;


        // Fast pointer
        ListNode* fast = head->next->next;



        // Find previous node of middle
        while(fast != NULL && fast->next != NULL)
        {

            slow = slow->next;

            fast = fast->next->next;
        }



        // Node to delete
        ListNode* delnode = slow->next;



        // Remove middle node
        slow->next = slow->next->next;



        // Free memory
        delete delnode;



        return head;
    }
};


// Time Complexity:
// Traversing linked list once
// O(n)


// Space Complexity:
// Only pointers used
// O(1)

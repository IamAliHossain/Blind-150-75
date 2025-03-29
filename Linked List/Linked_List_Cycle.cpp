/*
    Problem Link: https://leetcode.com/problems/linked-list-cycle/
    Problem Name: Linked List Cycle
    Problem Diff: Easy

*/
 /* solution using Floyd's Cycle Finding Algorithm 
    Follow the steps below to solve the problem:

    1. Traverse linked list using two pointers.
    2. Move one pointer(slow) by one step ahead and another pointer(fast) by two steps ahead.
    3. If these pointers meet at the same node then there is a loop. 
        If pointers do not meet then the linked list doesn’t have a loop.
 */
class Solution {
    public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow_pointer = head;
        ListNode* fast_pointer = head;
        
        while(1){
            if(slow_pointer->next == NULL){
                return false;
            }
            if(slow_pointer == fast_pointer){
                return true;
            }
            
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next->next;
        }
        return false;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// idea: discard some nodes of the longer list,
// then we can use two scanners to scan remaining lists
// at same step size
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // special case: intersection is the head
        if (headA == headB) {
            return headA;
        }
     
        // get the length of list A
        int length_A = 0;
        ListNode* scanner_A = headA;
        ListNode* tail_A = NULL;
        while (scanner_A != NULL) {
            ++length_A;
            tail_A = scanner_A;
            scanner_A = scanner_A->next;
        }
     
        // special case: A is empty, and B is not empty
        if ((length_A == 0) && (headB != NULL)) {
            return NULL;
        }
     
        // get the length of list B
        int length_B = 0;
        ListNode* scanner_B = headB;
        ListNode* tail_B = NULL;
        while (scanner_B != NULL) {
            ++length_B;
            tail_B = scanner_B;
            scanner_B = scanner_B->next;
        }
     
        // special case: B is empty, and A is not empty
        if ((length_B == 0) && (headA != NULL)) {
            return NULL;
        }
     
        // special case: A and B are of the same length, 
        //               but with different tails,
        //               so no intersection
        if ((length_A == length_B) && (tail_A != tail_B)) {
            return NULL;
        }
     
     
        // common cases:
     
        int move_steps = length_A - length_B;
        int move_counter = 0;
        scanner_A = headA;
        scanner_B = headB;
        if (move_steps > 0) { // list A is longer, discard part of it
            while (move_counter < move_steps) {
                scanner_A = scanner_A->next;
                ++move_counter;
            }
        }
        else if (move_steps < 0) { // list B is longer, discard part of it
            move_steps = -move_steps;
            while (move_counter < move_steps) {
                scanner_B = scanner_B->next;
                ++move_counter;
            }
        }
       
        // now we can move scanner_A and scanner_B at the same speed
        while (scanner_A != NULL) {
            if (scanner_A == scanner_B) {
                return scanner_A;
            }
            scanner_A = scanner_A->next;
            scanner_B = scanner_B->next;
        }
     
        return NULL;
    }
};
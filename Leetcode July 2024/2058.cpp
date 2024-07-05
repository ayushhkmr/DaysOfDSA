// A critical point in a linked list is defined as either a local maxima or a local minima.
// A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
// A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] 
// where minDistance is the minimum distance between any two distinct critical points and maxDistance 
// is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

Example 1:
Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].

x-----------------------------------------------x--------------x-----------------------------------------------------------------------x

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res(2, -1);
        int prev_critical_ind = -1, first_critical_ind = -1;
        ListNode* prev = head;
        ListNode* cur = head->next;
        int cur_ind = 1;

        while (cur->next != nullptr) {
            if ((cur->val > prev->val && cur->val > cur->next->val) ||
                (cur->val < prev->val && cur->val < cur->next->val)) {
                if (prev_critical_ind != -1) {
                    res[0] = (res[0] == -1) ? cur_ind - prev_critical_ind : min(res[0], cur_ind - prev_critical_ind);
                } else {
                    first_critical_ind = cur_ind;
                }
                prev_critical_ind = cur_ind;
            }
            prev = cur;
            cur = cur->next;
            cur_ind++;
        }

        if (prev_critical_ind != -1 && prev_critical_ind != first_critical_ind) {
            res[1] = prev_critical_ind - first_critical_ind;
        }

        return res;
    }
};

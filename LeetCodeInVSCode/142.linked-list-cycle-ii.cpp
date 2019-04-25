/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (31.62%)
 * Total Accepted:    207.8K
 * Total Submissions: 656.5K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects
 * to. If pos is -1, then there is no cycle in the linked list.
 * 
 * Note: Do not modify the linked list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 * 
 * 
 * 
 * 
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//题解：https://blog.csdn.net/sinat_35261315/article/details/79205157 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        //尝试第一次相遇，如果相遇则有环 
        while(true){
            if(slow == nullptr || fast == nullptr){
                return nullptr;
            }
            slow = slow->next;
            if(slow == nullptr){
                return nullptr;
            }
            fast = fast->next;
            if(fast == nullptr){
                return nullptr;
            }
            fast = fast->next;
            if(fast == nullptr){
                return nullptr;
            }
            if(fast == slow){
                break;
            }
        }

        //一个从head开始，一个从相遇点开始，如果相遇了，则相遇点则是入口
        ListNode* start = head;
        while(slow != start){
            slow = slow->next;
            start = start->next;
        }

        return start;

    }
};


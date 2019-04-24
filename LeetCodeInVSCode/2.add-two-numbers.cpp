/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.93%)
 * Total Accepted:    833.7K
 * Total Submissions: 2.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        ListNode* cur_l1 = l1;
        ListNode* cur_l2 = l2;
        int up = false;

        while(cur_l1 != nullptr || cur_l2 != nullptr){
            int x = cur_l1 != nullptr ? cur_l1->val : 0;
            int y = cur_l2 != nullptr ? cur_l2->val : 0;
            int sum = x + y;
            if(up){
                sum ++;
            }
            //注意是大于等于10而不是大于10
            up = sum >= 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if(cur_l1 != nullptr){
                cur_l1 = cur_l1->next;
            }
            if(cur_l2 != nullptr){
                cur_l2 = cur_l2->next;
            }
        }
        //如果遍历完之后还大于10则进位
        if(up){
            cur->next = new ListNode(1);
        }
        return head->next;
    }
};


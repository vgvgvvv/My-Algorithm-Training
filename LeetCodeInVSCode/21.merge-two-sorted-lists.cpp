/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (46.68%)
 * Total Accepted:    556.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* resultHead = new ListNode(0);
        ListNode* current = resultHead;
        ListNode* l1head = l1;
        ListNode* l2head = l2;
        while(l1head != nullptr || l2head != nullptr){
            //l2不为空，或者就是两者都不为空，进行比较
            if(l2head == nullptr || (l1head != nullptr && l1head->val < l2head->val)){
                current->next = new ListNode(l1head->val);
                current = current->next;
                l1head = l1head->next;
            }else{
                current->next = new ListNode(l2head->val);
                current = current->next;
                l2head = l2head->next;
            }
        }
        return resultHead->next;
    }
};


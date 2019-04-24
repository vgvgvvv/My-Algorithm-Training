/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.15%)
 * Total Accepted:    379.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
//利用快慢指针
//需要考虑的特殊情况有，只有一个节点的时候
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //注意这里最好使用一个dummy来链接head，防止第一个节点就被删除了
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* before = dummy;
        ListNode* after = dummy;
        
        //后面的指针先行
        for(int i = 0; i < n; i ++){
            after = after->next;
        }

        //注意只有一个元素的情况
        while(after->next != nullptr){
            after = after->next;
            before = before->next;
        }

        //进行赋值
        ListNode* temp = before->next->next;
        before->next = temp;

        return dummy->next;

    }
};


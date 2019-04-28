/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.70%)
 * Total Accepted:    388K
 * Total Submissions: 953.1K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
#include<vector>

using namespace std;

class Solution {
public:

    //就是简单的二分查找
    int bs(vector<int>& nums, int target, int head, int tail){
        //如果未找到，那么这里就是最合适的位置
        if(head > tail){
            return head;
        }
        int mid = (head + tail) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            return bs(nums, target, head, mid-1);
        }else{
            return bs(nums, target, mid+1, tail);
        }
    }
    
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return 0;
        }
        return bs(nums, target, 0, nums.size()-1);
    }
};


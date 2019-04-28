/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (33.34%)
 * Total Accepted:    289.8K
 * Total Submissions: 868.3K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
#include<vector>

using namespace std;

class Solution {
public:

    //二分查找
    void bs(vector<int>& nums, vector<int>& result, int target, int head, int tail){
        if(head > tail){
            return;
        }
        int mid = (head + tail) / 2;
        //找到目标，更新开始以及结束位置
        if(target == nums[mid]){
            if(result[0] == -1 || result[0] > mid){
                result[0] = mid;
            }
            if(result[1] == -1 || result[1] < mid){
                result[1] = mid;
            }
            //两边搜索
            bs(nums, result, target, mid+1, tail);
            bs(nums, result, target, head, mid-1);
        }
        //未找到，缩小搜索范围
        else if(target > nums[mid]){
            bs(nums, result, target, mid+1, tail);
        }
        //未找到，缩小搜索范围
        else{
            bs(nums, result, target, head, mid-1);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        bs(nums, res, target, 0, nums.size()-1);
        return res;
    }
};


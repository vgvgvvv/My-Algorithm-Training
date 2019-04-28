/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.80%)
 * Total Accepted:    399.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
#include<vector>

using namespace std;

class Solution {
public:

    //二分查找
    int bs(vector<int>& nums, int target, int head, int tail){
        if(head > tail){
            return -1;
        }
        int mid = (head + tail) / 2;
        if(target == nums[mid]){
            return mid;
        }else if(target > nums[mid]){
            return bs(nums, target, mid+1, tail);
        }else{
            return bs(nums, target, head, mid-1);
        }
    }

    //二分，分情况进行处理
    int search(vector<int>& nums, int target, int head, int tail){
        if(head > tail){
            return -1;
        }
        //还是无序的
        if(nums[head] > nums[tail]){
            int mid = (head+tail) / 2;
            if(nums[mid] == target){
                return mid;
            }
            //进行二分
            int res1 = search(nums, target, head, mid-1);
            if(res1 != -1){
                return res1;
            }
            //进行二分
            int res2 = search(nums, target, mid+1, tail);
            if(res2 != -1){
                return res2;
            }
            return -1;
        }
        //有序的
        else{
            //如果尾巴小于结果或者头大于结果则无结果
            if(target > nums[tail] || target < nums[head]){
                return -1;
            }else{
                //进行二分查找
                return bs(nums, target, head, tail);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        return search(nums, target, 0, nums.size()-1);
    }
};


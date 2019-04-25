/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (54.59%)
 * Total Accepted:    246.3K
 * Total Submissions: 451.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */
#include<vector>

using namespace std;

//双向遍历
//实际可以看做每一个数是将左边的数字乘了一遍，第二次是把所有数字的右边的数字乘了一遍，最后再乘在一起
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        int temp = 1;
        for(int i = 0; i < len; i ++){
            res[i] = temp;
            temp *= nums[i];
        }

        temp = 1;
        for(int i = len-1; i >= 0; i --){
            res[i] *= temp;
            temp *= nums[i];
        }
        return res;
    }
};


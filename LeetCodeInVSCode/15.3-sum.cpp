/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.79%)
 * Total Accepted:    527.7K
 * Total Submissions: 2.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int> > result;
        //总量小于3个则肯定不会有三元组
        if(len < 3){
            return result;
        }
        //进行排序
        sort(nums.begin(), nums.end());

        //如果全部大于0或者全部小于0则肯定不会有结果
        if(nums[0] > 0 || nums[len-1] < 0){
            return result;
        }

        //从头到尾
        for(int i = 0; i < len-2; i ++){
            //避免重复数字
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            //左与右压缩,可以看做双指针问题
            int head = i+1;
            int tail = len-1;
            //注意这里判定不是0，要考虑都是0的情况
            while(head < tail && nums[i] < 1){
                int sum = nums[i] + nums[head] + nums[tail];
                if(sum == 0){
                    vector<int> succ;
                    succ.push_back(nums[i]);
                    succ.push_back(nums[head]);
                    succ.push_back(nums[tail]);
                    result.push_back(succ);
                    head++;
                    tail--;
                    //避免重复数字
                    while(head < tail && nums[head] == nums[head-1]){
                        head++;
                    }
                    //避免重复数字
                    while(head < tail && nums[tail] == nums[tail+1]){
                        tail--;
                    }
                }
                //和小于0则尝试增大
                else if(sum < 0){
                    head++;
                }
                //和大于0则尝试减小
                else{
                    tail--;
                }
            }
        }
        return result;
    }
};


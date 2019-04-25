/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (44.22%)
 * Total Accepted:    328.1K
 * Total Submissions: 738.5K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

#include<vector>

using namespace std;
//采用双指针进行解题
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        //最佳结果
        int best = INT32_MAX;
        //最小差异
        int closest = INT32_MAX;
        
        //总量小于3个则肯定不会有三元组
        if(len < 3){
            int sum = 0;
            for(int i = 0; i < len; i ++){
                sum += nums[i];
            }
            return sum;
        }
        //进行排序
        sort(nums.begin(), nums.end());

        for(int i = 0; i < len-2; i ++){
            //防止重复的数字
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }

            //左与右压缩,可以看做双指针问题
            int head = i+1;
            int tail = len-1;
            //最小差
            while(head < tail){
                //算和
                int result = nums[i] + nums[head] + nums[tail];
                int temp = abs(target - result);
                //完全相同
                if(temp == 0){
                    return target;
                }
                //差别更小了,更新best
                if(temp < closest){
                    closest = temp;
                    best = result;
                }
                //和比目标小，需要加更多，提高head
                if(result < target){
                    head++;
                    while(head < tail && nums[head] == nums[head-1]){
                        head++;
                    }
                }
                //和比目标小，需要加更少，减少tail
                else{
                    tail--;
                    while(head < tail && nums[tail] == nums[tail+1]){
                        tail--;
                    }
                }
            }
        }
        return best;
    }
};


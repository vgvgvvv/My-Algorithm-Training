/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (30.20%)
 * Total Accepted:    226.3K
 * Total Submissions: 748.5K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {

        vector<vector<int> > res;

        int len = nums.size();
        if(len < 4){
            return res;
        }

        sort(nums.begin(), nums.end());
        //固定一个数字
        for(int i = 0; i < len-2; i ++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            //固定两个数字
            for(int j = i+1; j < len-2; j++){
                if(j > i+1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int ijsum = nums[i] + nums[j];
                int head = j+1;
                int tail = len-1;
                //和三数之和一样
                while(head < tail){
                    int sum = ijsum + nums[head] + nums[tail];
                    if(sum == target){
                        res.push_back({nums[i], nums[j], nums[head], nums[tail]});
                        while(head < tail && nums[head] == nums[head+1]){
                            head++;
                        }
                        while(head < tail && nums[tail] == nums[tail-1]){
                            tail--;
                        }
                        head++;
                        tail--;
                    }else if(sum < target){
                        head ++;
                    }else{
                        tail --;
                    }
                }
            }
        }

        return res;
    }
};


/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (47.82%)
 * Total Accepted:    329.5K
 * Total Submissions: 688K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */

#include<vector>

using namespace std;

class Solution {
public:
    
    //回溯算法的应用
    
    vector<vector<int> > ans;
    vector<int> tmp;

    void dfs(vector<int>& candidates, int target, int start, int end){
        //边界判断
        if(target < 0 || start > end){
            return;
        }
        //目标值为0则找到解
        if(target == 0){
            ans.push_back(tmp);
        }
        else{
            for(int i = start; i <= end; i ++){
                tmp.push_back(candidates[i]);
                //减完一个之后继续寻找
                dfs(candidates, target - candidates[i], i, end);
                //回溯
                tmp.pop_back();
            }
        }
    }

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0, candidates.size()-1);
        return ans; 
    }
};


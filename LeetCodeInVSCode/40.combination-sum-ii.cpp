/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (41.06%)
 * Total Accepted:    214.3K
 * Total Submissions: 521.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    //回溯算法的应用
    //set进行去重
    set<vector<int> > ans;
    vector<int> tmp;

    void dfs(vector<int>& candidates, int target, int start, int end){
        //边界判断
        if(target < 0){
            return;
        }
        //目标值为0则找到解
        if(target == 0){
            ans.insert(tmp);
        }
        else{
            for(int i = start; i <= end; i ++){
                tmp.push_back(candidates[i]);
                //减完一个之后继续寻找，因为不能复用，所以需要i+1
                dfs(candidates, target - candidates[i], i+1, end);
                //回溯
                tmp.pop_back();
            }
        }
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, candidates.size()-1);
        return vector<vector<int>>(ans.begin(), ans.end()); 
    }
};


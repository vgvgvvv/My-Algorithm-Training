/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (54.53%)
 * Total Accepted:    365.1K
 * Total Submissions: 669.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

#include<vector>

using namespace std;

class Solution {
public:
    //分治递归
    vector<vector<int> > permute(vector<int>& nums, vector<int>& visit, int start, vector<int>& before){
        //TODO
    }

    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> start;
        permute(nums, 0, start);
    }

    
};


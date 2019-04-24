/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (43.90%)
 * Total Accepted:    386.2K
 * Total Submissions: 879.2K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */

#include<map>
using namespace std;

class Solution {
public:

    map<int, int> cache;
    //从规律上可以发现，其实从3开始全部都是前两次函数返回值相加。
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        
        int tmp1 = cache.find(n-1) != cache.end() ? cache[n-1] : climbStairs(n-1);
        int tmp2 = cache.find(n-2) != cache.end() ? cache[n-2] : climbStairs(n-2);
        int result = tmp1 + tmp2;
        //进行缓存
        cache.insert(pair<int, int>(n, result));
        
        return result;
    }
};


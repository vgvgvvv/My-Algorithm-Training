/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include<vector>

using namespace std;

/**
 * 第一种解 时间过长 内存消耗过大
 * class Solution {
 * public:
 *      map<pair<int, int>, int> cache;
 * 
 *     int uniquePaths(int m, int n) {
 * 
 *         if(m == 1){
 *             return 1;
 *         }
 *         if(n == 1){
 *             return 1;
 *         }
 *         pair<int, int> current(m, n);
 *         if(cache.find(current) != cache.end()){
 *             return cache.at(current);
 *         }
 *         int result = uniquePaths(m-1,n) + uniquePaths(m, n-1);
 *         cache.insert(pair<pair<int, int>, int>(current, result));
 *         return result;
 *     }
 * };
 */

class Solution {
public:
    //采用动态规划，将问题逐步逼近为小问题
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};


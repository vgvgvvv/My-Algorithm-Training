/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include<vector>
using namespace std;

class Solution {
public:
    //要获得最大收益，则首先找到最小价格，以及相减获得的最大收益即可
    int maxProfit(vector<int>& prices) {
        int minprice = INT32_MAX;
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i ++){
            if(prices[i] < minprice){
                //更新目前可以使用的最小价格，保证最小价格不会被前面的高峰使用
                minprice = prices[i];
            }else if(maxprofit < prices[i] - minprice){
                //如果找到更大的收益
                maxprofit = prices[i] - minprice;
            }
        }
        return maxprofit;
    }

    //扩展：实际上这个题目可以使用动态规划来做
    //动态规划 前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
};


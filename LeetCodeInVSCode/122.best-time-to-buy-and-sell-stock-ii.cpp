/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int profit = 0;
        int current = prices[0];
        for(int i = 1; i < prices.size(); i ++){
            //一旦上涨就加，没有就不加
            if(current < prices[i]){
                profit += prices[i] - current;
            }
            current = prices[i];
        }
        return profit;
    }
};


/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (54.28%)
 * Total Accepted:    324.9K
 * Total Submissions: 598.4K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]  
 * 
 */
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    
    void findString(vector<string>& result, string str, int open, int close, int n){
        //如果字符已经用完则返回
        if(str.size() == n * 2){
            result.push_back(str);
            return;
        }

        //如果还没用完左括号则尝试添加左括号
        if(open < n){
            findString(result, str + "(", open+1, close, n);
        }
        //如果左括号的数量大于右括号的数量则尝试添加右括号
        if(open > close){
            findString(result, str + ")", open, close+1, n);
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        findString(result, "", 0, 0, n);
        return result;
    }

};


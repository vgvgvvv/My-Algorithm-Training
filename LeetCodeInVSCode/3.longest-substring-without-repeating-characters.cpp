/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.22%)
 * Total Accepted:    886.4K
 * Total Submissions: 3.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 */
#include<map>
#include<string>
#include<iostream>

using namespace std;

//该题可以使用滑动窗口进行解决
//其中重复字符可以直接跳过
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> posMap;
        int len = s.size();
        int result = 0;
        for(int i = 0,j = 0; j < len; j ++){
            //如果发现位置中字符串中已经有了该字符，则将i跳转到不存在该字符串的位置
            if(posMap.find(s[j]) != posMap.end()){
                int next = posMap.at(s[j]) + 1;
                //需要注意的是i不能后退，所以需要判断，否则会出现后退的问题
                i = next > i ? next : i;
            }
            posMap[s[j]] = j;
            //边界判断需要+1
            int max = j-i+1;
            //cout << j << " " << i  << " " << max << endl;
            result = result < max ? max : result;
        }
        return result;
    }
};


/*
 * @lc app=leetcode id=14 lang=csharp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.25%)
 * Total Accepted:    440.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
public class Solution {
    //目前采用的是暴力遍历直到出现不一样的的情况
    public string LongestCommonPrefix(string[] strs) {
        if(strs.Length == 0){
            return string.Empty;
        }
        if(strs.Length == 1){
            return strs[0];
        }
        int lastIndex = 0;
        char currentChar = char.MinValue;
        while(true){
            for(int i = 0; i < strs.Length; i ++){
                string currentStr = strs[i];
                if(currentStr.Length <= lastIndex){
                    return currentStr;
                }
                if(i == 0){
                    currentChar = strs[0][lastIndex];
                    continue;
                }
                if(string.IsNullOrEmpty(currentStr)){
                    return string.Empty;
                }
                if(currentStr[lastIndex] != currentChar){
                    if(lastIndex == 0){
                        return string.Empty;
                    }
                    return currentStr.Substring(0, lastIndex);
                }
            }
            lastIndex++;
        }
        
    }
}


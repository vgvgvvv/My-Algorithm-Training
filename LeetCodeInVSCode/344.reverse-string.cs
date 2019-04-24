/*
 * @lc app=leetcode id=344 lang=csharp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (63.06%)
 * Total Accepted:    403.2K
 * Total Submissions: 639.5K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters char[].
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * You may assume all the characters consist of printable ascii
 * characters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * 
 * 
 */
public class Solution {
    //最简单的翻转字符串
    public void ReverseString(char[] s) {
        int h = 0;
        int t = s.Length-1;
        while(h < t){
            char temp = s[h];
            s[h] = s[t];
            s[t] = temp;
            h++;
            t--;
        }
    }
}


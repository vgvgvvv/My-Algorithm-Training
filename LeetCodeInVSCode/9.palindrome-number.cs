/*
 * @lc app=leetcode id=9 lang=csharp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (42.70%)
 * Total Accepted:    550K
 * Total Submissions: 1.3M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
public class Solution {
    public bool IsPalindrome(int x) {
        if(x < 0){
            return false;
        }
        return x == Reverse(x);
    }
    private int Reverse(int x) {
        int ret = 0;
        while(x != 0){
            int temp = ret * 10 + x % 10;
            //判断是否溢出
            if(temp / 10 != ret){
                return 0;
            }
            ret = temp;
            x /= 10;
        }
        return ret;
    }
}


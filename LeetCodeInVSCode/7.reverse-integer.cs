/*
 * @lc app=leetcode id=7 lang=csharp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.24%)
 * Total Accepted:    656.6K
 * Total Submissions: 2.6M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
public class Solution {
    //这一题最大的问题就在于溢出如何判断，
    //在这里是通过比较除以10以后的结果进行判断的
    public int Reverse(int x) {
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


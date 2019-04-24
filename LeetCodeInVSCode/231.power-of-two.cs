/*
 * @lc app=leetcode id=231 lang=csharp
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (41.79%)
 * Total Accepted:    220.6K
 * Total Submissions: 527.9K
 * Testcase Example:  '1'
 *
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: true 
 * Explanation: 2^0 = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 16
 * Output: true
 * Explanation: 2^4 = 16
 * 
 * Example 3:
 * 
 * 
 * Input: 218
 * Output: false
 * 
 */
public class Solution {
    public bool IsPowerOfTwo(int n) {
        if(n == 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        if(n < 0){
            return false;
        }
        while(n > 1){
            if(n%2 != 0){
                return false;
            }
            n = n/2;
        }
        return true;
    }
}


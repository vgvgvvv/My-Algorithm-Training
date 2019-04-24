/*
 * @lc app=leetcode id=125 lang=csharp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (30.67%)
 * Total Accepted:    339.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
public class Solution {
    public bool IsPalindrome(string s) {
        s = s.ToLower();
        int head = 0;
        int tail = s.Length-1;
        while(head < tail){
            //确保char有效性
            while(head <= tail && !GoodChar(s[head])){
                head ++;
            }
            while(tail > head && !GoodChar(s[tail])){
                tail --;
            }
            //确保char有效性
            if(head >= tail){
                return true;
            }
            //比对
            if(s[head] != s[tail]){
                return false;
            }
            head ++;
            tail --;
        }
        return true;
    }

    private bool GoodChar(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
}


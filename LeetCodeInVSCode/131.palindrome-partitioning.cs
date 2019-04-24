/*
 * @lc app=leetcode id=131 lang=csharp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (40.24%)
 * Total Accepted:    157.9K
 * Total Submissions: 392.5K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
public class Solution {

    List<List<string>> result = new List<List<string>>();
    List<string> temp = new List<string>();

    public IList<IList<string>> Partition(string s) {
        //TODO
    }

    private void Recursion(string s){
        //TODO
    }

    private bool IsGood(string str){
        if(string.IsNullOrEmpty(str)){
            return false;
        }
        int h = 0;
        int t = str.Length-1;
        while(h < t){
            if(str[h] != str[t]){
                return false;
            }
            h++;
            t--;
        }
        return true;
    }
}


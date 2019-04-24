/*
 * @lc app=leetcode id=217 lang=csharp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (51.41%)
 * Total Accepted:    319.7K
 * Total Submissions: 621.9K
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an array of integers, find if the array contains any duplicates.
 * 
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 */
public class Solution {
    //HashSet底层是使用Hash表进行实现的，利用其去重的特性
    //用Hashtable也可以
    public bool ContainsDuplicate(int[] nums) {
        HashSet<int> set = new HashSet<int>(nums);
        return set.Count != nums.Length;
    }
}


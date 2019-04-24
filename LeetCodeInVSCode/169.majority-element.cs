/*
 * @lc app=leetcode id=169 lang=csharp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (52.07%)
 * Total Accepted:    366.9K
 * Total Submissions: 704.3K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
public class Solution {
    //从第一个数开始count=1，遇到相同的就加1，遇到不同的就减1，减到0就重新换个数开始计数，总能找到最多的那个
    public int MajorityElement(int[] nums) {
        int count = 1; 
        int maj = nums[0];
        for (int i = 1; i < nums.Length; i++)
        {
            if (maj == nums[i])
                count++;
            else
            {
                count--;
                if (count == 0)
                {
                    maj = nums[i + 1];
                }
            }
        }
        return maj;
    }
}


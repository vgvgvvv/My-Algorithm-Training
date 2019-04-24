/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (43.81%)
 * Total Accepted:    351K
 * Total Submissions: 801.1K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int head = 0;
        int tail = height.size()-1;

        int headHeight = height.at(head);
        int tailHeight = height.at(tail);
        //注意短板效应，取小的那一个
        int currentHeight = (headHeight > tailHeight ? tailHeight : headHeight);
        int max = currentHeight * (tail - head);

        //cout << tail - head << " " << currentHeight << " " << max << endl;

        while(head < tail){
            //将小的一边往里推，保证不会变小
            if(headHeight > tailHeight){
                tail --;
            }else{
                head ++;
            }
            headHeight = height.at(head);
            tailHeight = height.at(tail);
            //注意短板效应，取小的那一个
            currentHeight = (headHeight > tailHeight ? tailHeight : headHeight);
            int temp = currentHeight * (tail - head);

            max = max > temp ? max : temp;

            //cout << tail - head << " " << currentHeight << " " << temp << endl;

        }

        return max;
    }
};


/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //使用慢指针的方式来确定目前的数组位置
        int newIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[newIndex] = nums[i];
                newIndex++;
            }
        }
        return newIndex;
    }
};



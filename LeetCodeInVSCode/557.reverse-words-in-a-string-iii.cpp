/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (63.62%)
 * Total Accepted:    120.1K
 * Total Submissions: 188.6K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string& s, int head, int tail){
        while(head < tail){
            char temp = s[head];
            s[head] = s[tail];
            s[tail] = temp;
            head ++;
            tail --;
        }
    }

    string reverseWords(string s){
        if(s.size() == 0){
            return s;
        }
        int head = 0;
        int tail = 0;
        while(head < s.size() && tail < s.size()){
            while(s[head] == ' '){
                head++;
                if(head >= s.size()){
                    break;
                }
            }
            tail = head;
            while(s[tail]!= ' ' && tail < s.size()){
                tail++;
            }
            //cout << "head:" << head << endl;
            //cout << "tail:" << tail << endl << endl;
            reverseWords(s, head, tail-1);
            head = tail;
        }
        //cout << s << endl;
        return s;
    }
};


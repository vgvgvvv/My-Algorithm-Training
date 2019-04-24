using System.Collections.Generic;
/*
 * @lc app=leetcode id=20 lang=csharp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.22%)
 * Total Accepted:    558K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
public class Solution {

    //括号匹配：经典的栈使用场景
    public bool IsValid(string s) {
        Stack<char> charStack = new Stack<char>();
        for(int i = 0; i < s.Length; i ++){
            char currentChar = s[i];
            if(IsLeft(currentChar)){
                charStack.Push(currentChar);
            }else if(IsRight(currentChar)){
                if(charStack.Count == 0){
                    return false;
                }
                var last = charStack.Pop();
                if(GetPair(last) != currentChar){
                    return false;
                }
            }
        }
        return charStack.Count == 0;
    }

    private bool IsLeft(char input){
        return input == '(' || input == '{' || input == '[';
    }

    private bool IsRight(char input){
        return input == ')' || input == '}' || input == ']';
    }

    private char GetPair(char input){
        switch(input){
            case'(':
            return ')';
            case'[':
            return ']';
            case'{':
            return '}';
        }
        return char.MinValue;
    }
}


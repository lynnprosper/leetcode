/*
1. 原题
https://leetcode.com/problems/valid-parentheses/

2. 思路
题意：判断一组括号是否有效。

比较简单，直接用栈来判断就可以。
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char x: s)
        {
            switch(x)
            {
                case '(':
                case '{':
                case '[':
                    st.push(x);
                    break;
                case ')':
                    if (st.empty() || '(' != st.top())
                        return false;
                    else
                        st.pop();
                    break;
                case '}':
                    if (st.empty() || '{' != st.top())
                        return false;
                    else
                        st.pop();
                    break;
                case ']':
                    if (st.empty() || '[' != st.top())
                        return false;
                    else
                        st.pop();
                    break;
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};

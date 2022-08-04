/*
递归或者模拟栈来处理
https://leetcode.com/problems/decode-string/
*/

// 法一：递归
class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return dfs(s, pos);
    }
    
    string dfs(string s, int &pos) {
        string ret{""};
        while (pos < s.size() && s[pos] != ']') {
            if (isalpha(s[pos])) {
                ret += s[pos++];
            } else {
                int num = 0;
                while (isdigit(s[pos])) {
                    num = num * 10 + s[pos] - '0';
                    pos++;
                }
                ++pos; // '[' next one;
                string cur = dfs(s, pos);
                ++pos; // ']' next one;
                while (num > 0) {
                    ret.append(cur);
                    --num;
                }
                
            }
        }
        
        return ret;
    }
};

// 法二：栈
class Solution {
public:
    string decodeString(string s) {
        stack<string> staStr;
        stack<int> staNum;
        string res;
        int num = 0;
        vector<int> mv;
        
        for(char alpha : s) {
            if (isdigit(alpha)) {
                num = num *10 + (alpha - '0');
            } else if (alpha == '[') {
                staNum.push(num);
                num = 0;
                staStr.push(res);
                res = "";
            } else if (alpha == ']') {
                string tmp = staStr.top();
                staStr.pop();
                int cnt = staNum.top();
                staNum.pop();
                for (int i = 0; i < cnt; i++) {
                    tmp.append(res);
                }
                // staStr.push(tmp);
                res = tmp;
            } else {
                res.push_back(alpha);
            }
        }
        return res;
    }
};

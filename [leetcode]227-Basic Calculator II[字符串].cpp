/*
先添加一个虚拟的+开始，这样每个数字对应一个运算符，方便处理。
然后遍历，遇到乘除，从数字栈里弹出来运算，再压入。加减法直接入栈即可。
*/

class Solution {
public:
    int calculate(string s) {
        stack<long> num;
        int i = 0;
        char op = '+';
        long nn;
        while(i < s.length())
        {
            if(s[i] != ' ')
            {
                if(s[i] >= '0') {
                long tp = parseNum(s, i);
                switch(op)
                {
                    case '+': 
                        num.push(tp);
                        break;
                    case '-': 
                        num.push(-tp);
                        break;
                    case '*': 
                        nn = num.top()*tp;
                        num.pop();
                        num.push(nn);
                        break;
                    case '/': 
                        nn = num.top()/tp;
                        num.pop();
                        num.push(nn);
                        break;
                }
                
                    }
                else
                    op = s[i++];
            }
            else
             ++i;
        }
        long res = 0;
        while(!num.empty())
        {
            res += num.top();
            num.pop();
        }
        return res;
    }
    
    long parseNum(string &s, int &i)
    {
        long n = 0;
        while(i < s.length() && isdigit(s[i]))
        {
            n = n*10 + s[i]-'0';
            ++i;
        }
        return n;
    }
};

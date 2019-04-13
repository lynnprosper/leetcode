/*
1. 原题
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

2. 思路
题意：给出一个字符串，多个等长的单词，输出匹配时的索引下标。

给出的所有单词任意组合且中间无多余字符即匹配。

注意，字符串长度可能小于单词长度。

思路：题目较难。

由于单词等长，所以只需遍历词长这么多次。

每次遍历时，逐个判断取出的n个字符是否为给定的单词，同时累计单词个数。
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) //边界条件
            return res;
        
        map<string, int> mp1, mp2; //mp1存储已知的映射
        for(string word : words)
            ++mp1[word];
        int cnt = 0, left;
        int len = words[0].size();
        int num = words.size();
        if (s.size() < len) //边界
            return res;
        
        for (int i = 0; i < len; i++) //遍历len次即可
        {
            left = i;
            mp2.clear();
            cnt = 0;
            for (int j = i; j <= s.size()-len; j+=len)
            {
                string str = s.substr(j, len);
                if (mp1.count(str) > 0)
                {
                    ++mp2[str];
                    cnt++;
                    if (mp2[str] > mp1[str]) //单词多了，需要剔除一个
                    {
                        string ss;
                        do //从左开始逐个剔除多余的
                        {
                            ss = s.substr(left, len);
                            left += len;
                            --mp2[ss];
                            cnt--;
                        }
                        while (ss != str);
                    }
                }
                else //遇到不符合的单词，直接重新判断
                {
                    mp2.clear();
                    left = j+len;
                    cnt = 0;
                }
                
                if (cnt == num)
                {
                    res.push_back(left);
                    --mp2[s.substr(left, len)];
                    cnt--;
                    left += len; //向右滑动一个词长
                }
            }
        }
        
        return res;
    }
};

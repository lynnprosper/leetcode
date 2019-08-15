/*
1. 原题
https://leetcode.com/problems/group-anagrams/

2. 思路
题意：给出多个字符串，相同字符构成的字符串分到一块。

算法：每个字符串先排序，排序好的字符串相同就放到一起。

这时，要用到map，来存放索引。
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, int> mp;
        for (auto it : strs)
        {
            string tmp(it);
            sort(tmp.begin(), tmp.end()); //sort the string
            if(mp.count(tmp) < 1)
            {
                mp[tmp] = res.size();
                res.push_back(vector<string>(1, it));
            }
            else
            {
                res[mp[tmp]].push_back(it);
            }
        }
        
        return res;
    }
};

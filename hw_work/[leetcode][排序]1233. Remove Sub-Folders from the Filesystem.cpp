/*
https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
排序方法，按照字典序来查找比较，比较简单
*/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res(1, folder[0]);
        string pre = folder[0] + "/";
        for (int i = 1; i < folder.size(); i++) {
            
        }
        int i = 1;
        while (i < folder.size()) {
            if (folder[i].find(pre) == folder[i].npos ||
                folder[i].find(pre) != 0) { // 该判断是防止不是起始的父目录
                pre = folder[i] + "/";
                res.push_back(folder[i]);
            }
            ++i;
        }
        
        return res;
    }
};

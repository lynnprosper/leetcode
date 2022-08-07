/*
思路：贪心算法
先找出当前最小的人能放的位置，即空的+已存放的比它大的；
然后再找第二小的人能放的位置，遍历即可。
https://leetcode.com/problems/queue-reconstruction-by-height/
*/

bool cmp(vector<int>& a, vector<int>& b){
        if (a[0] == b[0]) {
            return a[1] < b[1];
        } else {
            return a[0] < b[0];
        }
    }
class Solution {
public:
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int flag[2005]{0}; //标志是否存放数据
        vector<vector<int>> res(people.size(), vector<int>(2, 0));
        sort(people.begin(), people.end(), cmp);
        for (auto it : people) {
            int pos = 0;
            for (int i = 0; i < res.size(); i++) {
                if (flag[i] == 0 || res[i][0] >= it[0]) { // 统计大于等于当前的
                    pos++;
                }
                if (pos == it[1]+1) { // 找到了，存放在i这里
                    res[i] = it;
                    flag[i] = 1;
                    break;
                }
            }
        }
        
        return res;
    }
};

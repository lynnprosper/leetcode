/*
扫描线法实现, 从左到右遍历, 如果遇到左节点即放入堆中, 右节点弹出堆中; 
每一次经过一个点, 就会有可能产生高度变化产生一个轮廓点, 而该轮廓点的高度就是堆中的最大值.

额外考虑的是经过相同左端点的不同高度应当优先考虑高度更高的建筑, 
产生了一个轮廓点, 考虑低建筑时则不会产生轮廓点; 经过右端点的不同高度时, 应当优先弹出低建筑再考虑高建筑, 这样低建筑的弹出不会产生额外的轮廓点.

*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int,int>> st;
        vector<vector<int>> res;
        for(auto it:buildings)
        {
            st.insert(make_pair(it[0], -it[2]));
            st.insert(make_pair(it[1], it[2]));
        }
        
        multiset<int> pool({0});
        int last = 0;
        for(auto it: st) //扫描线，扫描每一条, 都有可能有高度变化
        {
            if(it.second < 0)
                pool.insert(-it.second);
            else
                pool.erase(pool.find(it.second)); //不能直接删除值，erase会删除多个相同的元素
            int cur_max = *pool.rbegin();
            if(cur_max != last) //高度有变化
                res.push_back({it.first, cur_max});
            last = cur_max;
        }
        
        return res;
    }
};

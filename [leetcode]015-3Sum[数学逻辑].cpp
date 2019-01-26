/*

1. 原题
https://leetcode.com/problems/3sum/

2. 思路
题意：从一组序列中找出所有的组合，使得三个数之和为0.

思路：这题有点类似两个数之和的扩展。题意暗含三个数是升序，

而且相同的组合只能保留一个。我们知道求两数和为0可以采用快慢指针的算法，复杂度O(N).

那么对于三个数之和，我们可以指定第一个数，让另外两个和为第一个的相反数即可。复杂度O(N^2).

对于不能重复的组合，在快慢指针查找的时候处理即可。*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > re;
        sort(nums.begin(), nums.end()); //题意隐含有序
        int len = nums.size();
        for (int i = 0; i < len-1 && nums[i] <= 0; i)
        {
            int left = i+1, right = len-1; 
            while (left < right) //类似快慢指针
            {
                if (nums[left]+nums[right] > -nums[i])
                    right--;
                else if (nums[left]+nums[right] == -nums[i]) //**这里忽略相同的组合
                {
                    re.push_back({nums[i], nums[left], nums[right]});
                    while (left+1 < right && nums[left] == nums[left+1]) //相同跳过
                        left++;
                    while (left < right-1 && nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                }
                else
                    left++;
            }
            
            while (i < len-1 && nums[i+1] == nums[i]) i++; //相同的数已经处理了，跳过
            i++;
        }
        
        return re;
    }
};

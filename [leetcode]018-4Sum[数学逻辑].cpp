/*

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        set<vector<int> > mset; //利用set的性质去重，也可自己手动去重，多写点代码
        for (int i = 0; i <len-3; i++ )
        {
            int ftar = target-nums[i];
            for (int j = i+1; j < len-2; j++)
            {
                int lt = j+1, rt = len-1;
                int star = ftar-nums[j];
                while (lt < rt)
                {
                    if (nums[lt]+nums[rt] > star)
                        rt--;
                    else if (nums[lt]+nums[rt] < star)
                        lt++;
                    else
                    {
                        mset.insert(vector<int>({nums[i], nums[j], nums[lt], nums[rt]}));
                        lt++;
                        rt--;
                    }
                }
            }
        }
        
        return vector<vector<int>> (mset.begin(), mset.end());
    }
};

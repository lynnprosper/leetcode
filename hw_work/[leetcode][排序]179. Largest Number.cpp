/*
自定义字符串排序，把数字看成字符串，比较拼接后的大小。
https://leetcode.com/problems/largest-number/
*/

bool cmp(string& a, string& b){
	return (a + b) > (b + a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto it : nums) {
            str.push_back(to_string(it));
        }
        sort(str.begin(), str.end(), cmp);
        string res{""};
        for (auto it : str) {
            res.append(it);
        }
        int i;
        for(i = 0; i < res.size(); i++) {
            if (res[i] != '0') {
                break;
            }
        }
        if (i == res.size()) {
            res = "0";
        } else {
            res = res.substr(i);
        }
        return res;
    }
};

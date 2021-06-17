/*
回文字符串就是正读和反读都一样的字符串，如“viv”、“nexen”、“12321”、“qqq”、“翻身把身翻” 等。
给定一个非空字符串 str，在删除一个字符的情况下请编程判定其能否成为回文字符串；如果可以则输出首次删除一个字符所能得到的回文字符串，如果不行则输出字符串 "false" 。

输入描述:
一个非空字符串


输出描述:
一个回文字符串，或者 "false" 字符串（如果无法构造出回文字符串的话）

输入例子1:
abda

输出例子1:
ada
https://www.nowcoder.com/question/next?pid=29582167&qid=1487196&tid=44950252
*/

#include<stdio.h>
#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<unordered_set>
#include<unordered_map>

using namespace std;

int main()
{
    	string input, rstr;
	cin >> input;
	rstr = input;
	reverse(rstr.begin(), rstr.end());
	if (0)
		cout << input;
	else
	{
		for (int i = 0; i < input.length(); i++)
		{
			string str = input;
			str.erase(i, 1);
			rstr = str;
			reverse(rstr.begin(), rstr.end());
			if (str == rstr)
			{
				cout << str;
				return 0;
			}
		}
	}
    cout << "false";
    return 0;
}

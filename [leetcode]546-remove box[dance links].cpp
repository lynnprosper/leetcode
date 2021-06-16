/*
原题是vivo秋招https://www.nowcoder.com/profile/9110297/myFollowings/detail/22939109 
小v在vivo手机的应用商店中下载了一款名为“一维消消乐”的游戏，介绍如下：
1、给出一些不同颜色的豆子，豆子的颜色用数字（0-9）表示，即不同的数字表示不同的颜色；
2、通过不断地按行消除相同颜色且连续的豆子来积分，直到所有的豆子都消掉为止；
3、假如每一轮可以消除相同颜色的连续 k 个豆子（k >= 1），这样一轮之后小v将得到 k*k 个积分；
4、由于仅可按行消除，不可跨行或按列消除，因此谓之“一维消消乐”。
请你帮助小v计算出最终能获得的最大积分。

高效的解法应当是动态规划，但是没那么多时间想，这里使用dancing links的思想，使用一个链表记录数组，然后回溯即可
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/**
 * Welcome to vivo !
 */

#define MAX_NUM 100

struct Node{
    int val;
    Node * prev;
    Node * next;
    Node(int v) : val(v)
    {
        prev = next = nullptr;
    }
};
int search(Node *head);

int solution(int boxs[], int N)
{
        // TODO Write your code here
    Node * head = new Node(0);
    Node *p = head;
    for(int i = 0; i < N; i++)
    {
        Node *nn = new Node(boxs[i]);
        p->next = nn;
        nn->prev = p;
        p = nn;
    }
    

	return search(head);
}

int search(Node *head)
{
    if(head->next == nullptr)
        return 0;
    
    Node *p = head;
    p = head->next;
    int res = 0;
    
    while(p != nullptr)
    {
        int c = 1;
        Node *r = p;
        while(r->next && r->val == r->next->val)
        {
            c++;
            r = r->next;
        }
        
        //remove
        p->prev->next = r->next;
        if(r->next)
            r->next->prev = p->prev;
        int val = c*c + search(head);
        res = max(res, val);
        
        // restore
        p->prev->next = p;
         if(r->next)
            r->next->prev = r;
        p = r->next;
    }
    
    return res;
}

int main()
{
	string str("");
	getline(cin, str);
	int boxs[MAX_NUM];
	int i = 0;
	char *p;
	int count = 0;
	
	const char* strs = str.c_str();
	p = strtok((char *)strs, " ");
	while(p)
	{
		boxs[i] = atoi(p);
		count++;
		p = strtok(NULL, " ");
		i++;
		if(i >= MAX_NUM)
			break;
	}

	int num = solution(boxs, count);
	cout << num << endl;
	return 0;
}

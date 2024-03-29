/*
P1298 最接近的分数
已知某个分数分子的取值范围 n nn ，分母的取值范围 m mm ，和一个 d o u b l e doubledouble 浮点数 x xx ，求出满足条件并且最接近 x xx 的最简分数。

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	double x;
	cin>>n>>m>>x;
	double min3=10000000000000;
	int min1,min2;
	bool g=false;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(__gcd(i,j)!=1)continue;//是否互质
			if(abs(double(j)/double(i)-x)>min3)continue;//超过了目前最佳答案，剪枝1
			else if(abs(double(j)/double(i)-x)<min3){
				g=false;//已更新
				//接下来三行为传新值操作
				min3=abs(double(j)/double(i)-x);
				min1=j;
				min2=i;
			}else if(abs(double(j)/double(i)-x)==min3)g=true;//相等，有多重正解
		}
	}
	if(g)cout<<"TOO MANY"<<endl;//如果有重复
	else cout<<min1<<"/"<<min2;
	return 0;
}


*/


/*
0111101, 这样的字符串，输出连续子串中0的个数减去1的个数最大值

int main()
{
	////find函数返回类型 size_type
	//freopen("in.txt", "r", stdin);
	string s;
	while (cin >> s) {
		int pre = -1;
		int ans = s[0] == '0' ? 1 : -1;
		for (const auto &x : s) {
			int t = 0;
			if (x == '0') {
				t = 1;
			}
			if (x == '1') {
				t = -1;
			}
			pre = max(pre + t, t);
			ans = max(ans, pre);
		}
		cout << ans << endl;
	}
	return 0;

}
*/



/*
5 4
1 2 3 4 5
3 5 7 9 11
两个N长降序序列，分别任取一个数，求前k个最大的。
这些和可以看成n个有序表：
A1+B1 <= A1+B2 <= ... 
A2+B1 <= A2+B2 <= ... 
...
利用归并排序，每次O(logn),共取k次

输出：16 15 14 14
*/

#include <iostream>
#include <queue>
#include<vector>
#include<functional>

using namespace std;
int a[100000 + 5]{0};
int b[100000 + 5]{0};

int main(){
	freopen("in.txt","r",stdin);
	int n, k = 0;
	cin >> n >> k;
	for (int i = n; i> 0; i--){
		cin >> a[i];
	}
	for (int i = n; i> 0; i--){
		cin >> b[i];
	}
	priority_queue<int, vector<int>, greater<int> > q; //小根堆；
	for (int i = 1; i <= n; i++){
		q.push(a[i] + b[1]);
	}
	while (q.size() > k) q.pop();
	int tm = q.top();
	for (int j = 2; j <= n; j++){
		for (int i = 1; i <= n; i++){
			int tmp = a[i] + b[j];
			if (q.size() < k){
				q.push(tmp);
			}
			else{
				if (tmp <= q.top()) break;
				else{
					q.pop();
					q.push(tmp);
				}
			}
		}
	}
	for (int i = 1; i <= k; i++){
		cout << q.top() << ' ';
		q.pop();
	}

	return 0;
}

/*2.
2. 合并三个有序链表，
两个两个的合并

*/
 List merge(List head1, List head2){
 2     List mergeHead = NULL;
 3     if (head1 == NULL) {
 4         return head2;
 5     }
 6     if (head2 == NULL){
 7         return head1;
 8     }
 9 
10     if (head1->item < head2->item){
11         mergeHead = head1;
12         mergeHead->next = merge(head1->next, head2);
13     }else{
14         mergeHead = head2;
15         mergeHead->next = merge(head1, head2->next);
16     }
17     return mergeHead;
18 }

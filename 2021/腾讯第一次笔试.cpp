/*
5 4
1 2 3 4 5
3 5 7 9 11
两个N长降序序列，分别任取一个数，求前k个最大的。

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
